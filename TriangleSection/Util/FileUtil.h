/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          进行图片读写的工具类
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_FILEUTIL_H
#define TRIANGLEDOMAIN_FILEUTIL_H


#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../Entity/SamplingData.h"
#include "../Entity/AreaCoordinateSamplingData.h"
#include "../Entity/DescartesCoordinateSamplingData.h"
#include "../Entity/FittingInfo.h"

namespace TriangleDomain {

    class FileUtil {
    public:
        /*
         * 读取图片，转换为二维列表信息
         *
         *      @Param:
         *          fileName:                       文件名
         *
         *      @Return:
         *          vector<vector<SamplingData>>
         *                  图片的二维矩阵
         * */
        static std::vector<std::vector<SamplingData>> ReadImage(std::string fileName);

        /*
         * 将重建后的图片展示出来
         *
         *      @Param:
         *          reconstructionImage:            重建后的图片
         *
         *      @Return:
         *          vector<vector<SamplingData>>
         *                  图片的二维矩阵
         * */
        static void ShowReconstructionImage(std::vector<std::vector<SamplingData>> reconstructionImage);

        /*
         * 通过原始的采样点集得到图像
         *
         *      @Param:
         *          dataList:            点集
         *          imgSize:             图像大小
         *
         *
         * */
        static void SaveImageBySampleData(std::vector<SamplingData> dataList, int imgSize, std::string path);

        /*
         * 记录拟合过程中的信息
         *
         *      @Param:
         *          data:            点集
         *          path:            文件路径
         *
         *
         * */
        static void SaveFittingInfo(std::vector<FittingInfo> data,std::string path);

        /*
         * 记录拟合过程中的图像信息
         *
         *      @Param:
         *          dimageListata:       图像信息
         *          filePath:            文件路径
         *
         *
         * */
        static void SaveImage(std::vector<std::vector<std::vector<SamplingData>>> imageList,std::string path);

        /*
         * 写CSV
         *
         *      @Param:
         *          src:                 资源
         *          filePath:            文件路径
         *
         *
         * */
        static void WriteTiCSV(std::vector<std::vector<std::string>> src,std::string filePath);
    };
}


#endif //TRIANGLEDOMAIN_FILEUTIL_H
