/********************************************************************************
** Form generated from reading UI file 'trianglevwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEVWINDOW_H
#define UI_TRIANGLEVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangleVWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *function_widget;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *bernstein_fitting_btn;
    QCommandLinkButton *triangle_v_base_function_btn;
    QCommandLinkButton *triangle_v_image_processing_btn;
    QWidget *work_widget;

    void setupUi(QWidget *TriangleVWindow)
    {
        if (TriangleVWindow->objectName().isEmpty())
            TriangleVWindow->setObjectName(QString::fromUtf8("TriangleVWindow"));
        TriangleVWindow->resize(1507, 904);
        verticalLayout = new QVBoxLayout(TriangleVWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        function_widget = new QWidget(TriangleVWindow);
        function_widget->setObjectName(QString::fromUtf8("function_widget"));
        function_widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(function_widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bernstein_fitting_btn = new QCommandLinkButton(function_widget);
        bernstein_fitting_btn->setObjectName(QString::fromUtf8("bernstein_fitting_btn"));

        horizontalLayout->addWidget(bernstein_fitting_btn);

        triangle_v_base_function_btn = new QCommandLinkButton(function_widget);
        triangle_v_base_function_btn->setObjectName(QString::fromUtf8("triangle_v_base_function_btn"));

        horizontalLayout->addWidget(triangle_v_base_function_btn);

        triangle_v_image_processing_btn = new QCommandLinkButton(function_widget);
        triangle_v_image_processing_btn->setObjectName(QString::fromUtf8("triangle_v_image_processing_btn"));

        horizontalLayout->addWidget(triangle_v_image_processing_btn);


        verticalLayout->addWidget(function_widget);

        work_widget = new QWidget(TriangleVWindow);
        work_widget->setObjectName(QString::fromUtf8("work_widget"));

        verticalLayout->addWidget(work_widget);


        retranslateUi(TriangleVWindow);

        QMetaObject::connectSlotsByName(TriangleVWindow);
    } // setupUi

    void retranslateUi(QWidget *TriangleVWindow)
    {
        TriangleVWindow->setWindowTitle(QCoreApplication::translate("TriangleVWindow", "TriangleVWindow", nullptr));
        bernstein_fitting_btn->setText(QCoreApplication::translate("TriangleVWindow", "Bernstein Fitting", nullptr));
        triangle_v_base_function_btn->setText(QCoreApplication::translate("TriangleVWindow", "Triangle V System Base Function", nullptr));
        triangle_v_image_processing_btn->setText(QCoreApplication::translate("TriangleVWindow", "Triangle V System Image Processing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleVWindow: public Ui_TriangleVWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEVWINDOW_H
