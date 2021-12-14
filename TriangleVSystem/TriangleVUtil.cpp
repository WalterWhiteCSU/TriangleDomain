/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TriangleVUtil.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/15
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "TriangleVUtil.h"

namespace TriangleV {

    ImageQuadTree *TriangleVUtil::TriangleVFitting(ImageQuadTree *imageQuadTree) {
        //  得到总共的数据点
        std::vector<CalculateData *> totalData = imageQuadTree->tree->dataList;
        int totalDataCount = totalData.size();
        //  层次遍历，得到每个节点中的数据
        std::vector<ImageQuadTreeNode *> nodeList = imageQuadTree->levelOrder();

        //  得到三角域V系统矩阵
        Eigen::MatrixXf vMatrix = GetVMatrix(totalData, nodeList, imageQuadTree->layer);

        //  将Y赋值为为每个像素点的灰度值
        Eigen::VectorXf valueVec = Eigen::VectorXf::Zero(totalData.size());
        for (int i = 0; i < totalData.size(); ++i) {
            valueVec(i) = totalData[i]->data->getValue();
        }

        //  通过最小二乘解得拟合系数
        std::cout << "Start solve Equations" << std::endl;
//        Eigen::VectorXf coefficientVec = (vMatrix.transpose() * vMatrix).inverse() * vMatrix.transpose() * valueVec;
        Eigen::VectorXf coefficientVec = vMatrix.colPivHouseholderQr().solve(valueVec);
//        Eigen::VectorXf coefficientVec = vMatrix.householderQr().solve(valueVec);

        std::cout << "Equation solved" << std::endl;

        //  为每个四叉树的节点中的拟合系数赋值
        //  先为祖先节点赋值、为12个
        imageQuadTree->tree->parameterList = GetParameterListForEachNode(coefficientVec, 0, 12);
        //  为接下来的节点赋值
        int coefficientCursor = 12;
        for (int i = 1; i < nodeList.size(); ++i) {
            nodeList[i]->parameterList = GetParameterListForEachNode(coefficientVec, coefficientCursor,
                                                                     coefficientCursor + 9);
            coefficientCursor += 9;
        }

        return imageQuadTree;
    }

    Eigen::MatrixXf TriangleVUtil::GetVMatrix(std::vector<CalculateData *> &totalData,
                                              std::vector<ImageQuadTreeNode *> &nodeList, int totalLayer) {
        //  声明V矩阵
        int row = totalData.size();
        int col = 12 + 9 * (nodeList.size() - 1);
        Eigen::MatrixXf vMatrix = Eigen::MatrixXf::Zero(row, col);

        //  第一组V系统
        std::vector<std::vector<float>> firstVector = FirstV(totalData);
        //  计算第二组V系统
        std::vector<std::vector<float>> basicGenerate = GenerateV(totalData, 1);
        for (int i = 0; i < row; ++i) {
            vMatrix(i, 0) = firstVector[i][0];
            vMatrix(i, 1) = firstVector[i][1];
            vMatrix(i, 2) = firstVector[i][2];

            vMatrix(i, 3) = basicGenerate[i][0];
            vMatrix(i, 4) = basicGenerate[i][1];
            vMatrix(i, 5) = basicGenerate[i][2];

            vMatrix(i, 6) = basicGenerate[i][3];
            vMatrix(i, 7) = basicGenerate[i][4];
            vMatrix(i, 8) = basicGenerate[i][5];

            vMatrix(i, 9) = basicGenerate[i][6];
            vMatrix(i, 10) = basicGenerate[i][7];
            vMatrix(i, 11) = basicGenerate[i][8];
        }

        int currentMatrixColCount = 12;
        for (int i = 1; i < nodeList.size(); ++i) {
            std::cout << i << std::endl;

            //  获得仿射变换后的列表
            std::vector<TriangleDomain::AreaPoint *> affineData = GetAffineData(nodeList[i]);

            int layer = nodeList[i]->layer;

            //  得到当前节点中的所有取值
            auto localGenerate = GenerateV(affineData, pow(2, layer - 1));
//           auto localGenerate = GenerateV(affineData, 1);
            //  为矩阵赋值
            SetMatrixValueByAffineList(vMatrix, localGenerate, totalData, nodeList[i]->triangle,
                                       currentMatrixColCount);
            currentMatrixColCount += 9;

        }
        return vMatrix;
    }

