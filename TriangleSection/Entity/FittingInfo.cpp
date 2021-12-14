/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                FittingInfo.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/12/6
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "FittingInfo.h"

TriangleDomain::FittingInfo::FittingInfo() {

}

TriangleDomain::FittingInfo::FittingInfo(const std::vector<AreaCoordinateSamplingData *> m_pointList,
                                         const Triangle m_Triangle,
                                         const std::vector<float> m_FittingParam,
                                         const std::vector<int> m_triangleLocation,
                                         const float m_error) : triangle{m_Triangle}, fittingParam{m_FittingParam},
                                                                triangleLocation{m_triangleLocation}, error{m_error} {
    for (auto model:m_pointList) {
        Point pointModel(*model->getPoint());
        pointList.push_back(pointModel);
        AreaPoint areaPointModel(*model->getAreaPoint());
        areaPointList.push_back(areaPointModel);
    }
}

TriangleDomain::FittingInfo::FittingInfo(std::vector<DescartesCoordinateSamplingData *> m_pointList,
                                         TriangleDomain::Triangle m_Triangle, std::vector<float> m_FittingParam,
                                         std::vector<int> m_triangleLocation, float m_error) : triangle{m_Triangle},
                                                                                               fittingParam{m_FittingParam},
                                                                                               triangleLocation{m_triangleLocation},
                                                                                               error{m_error} {
    for (auto model:m_pointList) {
        Point pointModel(*model->getPoint());
        pointList.push_back(pointModel);
    }
}
