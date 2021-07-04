/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          采样点的数据
 *          point:  采样点的坐标
 *          value:  采样点的值
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_SAMPLINGDATA_H
#define TRIANGLEDOMAIN_SAMPLINGDATA_H

#include <ostream>
#include "Point.h"

namespace TriangleDomain {
    class SamplingData {
    private:
        Point *point;
        float value;
    public:
        SamplingData();

        SamplingData(Point *point, float value);

        SamplingData(const SamplingData &rhs);

        virtual ~SamplingData();

        Point *getPoint() const;

        void setPoint(Point *point);

        float getValue() const;

        void setValue(float value);

        bool operator==(const SamplingData &rhs) const;

        bool operator!=(const SamplingData &rhs) const;

        bool operator<(const SamplingData &rhs) const;

        bool operator>(const SamplingData &rhs) const;

        bool operator<=(const SamplingData &rhs) const;

        bool operator>=(const SamplingData &rhs) const;

        SamplingData& operator=(const SamplingData &rhs);

        friend std::ostream &operator<<(std::ostream &os, const SamplingData &data) {
            os << "point: " << data.point->getX() << "," << data.point->getY() << " value: " << data.value;
            return os;
        }
    };
}


#endif //TRIANGLEDOMAIN_SAMPLINGDATA_H
