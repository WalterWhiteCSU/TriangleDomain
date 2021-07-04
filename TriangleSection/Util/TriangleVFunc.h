/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/24
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          三角域V系统
 *
 ***************************************************************
 * */


#ifndef TRIANGLEDOMAIN_TRIANGLEVFUNC_H
#define TRIANGLEDOMAIN_TRIANGLEVFUNC_H

#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include "../Entity/AreaPoint.h"
#include "../Entity/AreaCoordinateTriangle.h"

namespace TriangleDomain {

    class TriangleVFunc {
        /*
        * 计算得到三角域v矩阵
        *
        *      @Param:
        *          image:                  原始数据
        *          n:                      v系统的组数
        *
        *      @Return:
        *          float:                  拟合误差
        *
        * */
        static Eigen::MatrixXf TriangleV_matrix(const std::vector<AreaPoint *> &image, int n);

        /*
        * 三角域v系统的第一组
        *
        *      @Param:
        *          image:                  原始数据
        *          n:                      v系统的组数
        *          matrix:                 系数矩阵
        *
        *      @Return:
        *          float:                  拟合误差
        *
        * */
        static void FirstV(const std::vector<AreaPoint *> &image, int n, Eigen::MatrixXf &matrix);

        /*
        * 三角域v系统的第二组生成元
        *
        *      @Param:
        *          image:                  原始数据
        *          n:                      v系统的组数
        *          scale:                  尺度系数
        *          matrix:                 系数矩阵
        *          startRow:               开始位置
        *          endRow:                 结束位置
        *
        *      @Return:
        *          float:                  拟合误差
        *
        * */
        static void
        GenerateV(const std::vector<AreaPoint *> &image, float scale, Eigen::MatrixXf &matrix);

        /*
        * 三角域v系统的其他组
        *       由生成元生成
        *
        *      @Param:
        *          image:                  原始数据
        *          matrix:                 系数矩阵
        *          groupCount:             组数
        *
        *      @Return:
        *
        *
        * */
        static void AddV(const std::vector<AreaPoint *> &image, Eigen::MatrixXf &matrix, int groupCount);

        /*
        * 求解第三组之后的矩阵
        *
        *      @Param:
        *          image:                  原始数据
        *          matrix:                 系数矩阵
        *          triangle:               三角形
        *          currentGroup:           当前组数
        *          groupCount:             总组数
        *
        *      @Return:
        *
        *
        * */
        static void
        SetVmatrix(const std::vector<AreaPoint *> image, Eigen::MatrixXf matrix, AreaCoordinateTriangle triangle,
                   int currentGroup, int groupCount);

        /*
        * 通过原先的三角形得到三角剖分后的新的三角形
        *       由生成元生成
        *
        *      @Param:
        *          originTriangle:         原先的三角形
        *
        *      @Return:
         *          vector<AreaCoordinateTriangle> 三角剖分后的三角形list
        *
        *
        * */
        static std::vector<AreaCoordinateTriangle> GetSubTriangle(AreaCoordinateTriangle originTriangle);
    };
}


#endif //TRIANGLEDOMAIN_TRIANGLEVFUNC_H
