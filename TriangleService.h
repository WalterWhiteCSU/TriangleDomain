/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/21
 *      @Last Modified Date:    2021/6/21
 *
 *      @Descript:
 *          信息的管理类，存放各种信息
 *
 *          @Param:
 *              imageFileName:      图像的位置信息
 *
 *
 ***************************************************************
 * */
#ifndef TRIANGLEDOMAIN_TRIANGLESERVICE_H
#define TRIANGLEDOMAIN_TRIANGLESERVICE_H

#include <QTextBrowser>
#include "include/TriangulationUtil.h"
#include "include/ReconstructionUtil.h"
#include "include/FittingInfo.h"

namespace TriangleDomain {
    class TriangleService {
    public:
        /*
         * 三角剖分服务
         *
         *      @Param:
         *          triangleInfo:           各种输入信息
         *          infobox:                消息输出
         *
         *      @Return:
         *          std::vector<std::vector<SamplingData>>:
         *                  重建的图像
         * */
        static std::vector<std::vector<std::vector<SamplingData>>>
        TriangleSectionServe(InfoManager &triangleInfo, QTextBrowser *infobox) {

            infobox->insertPlainText("Processing Start..........................................................\n");

            std::vector<std::vector<std::vector<SamplingData>>> sectionData;
            std::vector<FittingInfo> fittingInfoList;
            switch (triangleInfo.domainType) {
                case 1:
                    infobox->insertPlainText("Start Area Coordinate Triangle Section Process......\n");
                    sectionData = TriangleDomain::TriangulationUtil::AreaCoordinateTriangulation(triangleInfo.data,
                                                                                                 triangleInfo.functionType,
                                                                                                 triangleInfo.permitError,
                                                                                                 fittingInfoList);
                    infobox->insertPlainText("# Area Coordinate Triangle Section Process Sucess!\n");
                    infobox->insertPlainText("Use ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(triangleInfo.functionType)));
                    infobox->insertPlainText(" Area Coordinate System\nThe permit Error is ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(triangleInfo.permitError)));
                    infobox->insertPlainText("\nThe PSNR Of This Image is:    ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(
                            ReconstructionUtil::ImagePSNR(triangleInfo.data, sectionData[0]))));
                    infobox->insertPlainText("\n");


                    break;
                case 2:
                    infobox->insertPlainText("Start Descartes Coordinate Triangle Section Process......\n");
                    sectionData = TriangleDomain::TriangulationUtil::DescartesCoordinatesTriangulation(
                            triangleInfo.data, triangleInfo.functionType, triangleInfo.permitError,fittingInfoList);
                    infobox->insertPlainText("# Descartes Coordinate Triangle Section Process Sucess!\n");
                    infobox->insertPlainText("Use ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(triangleInfo.functionType)));
                    infobox->insertPlainText(" Descartes Coordinate System\nThe permit Error is ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(triangleInfo.permitError)));
                    infobox->insertPlainText("\n");
                    infobox->insertPlainText("\nThe PSNR Of This Image is:    ");
                    infobox->insertPlainText(QString::fromStdString(std::to_string(
                            ReconstructionUtil::ImagePSNR(triangleInfo.data, sectionData[0]))));
                    infobox->insertPlainText("\n\n\n");
                    break;
            }
            return sectionData;

        }
    };
}

#endif //TRIANGLEDOMAIN_TRIANGLESERVICE_H
