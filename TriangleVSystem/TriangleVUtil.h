/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TriangleVUtil.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/15
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_TRIANGLEVUTIL_H
#define TRIANGLEDOMAIN_TRIANGLEVUTIL_H

#include <vector>
#include <cmath>
#include <iostream>
#include <time.h>

#include <Eigen/Dense>

#include "Tree/ImageQuadTree.h"
#include "Tree/CalculateData.h"

namespace TriangleV {
    class TriangleVUtil {
    public:
        /*
         * 三角域V系统拟合
         *
         *      @Param:
         *          imageQuadTree:                  图像四叉树
         *
         *      @Return:
         *          imageQuadTree                   返回的携带V系统参数的四叉树
         *
         * */
        static ImageQuadTree *TriangleVFitting(ImageQuadTree *imageQuadTree);

        /*
         * 得到三角域V系统的矩阵
         *
         *      @Param:
         *          totalData:                      所有的数据点
         *          nodeList:                       四叉树的所有的节点
         *
         *      @Return:
         *          Eigen::MatrixXf                 v系统的矩阵
         *
         * */
        static Eigen::MatrixXf
        GetVMatrix(std::vector<CalculateData *> &totalData, std::vector<ImageQuadTreeNode *> &nodeList, int totalLayer);

        /*
         * 三角域V系统第一项
         *
         *      @Param:
         *          data:                           数据点
         *          matrix:                         V矩阵
         *
         *      @Return:
         *          void                            空
         *
         * */
        static std::vector<std::vector<float>> FirstV(std::vector<CalculateData *> &data);

        /*
         * 三角域V系统生成元
         *
         *      @Param:
         *          data:                           数据点
         *          scale:                          比例
         *
         *      @Return:
         *          vector<vector<float>>           数据集合
         *
         * */
        static std::vector<std::vector<float>> GenerateV(std::vector<TriangleDomain::AreaPoint *> &data, int scale);

        /*   重载方法   */
        static std::vector<std::vector<float>> GenerateV(std::vector<CalculateData *> &data, int scale);

        /*
         * 得到单个数据点的生成元列表
         *
         *      @Param:
         *          data:                           数据点
         *          scale:                          比例
         *
         *      @Return:
         *          vector<float>                   数据集合
         *
         * */
        static std::vector<float> GetSingleDataGenerateV(TriangleDomain::AreaPoint *data, int scale);

        /*
         * 得到仿射变换后的面积坐标
         *
         *      @Param:
         *          node:                           节点
         *
         *      @Return:
         *          vector<AreaPoint>               变换后的仿射变换
         *
         * */
        static std::vector<TriangleDomain::AreaPoint *> GetAffineData(ImageQuadTreeNode *node);

        /*
         * 为三角域V矩阵赋值
         *
         *      @Param:
         *          vMatrix:                        v矩阵
         *          affineDataList:                 计算得到的函数值
         *          totalPointData:                 所有的数据点
         *          triangle:                       当前三角形
         *          scale:                          尺度
         *
         *      @Return:
         *          vector<AreaPoint>               变换后的仿射变换
         *
         * */
        static void
        SetMatrixValueByAffineList(Eigen::MatrixXf &vMatrix, std::vector<std::vector<float>> &paramDataList,
                                   std::vector<CalculateData *> &totalPointData,
                                   TriangleDomain::Triangle *triangle, int currentMatrixColCount);

        /*
         * 得到单个结点的拟合系数
         *      区间为左闭右开
         *
         *      @Param:
         *          coefficientVec:                 拟合系数向量
         *          startIndex:                     开始的拟合系数向量的索引
         *          endIndex:                       结束的拟合系数向量的索引
         *
         *      @Return:
         *          vector<float>                   拟合系数vector
         *
         * */
        static std::vector<float>
        GetParameterListForEachNode(Eigen::VectorXf &coefficientVec, int startIndex, int endIndex);
    };
}


#endif //TRIANGLEDOMAIN_TRIANGLEVUTIL_H
