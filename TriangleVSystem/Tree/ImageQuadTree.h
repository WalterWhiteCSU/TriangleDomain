/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageQuadTree.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_IMAGEQUADTREE_H
#define TRIANGLEDOMAIN_IMAGEQUADTREE_H

#include <queue>
#include "ImageQuadTreeNode.h"

namespace TriangleV {
    class ImageQuadTree {
    public:
        ImageQuadTreeNode *tree;

        ImageQuadTree();

        ~ImageQuadTree();

        /*   通过数据列表得到图像的四叉树   */
        ImageQuadTree &
        getAncestorImageQuadTreeByList(std::vector<CalculateData> dataList, TriangleDomain::Triangle triangle);

    private:
    };
}


#endif //TRIANGLEDOMAIN_IMAGEQUADTREE_H
