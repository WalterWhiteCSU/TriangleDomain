/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/21
 *      @Last Modified Date:    2021/6/21
 *
 *      @Descript:
 *          窗口
 *
 *          @Param:
 *              ui:窗口的实体
 *
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_MAINWINDOW_H
#define TRIANGLEDOMAIN_MAINWINDOW_H

#include <QWidget>

#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QButtonGroup>
#include <iostream>
#include <vector>
#include <string>
#include "TriangleSection/Entity/SamplingData.h"
#include "TriangleSection/Util/FileUtil.h"
#include "dialog.h"
#include "InfoManager.h"
#include "TriangleService.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    /*
         * 通过二维矩阵展示图像
         *
         *      @Param:
         *          image:            图像的二维矩阵
         *
         *      @Return:
         * */
    static void showImageFromVector(std::vector<std::vector<TriangleDomain::SamplingData>> &image, QLabel *label);


    //  槽
private slots:

    /*   读取文件button   */
    void on_readFileBtn_clicked();

    /*   选择三角域   */
    void on_triangulationBtn_clicked();

    /*   选择笛卡尔域   */
    void on_descartesBtn_clicked();

    /*    选择一次系统  */
    void on_linearBtn_clicked();

    /*   选择二次系统   */
    void on_quadraticBtn_clicked();

    /*   输入容许误差   */
    void on_permitError_textChanged(const QString &arg1);

    /*   开始按钮   */
    void on_startBtn_clicked();

    /*   是否显示网格   */
    void on_changeBtn_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup *domainGroup;
    QButtonGroup *functionGroup;

    Dialog *dialog;
    QString info;

    TriangleDomain::InfoManager triangleData;
};


#endif //TRIANGLEDOMAIN_MAINWINDOW_H
