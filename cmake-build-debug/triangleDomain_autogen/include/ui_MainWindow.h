/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *OriginalImage;
    QLabel *ReconstructionImage;
    QWidget *widget;
    QRadioButton *triangulationBtn;
    QRadioButton *descartesBtn;
    QRadioButton *quadraticBtn;
    QPushButton *readFileBtn;
    QLineEdit *permitError;
    QRadioButton *linearBtn;
    QTextBrowser *infoBox;
    QPushButton *startBtn;
    QPushButton *changeBtn;
    QLabel *label;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1537, 849);
        horizontalLayout = new QHBoxLayout(MainWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OriginalImage = new QLabel(MainWindow);
        OriginalImage->setObjectName(QString::fromUtf8("OriginalImage"));

        horizontalLayout->addWidget(OriginalImage);

        ReconstructionImage = new QLabel(MainWindow);
        ReconstructionImage->setObjectName(QString::fromUtf8("ReconstructionImage"));

        horizontalLayout->addWidget(ReconstructionImage);

        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(409, 16777215));
        triangulationBtn = new QRadioButton(widget);
        triangulationBtn->setObjectName(QString::fromUtf8("triangulationBtn"));
        triangulationBtn->setGeometry(QRect(9, 93, 111, 20));
        descartesBtn = new QRadioButton(widget);
        descartesBtn->setObjectName(QString::fromUtf8("descartesBtn"));
        descartesBtn->setGeometry(QRect(9, 127, 111, 20));
        quadraticBtn = new QRadioButton(widget);
        quadraticBtn->setObjectName(QString::fromUtf8("quadraticBtn"));
        quadraticBtn->setGeometry(QRect(9, 195, 91, 20));
        readFileBtn = new QPushButton(widget);
        readFileBtn->setObjectName(QString::fromUtf8("readFileBtn"));
        readFileBtn->setGeometry(QRect(9, 55, 75, 24));
        permitError = new QLineEdit(widget);
        permitError->setObjectName(QString::fromUtf8("permitError"));
        permitError->setGeometry(QRect(10, 260, 133, 21));
        linearBtn = new QRadioButton(widget);
        linearBtn->setObjectName(QString::fromUtf8("linearBtn"));
        linearBtn->setGeometry(QRect(9, 161, 91, 20));
        infoBox = new QTextBrowser(widget);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));
        infoBox->setGeometry(QRect(10, 420, 341, 401));
        startBtn = new QPushButton(widget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        startBtn->setGeometry(QRect(20, 320, 75, 24));
        changeBtn = new QPushButton(widget);
        changeBtn->setObjectName(QString::fromUtf8("changeBtn"));
        changeBtn->setGeometry(QRect(170, 320, 75, 24));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 240, 161, 16));

        horizontalLayout->addWidget(widget);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OriginalImage->setText(QCoreApplication::translate("MainWindow", "The Original Image", nullptr));
        ReconstructionImage->setText(QCoreApplication::translate("MainWindow", "The Reconstructed Image", nullptr));
        triangulationBtn->setText(QCoreApplication::translate("MainWindow", "Triangular", nullptr));
        descartesBtn->setText(QCoreApplication::translate("MainWindow", "Descartes", nullptr));
        quadraticBtn->setText(QCoreApplication::translate("MainWindow", "Quadratic", nullptr));
        readFileBtn->setText(QCoreApplication::translate("MainWindow", "ReadImage", nullptr));
        linearBtn->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        changeBtn->setText(QCoreApplication::translate("MainWindow", "mask", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Please Input Permit Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