    std::vector<std::vector<float>> TriangleVUtil::FirstV(std::vector<CalculateData *> &data) {
        std::vector<std::vector<float>> res;

        for (int i = 0; i < data.size(); ++i) {
            float u = data[i]->areaPoint->getU();
            float v = data[i]->areaPoint->getV();

            std::vector<float> model;
            model.push_back(sqrt(2.0f));
            model.push_back(6.0f * u - 2.0f);
            model.push_back(2.0f * sqrt(3.0f) * (u + 2 * v - 1));

            res.push_back(model);
        }

        return res;
    }

    std::vector<std::vector<float>>
    TriangleVUtil::GenerateV(std::vector<TriangleDomain::AreaPoint *> &data, int scale) {
        std::vector<std::vector<float>> res;

        for (int i = 0; i < data.size(); ++i) {
            auto model = GetSingleDataGenerateV(data[i], scale);
            res.push_back(model);
        }

        return res;
    }

    std::vector<std::vector<float>> TriangleVUtil::GenerateV(std::vector<CalculateData *> &data, int scale) {
        std::vector<std::vector<float>> res;

        for (int i = 0; i < data.size(); ++i) {
            auto model = GetSingleDataGenerateV(data[i]->areaPoint, scale);
            res.push_back(model);
        }

        return res;
    }

    std::vector<float> TriangleVUtil::GetSingleDataGenerateV(TriangleDomain::AreaPoint *data, int scale) {
        float u = data->getU();
        float v = data->getV();
        float w = data->getW();

        std::vector<float> model;

        //  如果点在第一个三角形中
        if (u > 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 5.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 5.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 5.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (18.0f * u - 12.0f));
            model.push_back(0.0f);
            model.push_back(0.0f);

            model.push_back(scale * (-12.0f * w + 12.0f * v));
            model.push_back(0.0f);
            model.push_back(0.0f);
        }

        //  如果在第二个三角形中
        if (v > 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 1.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * 2.0f * sqrt(6.0f) / 3.0f * (-12.0 * u - 2.0f));
            model.push_back(0.0f);

