//
// Created by WalterWhite on 2021/6/7.
//

#include "FileUtil.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//  rapidjson
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/filereadstream.h>


namespace TriangleDomain {
    std::vector<std::vector<SamplingData>> FileUtil::ReadImage(std::string fileName) {
        std::vector<std::vector<SamplingData>> result;

        cv::Mat image;
        image = cv::imread(fileName, cv::IMREAD_GRAYSCALE);
        if (image.data == nullptr) {
            std::cerr << "Failed To Read Image!" << std::endl;
            return result;
        }

        //显示图片
//        cv::imshow("Origin Image", image);

//        cv::waitKey();

        int row = image.rows;
        int col = image.cols;
        for (int i = 0; i < row; ++i) {
            std::vector<SamplingData> model;
            for (int j = 0; j < col; ++j) {
                model.push_back(SamplingData(new Point(i + 0.5f, j + 0.5f), image.at<uchar>(i, j)));
//                model.push_back(SamplingData(new Point(i + 0.5f, j + 0.5f), 0.f));
            }
            result.push_back(model);
        }
        return result;
    }

    void FileUtil::ShowReconstructionImage(std::vector<std::vector<SamplingData>> reconstructionImage) {
        int row = reconstructionImage.size();
        int col = reconstructionImage[0].size();

        cv::Mat image(row, col, CV_8UC1);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                image.at<uchar>(i, j) = reconstructionImage[i][j].getValue();
            }
        }

//        cv::imshow("Reconstruction Image0", image);
//        cv::waitKey();
    }

    void FileUtil::SaveImageBySampleData(std::vector<SamplingData> dataList, int imgSize, std::string path) {
        cv::Mat image(imgSize, imgSize, CV_8UC1);

        for (auto model: dataList) {
            image.at<uchar>(model.getPoint()->getX(), model.getPoint()->getY()) = model.getValue();
        }

        cv::imwrite(path, image);
    }

    void FileUtil::SaveFittingInfo(std::vector<FittingInfo> data, std::string path) {
        std::string filePath = path + "\\data.json";
        std::cerr << "Write" << std::endl;


        rapidjson::Document doc;
        doc.SetObject();
        rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

        int i = 1;
        //  对每一条数据进行读取
        for (const auto model: data) {
            rapidjson::Value jModel(rapidjson::kArrayType);
            jModel.SetObject();

            //  写入点集
            rapidjson::Value pointList(rapidjson::kArrayType);
            for (const auto point:model.getPointList()) {
                pointList.PushBack(point.getX(), allocator);
                pointList.PushBack(point.getY(), allocator);
            }
            jModel.AddMember("PointList", pointList, allocator);

            //  写入面积坐标
            rapidjson::Value areaList(rapidjson::kArrayType);
            for (const auto area:model.getAreaPointList()) {
                areaList.PushBack(area.getU(), allocator);
                areaList.PushBack(area.getV(), allocator);
                areaList.PushBack(area.getW(), allocator);
            }
            jModel.AddMember("AreaList", areaList, allocator);

            //  写入三角形
            rapidjson::Value triangle(rapidjson::kArrayType);
            triangle.PushBack(model.getTriangle().getVertexA()->getX(), allocator);
            triangle.PushBack(model.getTriangle().getVertexA()->getY(), allocator);
            triangle.PushBack(model.getTriangle().getVertexB()->getX(), allocator);
            triangle.PushBack(model.getTriangle().getVertexB()->getY(), allocator);
            triangle.PushBack(model.getTriangle().getVertexC()->getX(), allocator);
            triangle.PushBack(model.getTriangle().getVertexC()->getY(), allocator);
            jModel.AddMember("Triangle", triangle, allocator);

            //  写入拟合参数
            rapidjson::Value fittingList(rapidjson::kArrayType);
            for (const auto fitting:model.getFittingParam()) {
                fittingList.PushBack(fitting, allocator);
            }
            jModel.AddMember("Fitting", fittingList, allocator);

            //  写入定位
            rapidjson::Value location(rapidjson::kArrayType);
            for (const auto loc:model.getTriangleLocation()) {
                location.PushBack(loc, allocator);
            }
            jModel.AddMember("Location", location, allocator);

            //  写入误差
            rapidjson::Value error(rapidjson::kArrayType);
            error.PushBack(model.getError(), allocator);
            jModel.AddMember("Error", error, allocator);

            doc.AddMember("ele", jModel, allocator);
        }

        // 写文件
        FILE *fp = fopen(filePath.c_str(), "w");
        char writeBuffer[65535];
        rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
        doc.Accept(writer);
        fclose(fp);
    }

    void FileUtil::SaveImage(std::vector<std::vector<std::vector<SamplingData>>> imageList, std::string path) {
        int i = 1;
        for (const auto image:imageList) {
            cv::Mat imageMat(image.size(), image[0].size(), CV_8UC1);

            for (size_t row = 0; row < image.size(); row++) {
                for (size_t col = 0; col < image[row].size(); col++) {
                    imageMat.at<uchar>(image[row][col].getPoint()->getX(),
                                       image[row][col].getPoint()->getY()) = image[row][col].getValue();
                }
            }
            std::string filePath = path + "\\" + std::to_string(i) + ".jpg";
            cv::imwrite(filePath, imageMat);
            i++;
        }
    }

    void FileUtil::WriteTiCSV(std::vector<std::vector<std::string>> src, std::string filePath) {
        std::ofstream outFile;
        outFile.open(filePath, std::ios::out);

        for (const auto dataRow:src) {
            for (size_t i = 0; i < dataRow.size() - 1; i++) {
                outFile << dataRow[i] << ",";
            }
            outFile << dataRow[dataRow.size() - 1] << std::endl;
        }

        outFile.close();
    }

}
