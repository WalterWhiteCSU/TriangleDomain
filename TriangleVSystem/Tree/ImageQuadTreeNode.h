/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageQuadTreeNode.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:             所分四叉树的节点
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_IMAGEQUADTREENODE_H
#define TRIANGLEDOMAIN_IMAGEQUADTREENODE_H

#include <vector>
#include "../../include/SamplingData.h"
#include "../../include/AreaPoint.h"
#include "../../include/Triangle.h"
#include "CalculateData.h"

namespace TriangleV {

    class ImageQuadTreeNode {
    public:
        //  数据列表
        std::vector<CalculateData> dataList;
        //  三角形
        TriangleDomain::Triangle *triangle;
        //  节点编号
        std::string id;
        //  层级
        int layer;
        //  每个三角形的参数（拟合系数）
        std::vector<float> parameterList;

        //  孩子节点
        ImageQuadTreeNode *child1;
        ImageQuadTreeNode *child2;
        ImageQuadTreeNode *child3;
        ImageQuadTreeNode *child4;

        //  父亲节点
        ImageQuadTreeNode *parent;

        ImageQuadTreeNode();

        ImageQuadTreeNode(const std::vector<CalculateData> &dataList, TriangleDomain::Triangle *triangle,
                          const std::string &id, int layer);

        ImageQuadTreeNode(const std::vector<CalculateData> &dataList, TriangleDomain::Triangle *triangle,
                          const std::string &id, int layer, ImageQuadTreeNode *parent);

        ImageQuadTreeNode(const std::vector<CalculateData> &dataList, TriangleDomain::Triangle *triangle,
                          const std::string &id, int layer, ImageQuadTreeNode *child1, ImageQuadTreeNode *child2,
                          ImageQuadTreeNode *child3, ImageQuadTreeNode *child4, ImageQuadTreeNode *parent,
                          std::vector<float> &parameterList);

        /*  Warning: DO NOT USE IT!!!!  */
        ImageQuadTreeNode(const ImageQuadTreeNode &rhs);

        ~ImageQuadTreeNode();

        /*  Warning: DO NOT USE IT!!!!  */
        ImageQuadTreeNode &operator=(const ImageQuadTreeNode &rhs);
    };
}


#endif //TRIANGLEDOMAIN_IMAGEQUADTREENODE_H
