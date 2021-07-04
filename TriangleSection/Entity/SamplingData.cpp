//
// Created by WalterWhite on 2021/6/7.
//

#include "SamplingData.h"

namespace TriangleDomain {

    SamplingData::SamplingData() {
        point = new Point(0.0f, 0.0f);
        value = 0.0f;
    }

    SamplingData::SamplingData(Point *point, float value) {
        this->point = new Point(*point);
        this->value = value;
    }

    SamplingData::SamplingData(const SamplingData &rhs) {
        point = new Point(*rhs.point);
        value = rhs.value;
    }

    Point *SamplingData::getPoint() const {
        return point;
    }

    void SamplingData::setPoint(Point *point) {
        delete this->point;
        SamplingData::point = new Point(point->getX(), point->getY());
    }

    float SamplingData::getValue() const {
        return value;
    }

    void SamplingData::setValue(float value) {
        SamplingData::value = value;
    }

    bool SamplingData::operator==(const SamplingData &rhs) const {
        return point == rhs.point &&
               value == rhs.value;
    }

    bool SamplingData::operator!=(const SamplingData &rhs) const {
        return !(rhs == *this);
    }

    bool SamplingData::operator<(const SamplingData &rhs) const {
        if (point < rhs.point)
            return true;
        if (rhs.point < point)
            return false;
        return value < rhs.value;
    }

    bool SamplingData::operator>(const SamplingData &rhs) const {
        return rhs < *this;
    }

    bool SamplingData::operator<=(const SamplingData &rhs) const {
        return !(rhs < *this);
    }

    bool SamplingData::operator>=(const SamplingData &rhs) const {
        return !(*this < rhs);
    }

    SamplingData &SamplingData::operator=(const SamplingData &rhs) {
        if (this != &rhs) {
            delete this->point;
            point = new Point(*rhs.point);
            value = rhs.value;
        }
        return *this;
    }

    SamplingData::~SamplingData() {
        delete point;
    }

}
