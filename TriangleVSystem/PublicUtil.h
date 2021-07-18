/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                PublicUtil.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/17
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_PUBLICUTIL_H
#define TRIANGLEDOMAIN_PUBLICUTIL_H

#include "../include/AreaPoint.h"
#include "../include/Triangle.h"

namespace TriangleV {
    class PublicUtil {
    public:
        /*
         * 通过三角形和数据点坐标得到面积坐标
         *
         *      @Param:
         *          triangle:                       三角形
         *          point:                          数据点坐标
         *
         *      @Return:
         *          vector<AreaPoint>               变换后的仿射变换
         *
         * */
        static TriangleDomain::AreaPoint *
        GetAreaCoordinateByTriangle(const TriangleDomain::Triangle &triangle, TriangleDomain::Point &point);
    };
}

#endif //TRIANGLEDOMAIN_PUBLICUTIL_H
