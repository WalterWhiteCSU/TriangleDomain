/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bernsteinBtn;
    QPushButton *vSystemBtn;

    void setupUi(QWidget *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(300, 260);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 197)"));
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(250, 200));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bernsteinBtn = new QPushButton(widget);
        bernsteinBtn->setObjectName(QString::fromUtf8("bernsteinBtn"));
        bernsteinBtn->setMinimumSize(QSize(100, 26));
        bernsteinBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgb(225, 225, 225);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:rgb(176, 176, 176);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-style:inset;\n"
"}"));

        horizontalLayout_2->addWidget(bernsteinBtn);

        vSystemBtn = new QPushButton(widget);
        vSystemBtn->setObjectName(QString::fromUtf8("vSystemBtn"));
        vSystemBtn->setMinimumSize(QSize(100, 26));
        vSystemBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgb(225, 225, 225);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:rgb(176, 176, 176);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-style:inset;\n"
"}"));

        horizontalLayout_2->addWidget(vSystemBtn);


        horizontalLayout->addWidget(widget);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QWidget *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        bernsteinBtn->setText(QCoreApplication::translate("Dialog", "Bernstein", nullptr));
        vSystemBtn->setText(QCoreApplication::translate("Dialog", "V-System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
