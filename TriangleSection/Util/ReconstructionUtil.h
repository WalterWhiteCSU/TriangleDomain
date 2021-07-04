/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/19
 *      @Last Modified Date:    2021/6/19
 *
 *      @Descript:
 *          图像重建的工具类
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_RECONSTRUCTIONUTIL_H
#define TRIANGLEDOMAIN_RECONSTRUCTIONUTIL_H

#include <vector>
#include "../Entity/SamplingData.h"
#include "../Entity/AreaCoordinateSamplingData.h"
#include "FittingUtil.h"

namespace TriangleDomain {
    class ReconstructionUtil {
    public:
        /*
         * 将面积坐标下的拟合数据复原为图像的二维矩阵
         *
         *      @Param:
         *          calculateData:  计算得到的数据
         *          row:            图像的行
         *          col:            图像的列
         *
         *      @Return:
         *          std::vector<std::vector<SamplingData>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static std::vector<std::vector<std::vector<SamplingData>>>
        ConvertAreaCoordinateCalculateDataToImageData(std::vector<AreaCoordinateSamplingData *> &calculateData, int row,
                                                      int col, int fittingType);

        /*
         * 将直角坐标下的拟合数据复原为图像的二维矩阵
         *
         *      @Param:
         *          calculateData:  计算得到的数据
         *          row:            图像的行
         *          col:            图像的列
         *
         *      @Return:
         *          std::vector<std::vector<SamplingData>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static std::vector<std::vector<std::vector<SamplingData>>>
        ConvertDescartesCoordinateCalculateDataToImageData(
                std::vector<DescartesCoordinateSamplingData *> &calculateData, int row, int col, int fittingType);

        /*
         * 面积坐标下计算单个数据的拟合值
         *
         *      @Param:
         *          areaPoint:              面积坐标
         *          fitting_para:           拟合参数
         *          fittingType:            拟合类型
         *
         *      @Return:
         *          std::vector<std::vector<SamplingData>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static float AreaCoordinateFittingValue(AreaPoint *areaPoint, std::vector<float> fitting_para, int fittingType);

        /*
         * 面积坐标下计算单个数据的拟合值
         *
         *      @Param:
         *          point:              数据值
         *          fitting_para:       拟合参数
         *          fittingType:        拟合类型
         *
         *      @Return:
         *          std::vector<std::vector<SamplingData>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static float DescartesCoordinateFittingValue(Point *point, std::vector<float> fitting_para, int fittingType);

        /*
         * 图像的PSNR
         *
         *      @Param:
         *          oringinImage:            原始图像
         *          recontructedImage:       重建参数
         *
         *      @Return:
         *          float
         *              PSNR的值
         *
         * */
        static float ImagePSNR(std::vector<std::vector<SamplingData>> oringinImage,
                               std::vector<std::vector<SamplingData>> recontructedImage);
    };
}


#endif //TRIANGLEDOMAIN_RECONSTRUCTIONUTIL_H
