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
#include <opencv2/opencv.hpp>


namespace TriangleV {
    std::vector<ImageQuadTree *> TestService::ImageQuadTreeFittingTest(std::string imagePath) {
        //  显示图像
//        cv::Mat img = cv::imread("D:\\Project\\QtProject\\triangleDomain\\Images\\Lena16.png", 0);
//        cv::imshow("origin", img);

        std::vector<ImageQuadTree *> tree = TriangleV::ImageTriangleVUtil::TriangleV(
                imagePath);
        TriangleV::TriangleVUtil::TriangleVFitting(tree[0]);
        TriangleV::TriangleVUtil::TriangleVFitting(tree[1]);

        return tree;
    }

    std::vector<std::vector<TriangleDomain::SamplingData>> TestService::FirstGroupOfTriangleVTest() {
        //  设置图像
        std::vector<std::vector<TriangleDomain::SamplingData>> image;
        for (int i = 0; i < 512; ++i) {
            std::vector<TriangleDomain::SamplingData> temp;
            for (int j = 0; j < 512; ++j) {
                TriangleDomain::SamplingData model;
                model.setPoint(new TriangleDomain::Point(i + 1, j + 1));
                model.setValue(0.f);

                temp.push_back(model);
            }
            image.push_back(temp);
        }

        //  设定三角形
        TriangleDomain::Triangle triangle;
        triangle.setVertexA(image[511][0].getPoint());
        triangle.setVertexB(image[0][511].getPoint());
        triangle.setVertexC(image[0][0].getPoint());
        std::vector<TriangleDomain::Triangle> triList;
        triList.push_back(triangle);

        //  得到生成的树
        auto triangleDataList = TriangleV::ImageTriangleVUtil::InitialTriangleSection(image, triList);
        TriangleV::ImageQuadTree *model = TriangleV::ImageTriangleVUtil::ImageQuadTreeGenerator(triangleDataList[0],
                                                                                                triangle);
        std::cout << "tree generate success!" << std::endl;
        //  得到总共的数据点
        std::vector<CalculateData *> totalData = model->tree->dataList;
        //  层次遍历，得到每个节点中的数据
        std::vector<ImageQuadTreeNode *> nodeList = model->levelOrder();

        //  得到三角域V系统矩阵
        Eigen::MatrixXf vMatrix = TriangleVUtil::GetVMatrix(totalData, nodeList, model->layer);

        //  为输出的每个像素点赋值（每个点的值 9个）
        std::vector<std::vector<TriangleDomain::SamplingData>> res;
        for (size_t i = 0; i < vMatrix.cols(); i++) {
            std::vector<std::vector<std::string>> fileList;

            for (size_t j = 0; j < vMatrix.rows(); j++) {
                std::vector<std::string> model;
                model.push_back(std::to_string(totalData[j]->data->getPoint()->getX()));
                model.push_back(std::to_string(totalData[j]->data->getPoint()->getY()));
                model.push_back(std::to_string(vMatrix(j, i)));
                fileList.push_back(model);
            }

            std::string fileName;
            if (i / 10 <= 0) {
                fileName = "0000" + std::to_string(i) + ".csv";
            } else if (i / 100 <= 0) {
                fileName = "000" + std::to_string(i) + ".csv";
            } else if (i / 1000 <= 0) {
                fileName = "00" + std::to_string(i) + ".csv";
            } else if (i / 10000 <= 0) {
                fileName = "0" + std::to_string(i) + ".csv";
            } else {
                fileName = std::to_string(i) + ".csv";
            }

            TriangleDomain::FileUtil::WriteTiCSV(fileList, "D:\\Experiment\\TriangleImageSectionData\\" + fileName);
        }
        return res;
    }

    void TestService::ShowRecontructedImage(std::string imagePath, std::vector<ImageQuadTree *> imageTree) {
        //  读取原始图像
        std::vector<std::vector<TriangleDomain::SamplingData>> image = TriangleDomain::FileUtil::ReadImage(
                std::move(imagePath));
    }

}