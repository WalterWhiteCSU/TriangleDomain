/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageTriangleVUtil.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/15
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_IMAGETRIANGLEVUTIL_H
#define TRIANGLEDOMAIN_IMAGETRIANGLEVUTIL_H

#include <vector>
#include <string>
#include "../include/SamplingData.h"
#include "../include/TriangulationUtil.h"
#include "../include/AreaPoint.h"
#include "../include/FileUtil.h"

#include "Tree/CalculateData.h"
#include "Tree/ImageQuadTree.h"

namespace TriangleV {
    class ImageTriangleVUtil {
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
        static std::vector<std::vector<CalculateData *>>
        InitialTriangleSection(const std::vector<std::vector<TriangleDomain::SamplingData>> &image,
                               std::vector<TriangleDomain::Triangle> &triangleList);

        /*
         * 图像四叉树生成
         *
         *      @Param:
         *          image:                          图像的二维矩阵
         *          triangleList:                   初始三角形List
         *          layer:                          层数
         *
         *      @Return:
         *          vector<vector<SamplingData>>    每个三角形中的结果
         *
         * */
        static ImageQuadTree *
        ImageQuadTreeGenerator(std::vector<CalculateData *> &dataList, TriangleDomain::Triangle &originTriangle);

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
        static int UniformImageSection(ImageQuadTreeNode *node, int layer, TriangleDomain::Triangle *originTriangle);


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
        static std::vector<CalculateData *>
        GetIncludingDataBySubTriangle(std::vector<CalculateData *> &dataList, TriangleDomain::Triangle &triangle);

        /*
         * 三角域V系统图像处理
         *
         *      @Param:
         *          filePath:                       文件路径
         *
         *      @Return:
         *          ImageQuadTree                   图像
         *
         * */
        static std::vector<TriangleV::ImageQuadTree *> TriangleV(std::string filePath);
    };
}


#endif //TRIANGLEDOMAIN_IMAGETRIANGLEVUTIL_H
