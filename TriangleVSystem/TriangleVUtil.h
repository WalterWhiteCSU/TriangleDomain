/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TriangleVUtil.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_TRIANGLEVUTIL_H
#define TRIANGLEDOMAIN_TRIANGLEVUTIL_H

#include <vector>
#include <string>
#include "../include/SamplingData.h"
#include "../include/TriangulationUtil.h"
#include "../include/AreaPoint.h"

#include "Tree/CalculateData.h"
#include "Tree/ImageQuadTree.h"

namespace TriangleV {
    class TriangleVUtil {
    public:
        /*
         * 初始三角剖分，将图像中的点放入每个三角形中
         *
         *      @Param:
         *          image:                          图像的二维矩阵
         *          triangleList:                   初始三角形List
         *
         *      @Return:
         *          vector<vector<SamplingData>>    每个三角形中的结果
         *
         * */
        static std::vector<std::vector<CalculateData>>
        InitialTriangleSection(const std::vector<std::vector<TriangleDomain::SamplingData>> &image,
                               std::vector<TriangleDomain::Triangle> triangleList);

        /*
         * 图像四叉树生成
         *
         *      @Param:
         *          image:                          图像的二维矩阵
         *          triangleList:                   初始三角形List
         *
         *      @Return:
         *          vector<vector<SamplingData>>    每个三角形中的结果
         *
         * */
        static ImageQuadTree
        ImageQuadTreeGenerator(std::vector<CalculateData> dataList, TriangleDomain::Triangle originTriangle);

        /*
         * 图像四叉树生成
         *
         *      @Param:
         *          image:                          图像的二维矩阵
         *          triangleList:                   初始三角形List
         *
         *      @Return:
         *          vector<vector<SamplingData>>    每个三角形中的结果
         *
         * */
        static int UniformImageSection(ImageQuadTreeNode *node, int layer);


        /*
         * 得到在三角形中的数据点
         *
         *      @Param:
         *          dataList:                       在上一个三角形中的点
         *          triangle:                       子三角形
         *
         *      @Return:
         *          vector<CalculateData>           在三角形中的点列表
         *
         * */
        static std::vector<CalculateData>
        GetIncludingDataBySubTriangle(std::vector<CalculateData> dataList, TriangleDomain::Triangle triangle);
    };
}


#endif //TRIANGLEDOMAIN_TRIANGLEVUTIL_H
