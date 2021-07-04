//
// Created by WalterWhite on 2021/6/7.
//

#include "Point.h"

namespace TriangleDomain {
    Point::Point(float x, float y) : x(x), y(y) {}

    Point::Point() {
        x = 0.0f;
        y = 0.0f;
    }

    Point::Point(const Point &rhs) {
        x = rhs.x;
        y = rhs.y;
    }

    float Point::getX() const {
        return x;
    }

    void Point::setX(float x) {
        Point::x = x;
    }

    float Point::getY() const {
        return y;
    }

    void Point::setY(float y) {
        Point::y = y;
    }

    bool Point::operator==(const TriangleDomain::Point &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool Point::operator!=(const TriangleDomain::Point &rhs) const {
        return !(rhs == *this);
    }

    bool Point::operator<(const TriangleDomain::Point &rhs) const {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }

    bool Point::operator>(const TriangleDomain::Point &rhs) const {
        return rhs < *this;
    }

    bool Point::operator<=(const TriangleDomain::Point &rhs) const {
        return !(rhs < *this);
    }

    bool Point::operator>=(const TriangleDomain::Point &rhs) const {
        return !(*this < rhs);
    }

    Point &Point::operator=(const Point &rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
        }
        return *this;
    }
}
