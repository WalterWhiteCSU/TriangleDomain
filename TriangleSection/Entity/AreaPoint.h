/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          坐标点
 *          u:  u坐标的值
 *          v:  v坐标的值
 *          w:  w坐标的信息
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_AREAPOINT_H
#define TRIANGLEDOMAIN_AREAPOINT_H

#include <ostream>
#include <Eigen/Dense>

namespace TriangleDomain {

    class AreaPoint {
    private:
        float u;
        float v;
        float w;


    public:
        AreaPoint();

        AreaPoint(float u, float v, float w);

        AreaPoint(const AreaPoint &rhs);

        float getU() const;

        void setU(float u);

        float getV() const;

        void setV(float v);

        float getW() const;

        void setW(float w);

        bool operator==(const AreaPoint &rhs) const;

        bool operator!=(const AreaPoint &rhs) const;

        bool operator<(const AreaPoint &rhs) const;

        bool operator>(const AreaPoint &rhs) const;

        bool operator<=(const AreaPoint &rhs) const;

        bool operator>=(const AreaPoint &rhs) const;

        AreaPoint &operator=(const AreaPoint &rhs);

        friend std::ostream &operator<<(std::ostream &os, const AreaPoint &point) {
            os << "u: " << point.u << " v: " << point.v << " w: " << point.w;
            return os;
        }

    public:
        Eigen::VectorXf GetVector();

        static AreaPoint *GetAreaPointByVector(Eigen::VectorXf vector);
    };
}


#endif //TRIANGLEDOMAIN_AREAPOINT_H
