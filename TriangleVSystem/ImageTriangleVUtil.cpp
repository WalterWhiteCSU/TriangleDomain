/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                ImageTriangleVUtil.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/15
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "ImageTriangleVUtil.h"

namespace TriangleV {

    std::vector<std::vector<CalculateData *>>
    ImageTriangleVUtil::InitialTriangleSection(const std::vector<std::vector<TriangleDomain::SamplingData>> &image,
                                               std::vector<TriangleDomain::Triangle> &triangleList) {
        std::vector<std::vector<CalculateData *>> res;

        //  遍历整个图像，得到在初始三角形中的数据点
        std::vector<CalculateData *> model;
        for (auto triangle:triangleList) {
            for (auto row:image) {
                for (auto point:row) {
                    int flag = triangle.isPointInTriangle(point.getPoint());
                    if (flag >= 0) {
                        CalculateData *temp = new CalculateData(&point);
                        temp->SetAreaPoint(triangle);
                        model.push_back(temp);
                    }
                }
            }
            res.push_back(model);
            model.clear();
        }
        return res;
    }

    ImageQuadTree *ImageTriangleVUtil::ImageQuadTreeGenerator(std::vector<CalculateData *> &dataList,
                                                              TriangleDomain::Triangle &originTriangle) {
        ImageQuadTree *res = new ImageQuadTree();

        res->getAncestorImageQuadTreeByList(dataList, originTriangle);

        int layerCount = UniformImageSection(res->tree, 0, res->tree->triangle);

        res->layer = layerCount;

        return res;
    }

    int ImageTriangleVUtil::UniformImageSection(ImageQuadTreeNode *node, int layer,
                                                TriangleDomain::Triangle *originTriangle) {
        int totalLayer = -1;

        //  获得剖分的子三角形
        std::vector<TriangleDomain::Triangle> subTriangleList = node->triangle->triangleSection();

        //  对每个子三角形进行运算
        for (int i = 0; i < subTriangleList.size(); ++i) {
            //  得到包含在三角形中的数据
            std::vector<CalculateData *> includingData = GetIncludingDataBySubTriangle(node->dataList,
                                                                                       subTriangleList[i]);

            if (includingData.size() <= 36) {
                return layer;
            }
            //  生成新的节点
            auto *childNode = new ImageQuadTreeNode(includingData, &subTriangleList[i],
                                                    std::to_string(i + 1), layer + 1, node,*originTriangle);

            //  将新节点连接到四叉树上
            switch (i) {
                case 0:
                    node->child1 = childNode;
                    break;
                case 1:
                    node->child2 = childNode;
                    break;
                case 2:
                    node->child3 = childNode;
                    break;
                case 3:
                    node->child4 = childNode;
                    break;
            }

            //  继续剖分
            totalLayer = UniformImageSection(childNode, layer + 1,originTriangle);
        }

        return totalLayer;
    }

    std::vector<CalculateData *>
    ImageTriangleVUtil::GetIncludingDataBySubTriangle(std::vector<CalculateData *> &dataList,
                                                      TriangleDomain::Triangle &triangle) {
        std::vector<CalculateData *> res;

        for (auto data:dataList) {
            if (triangle.isPointInTriangle(data->data->getPoint()) >= 0) {
                res.push_back(data);
            }
        }

        return res;
    }

    std::vector<TriangleV::ImageQuadTree *> ImageTriangleVUtil::TriangleV(std::string filePath) {
        //  先打开文件，读取图像
        auto image = TriangleDomain::FileUtil::ReadImage(std::move(filePath));

        //  获得初始的三角形
        auto triangleList = TriangleDomain::TriangulationUtil::initialTriangulation(image);

        //  获得初始三角剖分下的数据
        auto triangleDataList = TriangleV::ImageTriangleVUtil::InitialTriangleSection(image, triangleList);

        std::vector<TriangleV::ImageQuadTree *> imageTreeList;

        for (int i = 0; i < triangleList.size(); ++i) {
            TriangleV::ImageQuadTree *model = TriangleV::ImageTriangleVUtil::ImageQuadTreeGenerator(triangleDataList[0],
                                                                                                    triangleList[0]);

            imageTreeList.push_back(model);
        }

        return imageTreeList;
    }
}

