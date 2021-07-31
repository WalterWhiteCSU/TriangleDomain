/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                trianglevwindow.cpp
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/29
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

// You may need to build the project (run Qt uic code generator) to get "ui_TriangleVWindow.h" resolved

#include "trianglevwindow.h"
#include "ui_TriangleVWindow.h"


TriangleVWindow::TriangleVWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::TriangleVWindow) {
    ui->setupUi(this);
}

TriangleVWindow::~TriangleVWindow() {
    delete ui;
}

