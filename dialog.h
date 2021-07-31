//
// Created by WalterWhite on 2021/6/22.
//

#ifndef TRIANGLEDOMAIN_DIALOG_H
#define TRIANGLEDOMAIN_DIALOG_H

#include <QWidget>
#include "mainwindow.h"
#include "include/FileUtil.h"
#include "include/TriangulationUtil.h"

#include "include/ImageTriangleVUtil.h"
#include "include/TriangleVUtil.h"
#include "TestService.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QWidget {
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

private slots:

    /*   伯恩斯坦基   */
    void on_bernsteinBtn_clicked();

    /*   三角域V基   */
    void on_vSystemBtn_clicked();

private:
    Ui::Dialog *ui;

    QWidget *workWidget;
};


#endif //TRIANGLEDOMAIN_DIALOG_H
