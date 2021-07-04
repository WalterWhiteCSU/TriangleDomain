//
// Created by WalterWhite on 2021/6/9.
//

#include <complex>
#include "Vector.h"

namespace TriangleDomain {

    Vector::Vector() {}

    Vector::Vector(float x, float y) : x(x), y(y) {}

    Vector::Vector(const Vector &rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    Vector::Vector(const Point *startPoint, const Point *endPoint) {
        this->x = endPoint->getX() - startPoint->getX();
        this->y = endPoint->getY() - startPoint->getY();
    }

    float Vector::getX() const {
        return x;
    }

    void Vector::setX(float x) {
        Vector::x = x;
    }

    float Vector::getY() const {
        return y;
    }

    void Vector::setY(float y) {
        Vector::y = y;
    }

    bool Vector::operator==(const Vector &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool Vector::operator!=(const Vector &rhs) const {
        return !(rhs == *this);
    }

    bool Vector::operator<(const Vector &rhs) const {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }

    bool Vector::operator>(const Vector &rhs) const {
        return rhs < *this;
    }

    bool Vector::operator<=(const Vector &rhs) const {
        return !(rhs < *this);
    }

    bool Vector::operator>=(const Vector &rhs) const {
        return !(*this < rhs);
    }

    Vector &Vector::operator=(const Vector &rhs) {
        if (this != &rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
        }
        return *this;
    }

    Vector &Vector::normal() {
        float length = std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
        this->x /= length;
        this->y /= length;

        return *this;
    }

    Vector Vector::operator+(const Vector &rhs) const {
        Vector res;

        res.x = this->x + rhs.x;
        res.y = this->y + rhs.y;

        return res;
    }

    Vector Vector::operator-(const Vector &rhs) const {
        Vector res;

        res.x = this->x - rhs.x;
        res.y = this->y - rhs.y;

        return res;
    }

    float Vector::operator*(const Vector &rhs) const {
        return this->x * rhs.x + this->y * rhs.y;
    }

    float cross(const Vector &v1, const Vector &v2) {
        return v1.x * v2.y - v1.y * v2.x;
    }

    Vector Vector::opposite() const {
        Vector res;

        res.setX(this->x * -1.0f);
        res.setY(this->y * -1.0f);

        return res;
    }

}