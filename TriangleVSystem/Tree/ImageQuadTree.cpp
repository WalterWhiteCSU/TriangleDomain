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
    ImageQuadTree::getAncestorImageQuadTreeByList(std::vector<CalculateData *> dataList,
                                                  TriangleDomain::Triangle triangle) {
        delete this->tree;
        tree = nullptr;

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
                model->child1->parent = nullptr;
                nodeQueue.push(model->child1);
            }
            if (model->child2 != nullptr) {
                model->child2->parent = nullptr;
                nodeQueue.push(model->child2);
            }
            if (model->child3 != nullptr) {
                model->child3->parent = nullptr;
                nodeQueue.push(model->child3);
            }
            if (model->child4 != nullptr) {
                model->child4->parent = nullptr;
                nodeQueue.push(model->child4);
            }
            nodeQueue.pop();
            delete model;
        }
    }

    std::vector<ImageQuadTreeNode *> ImageQuadTree::levelOrder() {
        std::vector<ImageQuadTreeNode *> res;

        std::queue<ImageQuadTreeNode *> nodeQueue;
        nodeQueue.push(this->tree);
        while (!nodeQueue.empty()) {
            ImageQuadTreeNode *model = nodeQueue.front();
            res.push_back(model);

            if (model->child1 != nullptr && !model->child1->isLeafNode) {
                nodeQueue.push(model->child1);
            }
            if (model->child2 != nullptr && !model->child2->isLeafNode) {
                nodeQueue.push(model->child2);
            }
            if (model->child3 != nullptr && !model->child3->isLeafNode) {
                nodeQueue.push(model->child3);
            }
            if (model->child4 != nullptr && !model->child4->isLeafNode) {
                nodeQueue.push(model->child4);
            }

            nodeQueue.pop();
        }

        return res;
    }
}
