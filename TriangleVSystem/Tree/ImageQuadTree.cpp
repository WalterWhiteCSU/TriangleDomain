/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageQuadTree.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "ImageQuadTree.h"

namespace TriangleV {


    ImageQuadTree::ImageQuadTree() {
        this->tree = new ImageQuadTreeNode();
    }

    ImageQuadTree &
    ImageQuadTree::getAncestorImageQuadTreeByList(std::vector<CalculateData> dataList,
                                                  TriangleDomain::Triangle triangle) {
        delete this->tree;

        //  树的祖先节点
        this->tree = new ImageQuadTreeNode(dataList, &triangle, "0", 0);

        return *this;
    }

    ImageQuadTree::~ImageQuadTree() {
        std::queue<ImageQuadTreeNode *> nodeQueue;

        nodeQueue.push(this->tree);

        while (!nodeQueue.empty()) {
            ImageQuadTreeNode *model = nodeQueue.front();
            if (model->child1 != nullptr) {
                nodeQueue.push(model->child1);
            }
            if (model->child2 != nullptr) {
                nodeQueue.push(model->child2);
            }
            if (model->child3 != nullptr) {
                nodeQueue.push(model->child3);
            }
            if (model->child4 != nullptr) {
                nodeQueue.push(model->child4);
            }
            nodeQueue.pop();
            delete model;
        }
    }
}
