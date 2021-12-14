/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                TestService.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/22
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_TESTSERVICE_H
#define TRIANGLEDOMAIN_TESTSERVICE_H

#include <vector>

#include "include/ImageQuadTree.h"
#include "include/ImageTriangleVUtil.h"
#include "include/TriangleVUtil.h"
#include "include/Triangle.h"
#include "include/AreaPoint.h"
#include "include/SamplingData.h"

namespace TriangleV {
    class TestService {
    public:
        /*
         * 对三角域V系统生成图像四叉树进行测试
         *
         *      @Param:
         *
         *      @Return:
         *          vector<vector<ImageQuadTree>>       图像四叉树
         *
         *
         * */
        static std::vector<ImageQuadTree *> ImageQuadTreeFittingTest(std::string imagePath);

        /*
         * 对第一组三角域v系统进行测试
         *
         *      @Param:
         *
         *      @Return:
         *          vector<vector<vector<float>>       图像矩阵
         *
         *
         * */
        static std::vector<std::vector<TriangleDomain::SamplingData>> FirstGroupOfTriangleVTest();

        /*
         * 重建图像
         *
         *      @Param:
         *
         *      @Return:
         *          std::vector<ImageQuadTree *>       拟合得到的四叉树
         *
         *
         * */
        static void ShowRecontructedImage(std::string imagePath, std::vector<ImageQuadTree *> imageTree);
    };
}


#endif //TRIANGLEDOMAIN_TESTSERVICE_H
