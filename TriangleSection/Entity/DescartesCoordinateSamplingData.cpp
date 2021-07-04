//
// Created by WalterWhite on 2021/6/7.
//

#include "DescartesCoordinateSamplingData.h"

#include <utility>

namespace TriangleDomain {
    DescartesCoordinateSamplingData::DescartesCoordinateSamplingData() {
        this->triangle = new Triangle();
    }

    DescartesCoordinateSamplingData::DescartesCoordinateSamplingData(Point *point, float value) : SamplingData(point,
                                                                                                               value) {
        this->triangle = new Triangle();
    }

    DescartesCoordinateSamplingData::DescartesCoordinateSamplingData(const SamplingData &rhs) : SamplingData(rhs) {
        this->triangle = new Triangle();
    }

    DescartesCoordinateSamplingData::DescartesCoordinateSamplingData(const SamplingData &rhs,
                                                                     std::vector<int> location,
                                                                     std::vector<float> fittingPara,
                                                                     Triangle *triangle) : SamplingData(rhs),
                                                                                           location(
                                                                                                   std::move(location)),
                                                                                           fitting_para(std::move(
                                                                                                   fittingPara)) {
        this->triangle = new Triangle(*triangle);
    }

    DescartesCoordinateSamplingData::DescartesCoordinateSamplingData(const DescartesCoordinateSamplingData &rhs)
            : SamplingData(rhs) {
        this->triangle = new Triangle(*rhs.triangle);

        this->location = rhs.location;
        this->fitting_para = rhs.fitting_para;
    }

    DescartesCoordinateSamplingData::~DescartesCoordinateSamplingData() {
        delete this->triangle;
    }

    const std::vector<int> &DescartesCoordinateSamplingData::getLocation() const {
        return location;
    }

    void DescartesCoordinateSamplingData::setLocation(const std::vector<int> &location) {
        DescartesCoordinateSamplingData::location = location;
    }

    void DescartesCoordinateSamplingData::setSingleDataToLocation(const int data) {
        this->location.push_back(data);
    }

    const std::vector<float> &DescartesCoordinateSamplingData::getFittingPara() const {
        return fitting_para;
    }

    void DescartesCoordinateSamplingData::setFittingPara(const std::vector<float> &fittingPara) {
        fitting_para = fittingPara;
    }

    Triangle *DescartesCoordinateSamplingData::getTriangle() const {
        return triangle;
    }

    void DescartesCoordinateSamplingData::setTriangle(Triangle *triangle) {
        DescartesCoordinateSamplingData::triangle = triangle;
    }

    bool DescartesCoordinateSamplingData::operator==(const DescartesCoordinateSamplingData &rhs) const {
        return static_cast<const TriangleDomain::SamplingData &>(*this) ==
               static_cast<const TriangleDomain::SamplingData &>(rhs) &&
               location == rhs.location &&
               fitting_para == rhs.fitting_para &&
               triangle == rhs.triangle;
    }

    bool DescartesCoordinateSamplingData::operator!=(const DescartesCoordinateSamplingData &rhs) const {
        return !(rhs == *this);
    }

    bool DescartesCoordinateSamplingData::operator<(const DescartesCoordinateSamplingData &rhs) const {
        if (static_cast<const TriangleDomain::SamplingData &>(*this) <
            static_cast<const TriangleDomain::SamplingData &>(rhs))
            return true;
        if (static_cast<const TriangleDomain::SamplingData &>(rhs) <
            static_cast<const TriangleDomain::SamplingData &>(*this))
            return false;
        if (location < rhs.location)
            return true;
        if (rhs.location < location)
            return false;
        if (fitting_para < rhs.fitting_para)
            return true;
        if (rhs.fitting_para < fitting_para)
            return false;
        return triangle < rhs.triangle;
    }

    bool DescartesCoordinateSamplingData::operator>(const DescartesCoordinateSamplingData &rhs) const {
        return rhs < *this;
    }

    bool DescartesCoordinateSamplingData::operator<=(const DescartesCoordinateSamplingData &rhs) const {
        return !(rhs < *this);
    }

    bool DescartesCoordinateSamplingData::operator>=(const DescartesCoordinateSamplingData &rhs) const {
        return !(*this < rhs);
    }

    DescartesCoordinateSamplingData &
    DescartesCoordinateSamplingData::operator=(const DescartesCoordinateSamplingData &rhs) {
        if (this != &rhs) {
            delete this->triangle;

            SamplingData::operator=(rhs);

            this->triangle = new Triangle(*rhs.triangle);

            this->location = rhs.location;
            this->fitting_para = rhs.fitting_para;
        }
        return *this;
    }


}
