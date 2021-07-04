/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          坐标点
 *          x:  x坐标的值
 *          y:  y坐标的值
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_POINT_H
#define TRIANGLEDOMAIN_POINT_H

#include <ostream>

namespace TriangleDomain {
    class Point {
    private:
        float x;
        float y;

    public:
        Point();

        Point(float x, float y);

        Point(const Point &rhs);

        friend std::ostream &operator<<(std::ostream &os, const Point &point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }

        bool operator<(const Point &rhs) const;

        bool operator>(const Point &rhs) const;

        bool operator<=(const Point &rhs) const;

        bool operator>=(const Point &rhs) const;

        bool operator==(const Point &rhs) const;

        bool operator!=(const Point &rhs) const;

        Point &operator=(const Point &rhs);

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);
    };

}
#endif //TRIANGLEDOMAIN_POINT_H
