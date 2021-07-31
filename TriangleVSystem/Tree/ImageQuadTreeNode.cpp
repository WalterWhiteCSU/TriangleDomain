/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageQuadTreeNode.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "ImageQuadTreeNode.h"

namespace TriangleV {

    ImageQuadTreeNode::ImageQuadTreeNode() {
        this->triangle = nullptr;
        this->child1 = nullptr;
        this->child2 = nullptr;
        this->child3 = nullptr;
        this->child4 = nullptr;
        this->parent = nullptr;
    }


    ImageQuadTreeNode::ImageQuadTreeNode(const std::vector<CalculateData *> &dataList,
                                         TriangleDomain::Triangle *triangle,
                                         const std::string &id, int layer) {
        this->dataList = dataList;
        this->triangle = new TriangleDomain::Triangle(*triangle);
        this->id = id;
        this->layer = layer;

        this->parent = nullptr;

        this->child1 = nullptr;
        this->child2 = nullptr;
        this->child3 = nullptr;
        this->child4 = nullptr;

        SetTriangleAreaCoordinate(*triangle);

        this->isLeafNode = false;
    }

    ImageQuadTreeNode::ImageQuadTreeNode(const std::vector<CalculateData *> &dataList,
                                         TriangleDomain::Triangle *triangle,
                                         const std::string &id, int layer, ImageQuadTreeNode *parent,
                                         TriangleDomain::Triangle &originTriangle) {
        this->dataList = dataList;
        this->triangle = new TriangleDomain::Triangle(*triangle);
        this->id = id;
        this->layer = layer;

        this->parent = parent;

        this->child1 = nullptr;
        this->child2 = nullptr;
        this->child3 = nullptr;
        this->child4 = nullptr;

        SetTriangleAreaCoordinate(originTriangle);

        this->isLeafNode = false;
    }

    ImageQuadTreeNode::ImageQuadTreeNode(const std::vector<CalculateData *> &dataList,
                                         TriangleDomain::Triangle *triangle,
                                         const std::string &id, int layer, ImageQuadTreeNode *child1,
                                         ImageQuadTreeNode *child2, ImageQuadTreeNode *child3,
                                         ImageQuadTreeNode *child4, ImageQuadTreeNode *parent,
                                         std::vector<float> &parameterList) : dataList(dataList),
                                                                              triangle(triangle),
                                                                              id(id), layer(layer),
                                                                              child1(child1),
                                                                              child2(child2),
                                                                              child3(child3),
                                                                              child4(child4),
                                                                              parent(parent),
                                                                              parameterList(parameterList) {}

    ImageQuadTreeNode::ImageQuadTreeNode(const ImageQuadTreeNode &rhs) {
        this->dataList = rhs.dataList;
        this->triangle = new TriangleDomain::Triangle(*rhs.triangle);
        this->id = rhs.id;
        this->layer = rhs.layer;
        this->child1 = rhs.child1;
        this->child2 = rhs.child2;
        this->child3 = rhs.child3;
        this->child4 = rhs.child4;
        this->parent = rhs.parent;
        this->isLeafNode = rhs.isLeafNode;
    }

    ImageQuadTreeNode::~ImageQuadTreeNode() {
        delete this->triangle;

        this->child1 = nullptr;
        this->child2 = nullptr;
        this->child3 = nullptr;
        this->child4 = nullptr;
    }

    ImageQuadTreeNode &ImageQuadTreeNode::operator=(const ImageQuadTreeNode &rhs) {
        if (this != &rhs) {
            this->dataList = rhs.dataList;
            this->triangle = new TriangleDomain::Triangle(*rhs.triangle);
            this->id = rhs.id;
            this->layer = rhs.layer;
            this->child1 = rhs.child1;
            this->child2 = rhs.child2;
            this->child3 = rhs.child3;
            this->child4 = rhs.child4;
            this->parent = rhs.parent;
            this->isLeafNode = rhs.isLeafNode;
        }

        return *this;
    }

    void ImageQuadTreeNode::SetTriangleAreaCoordinate(const TriangleDomain::Triangle &originTriangle) {
        this->triangleAreaPoint.clear();

        auto a = PublicUtil::GetAreaCoordinateByTriangle(originTriangle, *this->triangle->getVertexA());
        auto b = PublicUtil::GetAreaCoordinateByTriangle(originTriangle, *this->triangle->getVertexB());
        auto c = PublicUtil::GetAreaCoordinateByTriangle(originTriangle, *this->triangle->getVertexC());
        this->triangleAreaPoint.push_back(a);
        this->triangleAreaPoint.push_back(b);
        this->triangleAreaPoint.push_back(c);
    }


}
