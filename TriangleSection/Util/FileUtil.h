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
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "../Entity/SamplingData.h"
#include "../Entity/AreaCoordinateSamplingData.h"
#include "../Entity/DescartesCoordinateSamplingData.h"

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

    };
}


#endif //TRIANGLEDOMAIN_FILEUTIL_H
