//
// Created by WalterWhite on 2021/6/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Dialog.h" resolved

#include "dialog.h"
#include "ui_Dialog.h"


Dialog::Dialog(QWidget *parent) :
        QWidget(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
    this->workWidget = nullptr;
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_bernsteinBtn_clicked() {
    MainWindow *work = new MainWindow();
    if (this->workWidget != nullptr) {
        delete this->workWidget;
    }
    this->workWidget = work;
    this->workWidget->show();
}

void Dialog::on_vSystemBtn_clicked() {
//    //  图像路径
//    std::string imagePath = "D:\\Project\\QtProject\\triangleDomain\\Images\\Lena64.png";
//    //  图像三角域V系统拟合测试
//    auto tree = TriangleV::TestService::ImageQuadTreeFittingTest(imagePath);
    //  重建图像
//    TriangleV::TestService::ShowRecontructedImage(imagePath, tree);

    //  第一组V系统
    std::vector<std::vector<TriangleDomain::SamplingData>> data = TriangleV::TestService::FirstGroupOfTriangleVTest();

//    std::cout << "Get V MAtrx" << std::endl;
    //  写文件
//    for (size_t col = 0; col < data[0].size(); col++) {
//        std::vector<std::vector<std::string>> fileList;
//        for (size_t row = 0; row < data.size(); row++) {
//            std::vector<std::string> model;
//
//            model.push_back(std::to_string(data[row][col].getPoint()->getX() / 128.f));
//            model.push_back(std::to_string(data[row][col].getPoint()->getY() / 128.f));
//            model.push_back(std::to_string(data[row][col].getValue()));
//
//            fileList.push_back(model);
//        }
//
//        std::string fileName;
//        if (col / 10 <= 0) {
//            fileName = "00" + std::to_string(col) + ".csv";
//        } else if (col / 100 <= 0) {
//            fileName = "0" + std::to_string(col) + ".csv";
//        } else {
//            fileName = std::to_string(col) + ".csv";
//        }
//
//        TriangleDomain::FileUtil::WriteTiCSV(fileList, "D:\\Experiment\\TriangleImageSectionData\\" + fileName);
    }
//    //  写文件CSV
//    std::vector<std::vector<std::string>> fileList00;
//    for(const auto pix:image)
//    {
//        std::vector<std::string> model0;
//        model0.push_back(std::to_string(pix[0].getPoint()->getX() / 512.f));
//        model0.push_back(std::to_string(pix[0].getPoint()->getY() / 512.f));
//        model0.push_back(std::to_string(pix[0].getValue()));
//        fileList00.push_back(model0);
//    }
//
//    TriangleDomain::FileUtil::WriteTiCSV(fileList00, "D:\\Experiment\\TriangleImageSectionData\\01.csv");
//
//    std::cout << "test" << std::endl;
//}

