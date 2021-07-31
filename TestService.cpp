/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TestService.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/22
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "TestService.h"

namespace TriangleV {
    std::vector<ImageQuadTree *> TestService::ImageQuadTreeFittingTest() {
        std::vector<ImageQuadTree *> tree = TriangleV::ImageTriangleVUtil::TriangleV(
                "D:\\Project\\QtProject\\triangleDomain\\Images\\Lena64.png");
        TriangleV::TriangleVUtil::TriangleVFitting(tree[0]);
        TriangleV::TriangleVUtil::TriangleVFitting(tree[1]);

        return tree;
    }

    std::vector<std::vector<std::vector<float>>> TestService::FirstGroupOfTriangleVTest() {
        //  设置图像
        std::vector<std::vector<CalculateData *>> image;
        for (int i = 0; i < 512; ++i) {
            std::vector<CalculateData *> temp;
            for (int j = 0; j < 512; ++j) {
                CalculateData *model = new CalculateData();
                TriangleDomain::SamplingData *samplingData = new TriangleDomain::SamplingData();
                TriangleDomain::Point *point = new TriangleDomain::Point(i + 1, j + 1);
                samplingData->setPoint(point);
                samplingData->setValue(0.0f);

                model->data = samplingData;
                temp.push_back(model);
            }
            image.push_back(temp);
        }

        //  设定三角形
        TriangleDomain::Triangle triangle;
        triangle.setVertexA(image[0][511]->data->getPoint());
        triangle.setVertexB(image[511][0]->data->getPoint());
        triangle.setVertexC(image[511][511]->data->getPoint());

        //  选出在三角形中的点
        std::vector<CalculateData *> selectedPoint;
        for (auto temp:image) {
            for (auto model:temp) {
                if (triangle.isPointInTriangle(model->data->getPoint()) >= 0) {
                    model->SetAreaPoint(triangle);
                    selectedPoint.push_back(model);
                }
            }
        }

        //  得到第一组基函数的值(9组)
        std::vector<std::vector<float>> firstGroupV = TriangleVUtil::FirstV(selectedPoint);
        std::vector<std::vector<float>> secondGroupV = TriangleVUtil::GenerateV(selectedPoint, 1);

        /// TODO
        //  为输出的每个像素点赋值（每个点的值 9个）
        std::vector<std::vector<std::vector<float>>> res;
        for (int i = 0; i < 512; ++i) {
            std::vector<std::vector<float>> temp;
            for (int j = 0; j < 512; ++j) {
                std::vector<float> single(9);
                temp.push_back(single);
            }
            res.push_back(temp);
        }


        return res;
    }
}