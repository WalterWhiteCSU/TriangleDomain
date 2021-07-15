/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/9
 *
 *      @Descript:
 *          面积坐标下的采样点
 *          data:           图像数据信息
 *          areaPoint:      面积坐标信息
 *          location:       三角剖分的信息，本质上为一个四进制数
 *          fitting_para:   拟合参数
 *          triangle:       数据点所属三角形
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_AREACOORDINATESAMPLINGDATA_H
#define TRIANGLEDOMAIN_AREACOORDINATESAMPLINGDATA_H

#include <vector>
#include <ostream>
#include "SamplingData.h"
#include "Triangle.h"
#include "AreaPoint.h"

namespace TriangleDomain {

    class AreaCoordinateSamplingData : public SamplingData {
    private:
        AreaPoint *areaPoint;
        std::vector<int> location;
        std::vector<float> fitting_para;
        Triangle *triangle;
    public:
        AreaCoordinateSamplingData();

        AreaCoordinateSamplingData(Point *point, float value);

        AreaCoordinateSamplingData(const SamplingData &rhs);

        AreaCoordinateSamplingData(const SamplingData &rhs, AreaPoint *areaPoint, std::vector<int> location,
                                   std::vector<float> fittingPara, Triangle *triangle);

        AreaCoordinateSamplingData(const AreaCoordinateSamplingData &rhs);

        virtual ~AreaCoordinateSamplingData();

        AreaPoint *getAreaPoint() const;

        void setAreaPoint(AreaPoint *areaPoint);

        void setAreaPoint(const Triangle &triangle);

        const std::vector<int> &getLocation() const;

        void setLocation(const std::vector<int> &location);

        void setSingleDataToLocation(const int data);

        const std::vector<float> &getFittingPara() const;

        void setFittingPara(const std::vector<float> &fittingPara);

        Triangle *getTriangle() const;

        void setTriangle(Triangle *triangle);

        bool operator==(const AreaCoordinateSamplingData &rhs) const;

        bool operator!=(const AreaCoordinateSamplingData &rhs) const;

        bool operator<(const AreaCoordinateSamplingData &rhs) const;

        bool operator>(const AreaCoordinateSamplingData &rhs) const;

        bool operator<=(const AreaCoordinateSamplingData &rhs) const;

        bool operator>=(const AreaCoordinateSamplingData &rhs) const;

        AreaCoordinateSamplingData &operator=(const AreaCoordinateSamplingData &rhs);

        friend std::ostream &operator<<(std::ostream &os, const AreaCoordinateSamplingData &data) {
            os << static_cast<const SamplingData &>(data) << " areaPoint: " << data.areaPoint << " location: ";
            for (int model:data.location) {
                os << model;
            }
            os << " fitting_para: ";
            for (float model:data.fitting_para) {
                os << model << "    ";
            }
            os << " triangle: " << data.triangle;
            return os;
        }

        void QuantifyParameter(int max, int min);
    };
}


#endif //TRIANGLEDOMAIN_AREACOORDINATESAMPLINGDATA_H
