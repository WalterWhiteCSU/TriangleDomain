/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          向量
 *          x:  向量的x坐标
 *          y:  向量的y坐标
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_VECTOR_H
#define TRIANGLEDOMAIN_VECTOR_H

#include <ostream>
#include "Point.h"

namespace TriangleDomain {
    class Vector {
    private:
        float x;
        float y;
    public:
        Vector();

        Vector(float x, float y);

        Vector(const Vector &rhs);

        Vector(const Point *startPoint, const Point *endPoint);

        float getX() const;

        void setX(float x);

        float getY() const;

        void setY(float y);

        bool operator==(const Vector &rhs) const;

        bool operator!=(const Vector &rhs) const;

        bool operator<(const Vector &rhs) const;

        bool operator>(const Vector &rhs) const;

        bool operator<=(const Vector &rhs) const;

        bool operator>=(const Vector &rhs) const;

        Vector &operator=(const Vector &rhs);

        friend std::ostream &operator<<(std::ostream &os, const Vector &vertex) {
            os << "x: " << vertex.x << " y: " << vertex.y;
            return os;
        }

    public:
        Vector &normal();

        Vector operator+(const Vector &rhs) const;

        Vector operator-(const Vector &rhs) const;

        float operator*(const Vector &rhs) const;

        Vector opposite() const;

        friend float cross(const Vector &v1, const Vector &v2);
    };
}


#endif //TRIANGLEDOMAIN_VECTOR_H
