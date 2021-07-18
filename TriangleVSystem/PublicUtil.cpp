/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                PublicUtil.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/17
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "PublicUtil.h"

namespace TriangleV {
    TriangleDomain::AreaPoint *PublicUtil::GetAreaCoordinateByTriangle(const TriangleDomain::Triangle &triangle,
                                                                       TriangleDomain::Point &point) {
        float overallArea = triangle.GetTriangleArea();
        TriangleDomain::Triangle triangle_u(&point, triangle.getVertexB(), triangle.getVertexC());
        TriangleDomain::Triangle triangle_v(&point, triangle.getVertexC(), triangle.getVertexA());
        TriangleDomain::Triangle triangle_w(&point, triangle.getVertexA(), triangle.getVertexB());
        float u_area = triangle_u.GetTriangleArea() / overallArea;
        float v_area = triangle_v.GetTriangleArea() / overallArea;
        float w_area = triangle_w.GetTriangleArea() / overallArea;

        return new TriangleDomain::AreaPoint(u_area, v_area, w_area);
    }
}