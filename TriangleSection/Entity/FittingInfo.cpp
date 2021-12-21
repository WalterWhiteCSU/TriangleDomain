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

const std::vector<TriangleDomain::Point> &TriangleDomain::FittingInfo::getPointList() const {
    return pointList;
}

void TriangleDomain::FittingInfo::setPointList(const std::vector<Point> &pointList) {
    FittingInfo::pointList = pointList;
}

const std::vector<TriangleDomain::AreaPoint> &TriangleDomain::FittingInfo::getAreaPointList() const {
    return areaPointList;
}

void TriangleDomain::FittingInfo::setAreaPointList(const std::vector<AreaPoint> &areaPointList) {
    FittingInfo::areaPointList = areaPointList;
}

const TriangleDomain::Triangle &TriangleDomain::FittingInfo::getTriangle() const {
    return triangle;
}

void TriangleDomain::FittingInfo::setTriangle(const TriangleDomain::Triangle &triangle) {
    FittingInfo::triangle = triangle;
}

const std::vector<float> &TriangleDomain::FittingInfo::getFittingParam() const {
    return fittingParam;
}

void TriangleDomain::FittingInfo::setFittingParam(const std::vector<float> &fittingParam) {
    FittingInfo::fittingParam = fittingParam;
}

const std::vector<int> &TriangleDomain::FittingInfo::getTriangleLocation() const {
    return triangleLocation;
}

void TriangleDomain::FittingInfo::setTriangleLocation(const std::vector<int> &triangleLocation) {
    FittingInfo::triangleLocation = triangleLocation;
}

float TriangleDomain::FittingInfo::getError() const {
    return error;
}

void TriangleDomain::FittingInfo::setError(float error) {
    FittingInfo::error = error;
}
