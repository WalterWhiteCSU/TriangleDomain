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
        std::vector<std::vector<TriangleDomain::SamplingData>> res;
        for (size_t i = 0; i < selectedPoint.size(); i++) {
            std::vector<TriangleDomain::SamplingData> pointList;

            for (auto value: firstGroupV[i]) {
                TriangleDomain::SamplingData model;
                model.setPoint(selectedPoint[i]->data->getPoint());
                model.setValue(value);
                pointList.push_back(model);
            }

            for (auto value: secondGroupV[i]) {
                TriangleDomain::SamplingData model;
                model.setPoint(selectedPoint[i]->data->getPoint());
                model.setValue(value);
                pointList.push_back(model);
            }
            res.push_back(pointList);
        }
        return res;
    }

    void TestService::ShowRecontructedImage(std::string imagePath, std::vector<ImageQuadTree *> imageTree) {
        //  读取原始图像
        std::vector<std::vector<TriangleDomain::SamplingData>> image = TriangleDomain::FileUtil::ReadImage(
                std::move(imagePath));
    }

}