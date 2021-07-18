//
// Created by WalterWhite on 2021/6/7.
//

#include "AreaPoint.h"

namespace TriangleDomain {

    AreaPoint::AreaPoint() {
        u = 0.0f;
        v = 0.0f;
        w = 0.0f;

    }

    AreaPoint::AreaPoint(float u, float v, float w) : u(u), v(v), w(w) {}


    AreaPoint::AreaPoint(const AreaPoint &rhs) {
        u = rhs.u;
        v = rhs.v;
        w = rhs.w;

    }

    float AreaPoint::getU() const {
        return u;
    }

    void AreaPoint::setU(float u) {
        AreaPoint::u = u;
    }

    float AreaPoint::getV() const {
        return v;
    }

    void AreaPoint::setV(float v) {
        AreaPoint::v = v;
    }

    float AreaPoint::getW() const {
        return w;
    }

    void AreaPoint::setW(float w) {
        AreaPoint::w = w;
    }

    bool AreaPoint::operator==(const AreaPoint &rhs) const {
        return u == rhs.u &&
               v == rhs.v &&
               w == rhs.w;
    }

    bool AreaPoint::operator!=(const AreaPoint &rhs) const {
        return !(rhs == *this);
    }

    bool AreaPoint::operator<(const AreaPoint &rhs) const {
        if (u < rhs.u)
            return true;
        if (rhs.u < u)
            return false;
        if (v < rhs.v)
            return true;
        if (rhs.v < v)
            return false;
        return w < rhs.w;
    }

    bool AreaPoint::operator>(const AreaPoint &rhs) const {
        return rhs < *this;
    }

    bool AreaPoint::operator<=(const AreaPoint &rhs) const {
        return !(rhs < *this);
    }

    bool AreaPoint::operator>=(const AreaPoint &rhs) const {
        return !(*this < rhs);
    }

    AreaPoint &AreaPoint::operator=(const AreaPoint &rhs) {
        if (this != &rhs) {
            u = rhs.u;
            v = rhs.v;
            w = rhs.w;
        }
        return *this;
    }

    Eigen::VectorXf AreaPoint::GetVector() {
        Eigen::VectorXf res(3);

        res(0) = this->u;
        res(1) = this->v;
        res(2) = this->w;

        return res;
    }

    AreaPoint *AreaPoint::GetAreaPointByVector(Eigen::VectorXf vector) {
        float u = vector(0);
        float v = vector(1);
        float w = vector(2);

        return new AreaPoint(u, v, w);
    }
}
