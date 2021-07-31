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
    //  图像三角域V系统拟合测试
    auto tree = TriangleV::TestService::ImageQuadTreeFittingTest();

    auto testImage = TriangleV::TestService::FirstGroupOfTriangleVTest();
    std::cout << "test" << std::endl;
}

