//
// Created by WalterWhite on 2021/6/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Dialog.h" resolved

#include "dialog.h"
#include "ui_Dialog.h"


Dialog::Dialog(QWidget *parent) :
        QWidget(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
}

Dialog::~Dialog() {
    delete ui;
}

