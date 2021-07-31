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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ReconstructionImage;
    QLabel *OriginalImage;
    QWidget *controlWidget;
    QVBoxLayout *verticalLayout;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *readFileBtn;
    QWidget *systemTypeWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *triangulationBtn;
    QRadioButton *descartesBtn;
    QWidget *systemTimesWidget;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *linearBtn;
    QRadioButton *quadraticBtn;
    QWidget *errorInputWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLineEdit *permitError;
    QPushButton *startBtn;
    QPushButton *changeBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *infoBox;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1537, 847);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 197)"));
        verticalLayout_6 = new QVBoxLayout(MainWindow);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ReconstructionImage = new QLabel(widget);
        ReconstructionImage->setObjectName(QString::fromUtf8("ReconstructionImage"));
        ReconstructionImage->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"\n"
"border-radius: 25px;\n"
"border-width: 3px;\n"
"border-style: solid;\n"
"border-color:rgb(16, 16, 16);"));

        horizontalLayout_2->addWidget(ReconstructionImage);

        OriginalImage = new QLabel(widget);
        OriginalImage->setObjectName(QString::fromUtf8("OriginalImage"));
        OriginalImage->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"\n"
"\n"
"border-radius: 25px;\n"
"border-width: 3px;\n"
"border-style: solid;\n"
"border-color:rgb(16, 16, 16);"));

        horizontalLayout_2->addWidget(OriginalImage);

        controlWidget = new QWidget(widget);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setMaximumSize(QSize(409, 16777215));
        verticalLayout = new QVBoxLayout(controlWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoWidget = new QWidget(controlWidget);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        verticalLayout_4 = new QVBoxLayout(infoWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        readFileBtn = new QPushButton(infoWidget);
        readFileBtn->setObjectName(QString::fromUtf8("readFileBtn"));
        readFileBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgb(225, 225, 225);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:rgb(176, 176, 176);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-style:inset;\n"
"}\n"
"\n"
"\n"
""));

        verticalLayout_4->addWidget(readFileBtn);

        systemTypeWidget = new QWidget(infoWidget);
        systemTypeWidget->setObjectName(QString::fromUtf8("systemTypeWidget"));
        systemTypeWidget->setMaximumSize(QSize(16777215, 50));
        verticalLayout_2 = new QVBoxLayout(systemTypeWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        triangulationBtn = new QRadioButton(systemTypeWidget);
        triangulationBtn->setObjectName(QString::fromUtf8("triangulationBtn"));

        verticalLayout_2->addWidget(triangulationBtn);

        descartesBtn = new QRadioButton(systemTypeWidget);
        descartesBtn->setObjectName(QString::fromUtf8("descartesBtn"));

        verticalLayout_2->addWidget(descartesBtn);


        verticalLayout_4->addWidget(systemTypeWidget);

        systemTimesWidget = new QWidget(infoWidget);
        systemTimesWidget->setObjectName(QString::fromUtf8("systemTimesWidget"));
        systemTimesWidget->setMaximumSize(QSize(16777215, 50));
        verticalLayout_3 = new QVBoxLayout(systemTimesWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        linearBtn = new QRadioButton(systemTimesWidget);
        linearBtn->setObjectName(QString::fromUtf8("linearBtn"));

        verticalLayout_3->addWidget(linearBtn);

        quadraticBtn = new QRadioButton(systemTimesWidget);
        quadraticBtn->setObjectName(QString::fromUtf8("quadraticBtn"));

        verticalLayout_3->addWidget(quadraticBtn);


        verticalLayout_4->addWidget(systemTimesWidget);

        errorInputWidget = new QWidget(infoWidget);
        errorInputWidget->setObjectName(QString::fromUtf8("errorInputWidget"));
        errorInputWidget->setMaximumSize(QSize(16777215, 80));
        verticalLayout_5 = new QVBoxLayout(errorInputWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(errorInputWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        permitError = new QLineEdit(errorInputWidget);
        permitError->setObjectName(QString::fromUtf8("permitError"));
        permitError->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 225, 225);\n"
"border-radius:5px;"));

        verticalLayout_5->addWidget(permitError);


        verticalLayout_4->addWidget(errorInputWidget);

        startBtn = new QPushButton(infoWidget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        startBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 225, 225);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:rgb(176, 176, 176);"));

        verticalLayout_4->addWidget(startBtn);

        changeBtn = new QPushButton(infoWidget);
        changeBtn->setObjectName(QString::fromUtf8("changeBtn"));
        changeBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 225, 225);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:rgb(176, 176, 176);"));

        verticalLayout_4->addWidget(changeBtn);


        verticalLayout->addWidget(infoWidget);


        horizontalLayout_2->addWidget(controlWidget);


        verticalLayout_6->addWidget(widget);

        widget_2 = new QWidget(MainWindow);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 200));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        infoBox = new QTextBrowser(widget_2);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));
        infoBox->setMaximumSize(QSize(16777215, 500));
        infoBox->setStyleSheet(QString::fromUtf8("background-color:rgb(212, 212, 212);\n"
"\n"
"\n"
"border-radius: 25px;\n"
"border-width: 3px;\n"
"border-style: solid;\n"
"border-color:rgb(16, 16, 16);"));

        verticalLayout_7->addWidget(infoBox);


        verticalLayout_6->addWidget(widget_2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ReconstructionImage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">The Reconstructed Image</span></p></body></html>", nullptr));
        OriginalImage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">The Original Image</span></p></body></html>", nullptr));
        readFileBtn->setText(QCoreApplication::translate("MainWindow", "ReadImage", nullptr));
        triangulationBtn->setText(QCoreApplication::translate("MainWindow", "Triangular", nullptr));
        descartesBtn->setText(QCoreApplication::translate("MainWindow", "Descartes", nullptr));
        linearBtn->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        quadraticBtn->setText(QCoreApplication::translate("MainWindow", "Quadratic", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Please Input Permit Error</span></p></body></html>", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        changeBtn->setText(QCoreApplication::translate("MainWindow", "mask", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
