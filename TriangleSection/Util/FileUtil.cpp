//
// Created by WalterWhite on 2021/6/7.
//

#include "FileUtil.h"


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

    void FileUtil::SaveFittingInfo(std::vector<FittingInfo> data, std::string) {

    }

}
