/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                FittingInfo.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/12/6
  *Description:             每次拟合后的信息
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_FITTINGINFO_H
#define TRIANGLEDOMAIN_FITTINGINFO_H

#include <vector>
#include "Point.h"
#include "AreaPoint.h"
#include "AreaCoordinateSamplingData.h"
#include "DescartesCoordinateSamplingData.h"

namespace TriangleDomain {
    class FittingInfo {
    private:
        std::vector<Point> pointList;
        std::vector<AreaPoint> areaPointList;
        Triangle triangle;
        std::vector<float> fittingParam;
        std::vector<int> triangleLocation;
        float error;

    public:
        FittingInfo();

        FittingInfo(std::vector<AreaCoordinateSamplingData *> m_pointList, Triangle m_Triangle,
                    std::vector<float> m_FittingParam, std::vector<int> m_triangleLocation,float m_error);

        FittingInfo(std::vector<DescartesCoordinateSamplingData *> m_pointList, Triangle m_Triangle,
                    std::vector<float> m_FittingParam, std::vector<int> m_triangleLocation,float m_error);

        const std::vector<Point> &getPointList() const;

        void setPointList(const std::vector<Point> &pointList);

        const std::vector<AreaPoint> &getAreaPointList() const;

        void setAreaPointList(const std::vector<AreaPoint> &areaPointList);

        const Triangle &getTriangle() const;

        void setTriangle(const Triangle &triangle);

        const std::vector<float> &getFittingParam() const;

        void setFittingParam(const std::vector<float> &fittingParam);

        const std::vector<int> &getTriangleLocation() const;

        void setTriangleLocation(const std::vector<int> &triangleLocation);

        float getError() const;

        void setError(float error);

    };
}


#endif //TRIANGLEDOMAIN_FITTINGINFO_H
