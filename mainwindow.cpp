//
// Created by WalterWhite on 2021/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QIntValidator>
#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //  初始化ButtonGroup
    this->domainGroup = new QButtonGroup(this);
    domainGroup->addButton(this->ui->triangulationBtn, 1);
    domainGroup->addButton(this->ui->descartesBtn, 2);
    //  设置默认选中
    ui->triangulationBtn->setChecked(true);

    this->functionGroup = new QButtonGroup(this);
    functionGroup->addButton(this->ui->linearBtn, 1);
    functionGroup->addButton(this->ui->quadraticBtn, 2);
    //  设置默认选中
    ui->linearBtn->setChecked(true);

    //  限制只能输入整型误差
    ui->permitError->setValidator(new QIntValidator(ui->permitError));
    //  显示
    ui->permitError->setText("10");

    //  设置输出框光标在最后
    ui->infoBox->moveCursor(QTextCursor::End);
}

MainWindow::~MainWindow() {
    delete ui;
}

/*   通过二维矩阵展示图像   */
void MainWindow::showImageFromVector(std::vector<std::vector<TriangleDomain::SamplingData>> &image, QLabel *label) {
    int row = image.size();
    int col = image[0].size();

    //  创建图像
    QImage ima = QImage(col, row, QImage::Format_Grayscale8);
    //  为每个像素设置值
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int value = image[i][j].getValue();
            ima.setPixel(j, i, qRgb(value, value, value));
        }
    }

    //  显示图像
    QPixmap pix = QPixmap::fromImage(ima);
    label->setPixmap(pix);
    label->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_readFileBtn_clicked() {
    std::cout << "Clicked!" << std::endl;

    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("文件"), "..\\Images");

    //  将文件读取
    this->triangleData.imageFileName = fileName.toStdString();

    //  在原图像区域显示
    auto image = TriangleDomain::FileUtil::ReadImage(triangleData.imageFileName);
    this->triangleData.data = image;
    showImageFromVector(image, ui->OriginalImage);
}

void MainWindow::on_triangulationBtn_clicked() {
    this->triangleData.domainType = 1;
    std::cout << 1 << std::endl;
}

void MainWindow::on_descartesBtn_clicked() {
    this->triangleData.domainType = 2;
    std::cout << 2 << std::endl;
}

void MainWindow::on_linearBtn_clicked() {
    this->triangleData.functionType = 1;
    std::cout << 3 << std::endl;
}

void MainWindow::on_quadraticBtn_clicked() {
    this->triangleData.functionType = 2;
    std::cout << 4 << std::endl;
}

void MainWindow::on_permitError_textChanged(const QString &arg1) {
    std::cout << arg1.toStdString() << std::endl;
    int value = std::stoi(arg1.toStdString());

    this->triangleData.permitError = value;
}

void MainWindow::on_startBtn_clicked() {
    this->triangleData.showMask = true;
    std::vector<std::vector<std::vector<TriangleDomain::SamplingData>>> data =
            TriangleDomain::TriangleService::TriangleSectionServe(this->triangleData, ui->infoBox);

    this->triangleData.sectionData = data[0];
    this->triangleData.maskData = data[1];
    //  绘制
    showImageFromVector(this->triangleData.maskData, ui->ReconstructionImage);
}

void MainWindow::on_changeBtn_clicked() {
    if (this->triangleData.sectionData.size() == 0)
        return;
    else {
        if (this->triangleData.showMask) {
            this->triangleData.showMask = false;
            showImageFromVector(this->triangleData.sectionData, ui->ReconstructionImage);
        } else {
            this->triangleData.showMask = true;
            showImageFromVector(this->triangleData.maskData, ui->ReconstructionImage);
        }
    }

}

