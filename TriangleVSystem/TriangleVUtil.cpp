/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TriangleVUtil.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "TriangleVUtil.h"

namespace TriangleV {

    std::vector<std::vector<CalculateData>>
    TriangleVUtil::InitialTriangleSection(const std::vector<std::vector<TriangleDomain::SamplingData>> &image,
                                          std::vector<TriangleDomain::Triangle> triangleList) {
        std::vector<std::vector<CalculateData>> res;

        //  得到初始的三角形
//        auto initialTriangleList = TriangleDomain::TriangulationUtil::initialTriangulation(image);

        //  遍历整个图像，得到在初始三角形中的数据点
        std::vector<CalculateData> model;
        for (auto triangle:triangleList) {
            for (auto row:image) {
                for (auto point:row) {
                    int flag = triangle.isPointInTriangle(point.getPoint());
                    if (flag >= 0) {
                        CalculateData temp(&point);
                        temp.SetAreaPoint(triangle);
                        model.push_back(temp);
                    }
                }
            }
            res.push_back(model);
            model.clear();
        }
        return res;
    }

    ImageQuadTree TriangleVUtil::ImageQuadTreeGenerator(std::vector<CalculateData> dataList,
                                                        TriangleDomain::Triangle originTriangle) {
        ImageQuadTree res;

        res.getAncestorImageQuadTreeByList(dataList, originTriangle);

        int layerCount = UniformImageSection(res.tree, 0);

        return res;
    }

    int TriangleVUtil::UniformImageSection(ImageQuadTreeNode *node, int layer) {
        int totalLayer;

        //  获得剖分的子三角形
        std::vector<TriangleDomain::Triangle> subTriangleList = node->triangle->triangleSection();

        //  对每个子三角形进行运算
        for (int i = 0; i < subTriangleList.size(); ++i) {
            //  得到包含在三角形中的数据
            std::vector<CalculateData> includingData = GetIncludingDataBySubTriangle(node->dataList,
                                                                                     subTriangleList[i]);
            if (includingData.size() <= 10) {
                return layer;
            }
            //  生成新的节点
            ImageQuadTreeNode *childNode = new ImageQuadTreeNode(includingData, &subTriangleList[i],
                                                                 std::to_string(i + 1), layer + 1, node);

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
            totalLayer = UniformImageSection(childNode, layer + 1);
        }

        return totalLayer;
    }

    std::vector<CalculateData> TriangleVUtil::GetIncludingDataBySubTriangle(std::vector<CalculateData> dataList,
                                                                            TriangleDomain::Triangle triangle) {
        std::vector<CalculateData> res;

        for (auto data:dataList) {
            if (triangle.isPointInTriangle(data.data->getPoint()) >= 0) {
                res.push_back(data);
            }
        }

        return res;
    }

}