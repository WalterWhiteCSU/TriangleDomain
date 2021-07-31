/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                trianglevwindow.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/29
  *Description:             系统的主窗口
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_TRIANGLEVWINDOW_H
#define TRIANGLEDOMAIN_TRIANGLEVWINDOW_H

#include <QWidget>
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class TriangleVWindow; }
QT_END_NAMESPACE

class TriangleVWindow : public QWidget {
Q_OBJECT

public:
    explicit TriangleVWindow(QWidget *parent = nullptr);

    ~TriangleVWindow() override;

private:
    Ui::TriangleVWindow *ui;
};


#endif //TRIANGLEDOMAIN_TRIANGLEVWINDOW_H