            model.push_back(scale * (4.0f * w - 4.0f * v + 2.0f));
            model.push_back(scale * -sqrt(8.0f) * (-4.0f * u - 8.0f * v + 6.0f));
            model.push_back(0.0f);
        }

        //  如果在第四个三角形中
        if (w > 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 1.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * 2.0f * sqrt(6.0f) / 3.0f * (-6.0 * u + 1.0f));
            model.push_back(scale * sqrt(8.0f) * (6.0f * u - 1.0f));

            model.push_back(scale * (4.0f * w - 4.0f * v - 2.0f));
            model.push_back(scale * -sqrt(8.0f) * (2.0f * u + 4.0f * v - 1.0f));
            model.push_back(scale * -sqrt(24.0f) * (-2.0f * u - 4.0f * v + 1.0f));
        }

        //  如果在第三个三角形中
        if (u < 0.5f && v < 0.5f && w < 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 1.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 2.0f));
            model.push_back(scale * 2.0f * sqrt(6.0f) / 3.0f * (-6.0 * u + 2.0f));
            model.push_back(scale * sqrt(8.0f) * (-6.0f * u + 2.0f));

            model.push_back(scale * (4.0f * w - 4.0f * v));
            model.push_back(scale * -sqrt(8.0f) * (2.0f * u + 4.0f * v - 2.0f));
            model.push_back(scale * -sqrt(24.0f) * (2.0f * u + 4.0f * v - 2.0f));
        }

        //  在第一和第三个三角形的交界处
        if (u == 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 3.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 3.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 3.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (6.0f * u - 5.0f));
            model.push_back(scale * sqrt(6.0f) / 3.0f * (-6.0f * u + 2.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 2.0f));

            model.push_back(scale * (-4.0f * w + 4.0f * v));
            model.push_back(scale * -sqrt(2.0f) * (2.0f * u + 4.0f * v - 2.0f));
            model.push_back(scale * -sqrt(6.0f) * (2.0f * u + 4.0f * v - 2.0f));
        }

        //  在第二个和第三个三角形的交界处
        if (v == 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 1.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.5f));
            model.push_back(scale * sqrt(24.0f) / 3.0f * (-9.0 * u));
            model.push_back(scale * sqrt(2.0f) * (-6.0 * u + 2.0f));

            model.push_back(scale * (4.0f * w - 4.0f * v + 1.0f));
            model.push_back(scale * -sqrt(2.0f) * (-2.0f * u - 4.0f * v + 4.0f));
            model.push_back(scale * -sqrt(6.0f) * (2.0f * u + 4.0f * v - 2.0f));
        }

        //  在第三个和第四个三角形的交界处
        if (w == 0.5f) {
            model.push_back(scale * sqrt(2.0f) * (-6.0f * u + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * v + 1.0f));
            model.push_back(scale * sqrt(2.0f) * (-6.0f * w + 1.0f));

            model.push_back(scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.5f));
            model.push_back(scale * sqrt(24.0f) / 3.0f * (-6.0 * u + 1.5f));
            model.push_back(scale * sqrt(2.0f));

            model.push_back(scale * (4.0f * w - 4.0f * v - 1.0f));
            model.push_back(scale * -sqrt(2.0f) * (4.0f * u + 8.0f * v - 3.0f));
            model.push_back(scale * sqrt(6.0f));
        }

        return model;
    }

    std::vector<TriangleDomain::AreaPoint *> TriangleVUtil::GetAffineData(ImageQuadTreeNode *node) {
        std::vector<TriangleDomain::AreaPoint *> res;

        Eigen::MatrixXf coordinateMatrix = Eigen::MatrixXf::Ones(3, 3);

        //  面积坐标组装
        float u1 = node->triangleAreaPoint[0]->getU();
        float v1 = node->triangleAreaPoint[0]->getV();
        float w1 = node->triangleAreaPoint[0]->getW();
        coordinateMatrix(0, 0) = u1;
        coordinateMatrix(1, 0) = v1;
        coordinateMatrix(2, 0) = w1;

        float u2 = node->triangleAreaPoint[1]->getU();
        float v2 = node->triangleAreaPoint[1]->getV();
        float w2 = node->triangleAreaPoint[1]->getW();
        coordinateMatrix(0, 1) = u2;
        coordinateMatrix(1, 1) = v2;
        coordinateMatrix(2, 1) = w2;

        float u3 = node->triangleAreaPoint[2]->getU();
        float v3 = node->triangleAreaPoint[2]->getV();
        float w3 = node->triangleAreaPoint[2]->getW();
        coordinateMatrix(0, 2) = u3;
        coordinateMatrix(1, 2) = v3;
        coordinateMatrix(2, 2) = w3;

        //  求得仿射矩阵
        Eigen::MatrixXf affineMatrix = coordinateMatrix.inverse();

        for (auto point:node->dataList) {
            //  先得到数据的面积坐标矩阵
            Eigen::VectorXf pointVec = point->areaPoint->GetVector();
            //  计算得到仿射变换后的坐标
            Eigen::VectorXf affineVec = affineMatrix * pointVec;
            //  转换成AreaPoint *的数据
            TriangleDomain::AreaPoint *model = TriangleDomain::AreaPoint::GetAreaPointByVector(affineVec);

            res.push_back(model);
        }

        return res;
    }

    void TriangleVUtil::SetMatrixValueByAffineList(Eigen::MatrixXf &vMatrix,
                                                   std::vector<std::vector<float>> &paramDataList,
                                                   std::vector<CalculateData *> &totalPointData,
                                                   TriangleDomain::Triangle *triangle, int currentMatrixColCount) {
        int cursor = 0;
        for (int i = 0; i < totalPointData.size(); ++i) {
            if (triangle->isPointInTriangle(totalPointData[i]->data->getPoint()) >= 0) {
                vMatrix(i, currentMatrixColCount) = paramDataList[cursor][0];
                vMatrix(i, currentMatrixColCount + 1) = paramDataList[cursor][1];
                vMatrix(i, currentMatrixColCount + 2) = paramDataList[cursor][2];

                vMatrix(i, currentMatrixColCount + 3) = paramDataList[cursor][3];
                vMatrix(i, currentMatrixColCount + 4) = paramDataList[cursor][4];
                vMatrix(i, currentMatrixColCount + 5) = paramDataList[cursor][5];

                vMatrix(i, currentMatrixColCount + 6) = paramDataList[cursor][6];
                vMatrix(i, currentMatrixColCount + 7) = paramDataList[cursor][7];
                vMatrix(i, currentMatrixColCount + 8) = paramDataList[cursor][8];

                cursor++;
            }
        }
    }

    std::vector<float> TriangleVUtil::GetParameterListForEachNode(Eigen::VectorXf &coefficientVec, int startIndex,
                                                                  int endIndex) {
        std::vector<float> res;

        for (int i = startIndex; i < endIndex; ++i) {
            res.push_back(coefficientVec(i));
        }
        return res;
    }
}
