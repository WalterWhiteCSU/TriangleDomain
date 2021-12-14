/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/16
 *
 *      @Descript:
 *          进行三角剖分的工具类
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_TRIANGULATIONUTIL_H
#define TRIANGLEDOMAIN_TRIANGULATIONUTIL_H

#include <vector>
#include "../Entity/SamplingData.h"
#include "../Entity/Triangle.h"
#include "../Entity/AreaCoordinateSamplingData.h"
#include "../Entity/DescartesCoordinateSamplingData.h"
#include "../Entity/FittingInfo.h"
#include "FittingUtil.h"
#include "ReconstructionUtil.h"

namespace TriangleDomain {
    class TriangulationUtil {
    public:
        /*
         * 面积坐标下的三角剖分拟合
         *      找到在三角形中的数据点，进行拟合后判断是否满足条件，不满足的情况下递归进行剖分
         *
         *      @Param:
         *          triangle:               三角形
         *          AreaCoordinateData:     需要进行筛选的数据集
         *          triangleNumber:         定位到的三角形编号
         *          fittingType:            拟合类型
         *          permitError:            允许的误差范围
         *
         *      @Return:
         *          vector<AreaCoordinateSamplingData *>
         *                 获得的在三角形中的数据
         *
         * */
        static std::vector<AreaCoordinateSamplingData *>
        AreaCoordinateSelectPoint(const Triangle triangle,
                                  std::vector<AreaCoordinateSamplingData *> &AreaCoordinateData,
                                  int triangleNumber, int fittingType, float permitError,
                                  std::vector<FittingInfo> &fittingInfoList);

        /*
         * 直角坐标下的三角剖分拟合
         *      找到在三角形中的数据点，进行拟合后判断是否满足条件，不满足的情况下递归进行剖分
         *
         *      @Param:
         *          triangle:                   三角形
         *          DescartesCoordinateData:    需要进行筛选的数据集
         *          triangleNumber:             定位到的三角形编号
         *          fittingType:                拟合类型
         *          permitError:                允许的误差范围
         *
         *      @Return:
         *          std::vector<DescartesCoordinateSamplingData *>
         *                 获得的在三角形中的数据
         *
         * */
        static std::vector<DescartesCoordinateSamplingData *>
        DescartesCoordinateSelectPoint(const Triangle triangle,
                                       std::vector<DescartesCoordinateSamplingData *> &DescartesCoordinateData,
                                       int triangleNumber, int fittingType, float permitError,std::vector<FittingInfo> &fittingInfoList);

        /*
         * 获得初始的三角形
         *  这里将图片划分为两个初始三角形
         *
         *      @Param:
         *          image:                  图片的数据
         *
         *      @Return:
         *          vector<Triangle>        三角形的集合
         * */
        static std::vector<Triangle>
        initialTriangulation(const std::vector<std::vector<SamplingData>> &image);

        /*
         * 将图像转换为携带面积坐标信息的数据
         *
         *      @Param:
         *          imageData:              图片数据
         *
         *      @Return:
         *          vector<AreaCoordinateSamplingData *>
         *              携带面积坐标的图片数据集合
         * */
        static std::vector<AreaCoordinateSamplingData *>
        ConvertImageToAreaCoordinate(const std::vector<std::vector<SamplingData>> &imageData);

        /*
         * 将图像转换为携带笛卡尔坐标信息的数据
         *
         *      @Param:
         *          imageData:              图片数据
         *
         *      @Return:
         *          vector<DescartesCoordinateSamplingData *>
         *              携带面积坐标的图片数据集合
         * */
        static std::vector<DescartesCoordinateSamplingData *>
        ConvertImageToDescartesCoordinate(const std::vector<std::vector<SamplingData>> &imageData);

        /*
         * 面积坐标下的三角剖分
         *
         *      @Param:
         *          image:                  图片数据
         *          fittingType:            拟合类型
         *          permitError:            允许误差
         *
         *      @Return:
         *          vector<vector<vector<SamplingData>>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static std::vector<std::vector<std::vector<SamplingData>>>
        AreaCoordinateTriangulation(const std::vector<std::vector<SamplingData>> &image, int fittingType,
                                    float permitError, std::vector<FittingInfo> &fittingInfoList);

        /*
         * 直角坐标下的三角剖分
         *
         *      @Param:
         *          image:                  图片数据
         *          fittingType:            拟合类型
         *          permitError:            允许误差
         *          fittingInfoList:        拟合信息
         *
         *      @Return:
         *          vector<vector<vector<SamplingData>>>
         *              携带剖分后的图像胡数据二维矩阵
         *
         * */
        static std::vector<std::vector<std::vector<SamplingData>>>
        DescartesCoordinatesTriangulation(const std::vector<std::vector<SamplingData>> &image, int fittingType,
                                          float permitError,std::vector<FittingInfo> &fittingInfoList);

        /*
         * 判断数据点是否在三角形边缘
         *
         *      @Param:
         *          triangle:               三角形
         *          point:                  数据点
         *
         *      @Return:
         *          bool
         *            是否在三角形边缘
         *
         * */
        static bool isNearEdge(const Triangle triangle, Point *point);
    };
}


#endif //TRIANGLEDOMAIN_TRIANGULATIONUTIL_H
