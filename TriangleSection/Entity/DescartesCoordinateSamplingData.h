/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          笛卡尔坐标系下的采样点
 *          data:           图像数据信息
 *          location:       三角剖分的信息，本质上为一个四进制数
 *          fitting_para:   拟合参数
 *          triangle:       数据点所属三角形
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_DESCARTESCOORDINATESAMPLINGDATA_H
#define TRIANGLEDOMAIN_DESCARTESCOORDINATESAMPLINGDATA_H

#include <vector>
#include <ostream>
#include "SamplingData.h"
#include "Triangle.h"

namespace TriangleDomain {

    class DescartesCoordinateSamplingData : public SamplingData {
    private:
        std::vector<int> location;
        std::vector<float> fitting_para;
        Triangle *triangle;
    public:
        DescartesCoordinateSamplingData();

        DescartesCoordinateSamplingData(Point *point, float value);

        DescartesCoordinateSamplingData(const SamplingData &rhs);

        DescartesCoordinateSamplingData(const SamplingData &rhs, std::vector<int> location,
                                        std::vector<float> fittingPara, Triangle *triangle);

        DescartesCoordinateSamplingData(const DescartesCoordinateSamplingData &rhs);

        virtual ~DescartesCoordinateSamplingData();

        const std::vector<int> &getLocation() const;

        void setLocation(const std::vector<int> &location);

        void setSingleDataToLocation(const int data);

        const std::vector<float> &getFittingPara() const;

        void setFittingPara(const std::vector<float> &fittingPara);

        Triangle *getTriangle() const;

        void setTriangle(Triangle *triangle);

        bool operator==(const DescartesCoordinateSamplingData &rhs) const;

        bool operator!=(const DescartesCoordinateSamplingData &rhs) const;

        bool operator<(const DescartesCoordinateSamplingData &rhs) const;

        bool operator>(const DescartesCoordinateSamplingData &rhs) const;

        bool operator<=(const DescartesCoordinateSamplingData &rhs) const;

        bool operator>=(const DescartesCoordinateSamplingData &rhs) const;

        DescartesCoordinateSamplingData &operator=(const DescartesCoordinateSamplingData &rhs);

        friend std::ostream &operator<<(std::ostream &os, const DescartesCoordinateSamplingData &data) {
            os << static_cast<const SamplingData &>(data) << " location: ";
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
    };
}


#endif //TRIANGLEDOMAIN_DESCARTESCOORDINATESAMPLINGDATA_H
