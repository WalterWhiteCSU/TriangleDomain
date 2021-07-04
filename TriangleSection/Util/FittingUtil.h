/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          进行数据拟合的工具类
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_FITTINGUTIL_H
#define TRIANGLEDOMAIN_FITTINGUTIL_H

#include "../Entity/AreaCoordinateSamplingData.h"
#include "../Entity/DescartesCoordinateSamplingData.h"
#include <Eigen/Dense>
#include <iostream>

namespace TriangleDomain {
    class FittingUtil {
    public:
        /*
         * 面积坐标拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingType:            拟合类型
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        AreaCoordinateFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data, int fittingType,
                              std::vector<float> &fittingPara);

        /*
         * 直角坐标拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingType:            拟合类型
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        DescartesCoordinateFitting(std::vector<DescartesCoordinateSamplingData *> &sampling_data, int fittingType,
                                   std::vector<float> &fittingPara);

        /*
         * 面积坐标一次拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        AreaCoordinateLinearFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data,
                                    std::vector<float> &fittingPara);

        /*
         * 直角坐标一次拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        DescartesCoordinateLinearFitting(std::vector<DescartesCoordinateSamplingData *> &sampling_data,
                                         std::vector<float> &fittingPara);

        /*
         * 面积坐标二次拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        AreaCoordinateQuadraticFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data,
                                       std::vector<float> &fittingPara);

        /*
         * 直角坐标二次拟合
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          fittingPara:            拟合参数
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        DescartesCoordinateQuadraticFitting(std::vector<DescartesCoordinateSamplingData *> &sampling_data,
                                            std::vector<float> &fittingPara);

        /*
         * 面积坐标一次拟合的函数
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合值
         *
         * */
        static float
        AreaCoordinateLinearFunction(std::vector<float> &parameterList, AreaPoint &areaPoint);

        /*
         * 直角坐标一次拟合的函数
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合值
         *
         * */
        static float
        DescartesCoordinateLinearFunction(std::vector<float> &parameterList, Point &point);

        /*
         * 面积坐标二次拟合的函数
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合值
         *
         * */
        static float
        AreaCoordinateQuadraticFunction(std::vector<float> &parameterList, AreaPoint &areaPoint);

        /*
         * 直角坐标二次拟合的函数
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合值
         *
         * */
        static float
        DescartesCoordinateQuadraticFunction(std::vector<float> &parameterList, Point &point);


        /*
         * 面积坐标拟合的误差
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        AreaCoordinateMES(std::vector<float> &parameterList, std::vector<AreaCoordinateSamplingData *> &areaPointList,
                          int fittingType);

        /*
         * 直角坐标拟合的误差
         *
         *      @Param:
         *          sampling_data:          拟合的数据
         *          areaPoint:              拟合点
         *
         *      @Return:
         *          float:                  拟合误差
         *
         * */
        static float
        DescartesCoordinateMES(std::vector<float> &parameterList,
                               std::vector<DescartesCoordinateSamplingData *> &PointList,
                               int fittingType);

    };
}


#endif //TRIANGLEDOMAIN_FITTINGUTIL_H
