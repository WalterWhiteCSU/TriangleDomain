//
// Created by WalterWhite on 2021/6/7.
//

#include "AreaCoordinateSamplingData.h"

#include <utility>

namespace TriangleDomain {

    AreaCoordinateSamplingData::AreaCoordinateSamplingData() {
        this->areaPoint = new AreaPoint();
        this->triangle = new Triangle();
    }

    AreaCoordinateSamplingData::AreaCoordinateSamplingData(const SamplingData &rhs) : SamplingData(rhs) {
        this->areaPoint = new AreaPoint();
        this->triangle = new Triangle();
    }

    AreaCoordinateSamplingData::AreaCoordinateSamplingData(Point *point, float value) : SamplingData(point, value) {
        this->areaPoint = new AreaPoint();
        this->triangle = new Triangle();
    }

    AreaCoordinateSamplingData::AreaCoordinateSamplingData(const SamplingData &rhs, AreaPoint *areaPoint,
                                                           std::vector<int> location,
                                                           std::vector<float> fittingPara, Triangle *triangle)
            : SamplingData(rhs), location(std::move(location)), fitting_para(std::move(fittingPara)) {
        this->areaPoint = new AreaPoint(*areaPoint);
        this->triangle = new Triangle(*triangle);
    }

    AreaCoordinateSamplingData::~AreaCoordinateSamplingData() {
        delete this->areaPoint;
        delete this->triangle;
    }

    AreaCoordinateSamplingData::AreaCoordinateSamplingData(const AreaCoordinateSamplingData &rhs) : SamplingData(rhs) {
        this->triangle = new Triangle(*rhs.triangle);
        this->areaPoint = new AreaPoint(*rhs.areaPoint);

        this->location = rhs.location;
        this->fitting_para = rhs.fitting_para;
    }

    AreaPoint *AreaCoordinateSamplingData::getAreaPoint() const {
        return areaPoint;
    }

    void AreaCoordinateSamplingData::setAreaPoint(AreaPoint *areaPoint) {
        delete this->areaPoint;
        AreaCoordinateSamplingData::areaPoint = areaPoint;
    }

    const std::vector<int> &AreaCoordinateSamplingData::getLocation() const {
        return location;
    }

    void AreaCoordinateSamplingData::setLocation(const std::vector<int> &location) {
        AreaCoordinateSamplingData::location = location;
    }

    const std::vector<float> &AreaCoordinateSamplingData::getFittingPara() const {
        return fitting_para;
    }

    void AreaCoordinateSamplingData::setFittingPara(const std::vector<float> &fittingPara) {
        fitting_para = fittingPara;
    }

    Triangle *AreaCoordinateSamplingData::getTriangle() const {
        return triangle;
    }

    void AreaCoordinateSamplingData::setTriangle(Triangle *triangle) {
        AreaCoordinateSamplingData::triangle = triangle;
    }

    bool AreaCoordinateSamplingData::operator==(const AreaCoordinateSamplingData &rhs) const {
        return static_cast<const TriangleDomain::SamplingData &>(*this) ==
               static_cast<const TriangleDomain::SamplingData &>(rhs) &&
               areaPoint == rhs.areaPoint &&
               location == rhs.location &&
               fitting_para == rhs.fitting_para &&
               triangle == rhs.triangle;
    }

    bool AreaCoordinateSamplingData::operator!=(const AreaCoordinateSamplingData &rhs) const {
        return !(rhs == *this);
    }

    bool AreaCoordinateSamplingData::operator<(const AreaCoordinateSamplingData &rhs) const {
        if (static_cast<const TriangleDomain::SamplingData &>(*this) <
            static_cast<const TriangleDomain::SamplingData &>(rhs))
            return true;
        if (static_cast<const TriangleDomain::SamplingData &>(rhs) <
            static_cast<const TriangleDomain::SamplingData &>(*this))
            return false;
        if (areaPoint < rhs.areaPoint)
            return true;
        if (rhs.areaPoint < areaPoint)
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

    bool AreaCoordinateSamplingData::operator>(const AreaCoordinateSamplingData &rhs) const {
        return rhs < *this;
    }

    bool AreaCoordinateSamplingData::operator<=(const AreaCoordinateSamplingData &rhs) const {
        return !(rhs < *this);
    }

    bool AreaCoordinateSamplingData::operator>=(const AreaCoordinateSamplingData &rhs) const {
        return !(*this < rhs);
    }

    AreaCoordinateSamplingData &AreaCoordinateSamplingData::operator=(const AreaCoordinateSamplingData &rhs) {
        if (this != &rhs) {
            delete this->areaPoint;
            delete this->triangle;

            SamplingData::operator=(rhs);

            this->areaPoint = new AreaPoint(*rhs.areaPoint);
            this->triangle = new Triangle(*rhs.triangle);

            this->location = rhs.location;
            this->fitting_para = rhs.fitting_para;
        }

        return *this;
    }

    void AreaCoordinateSamplingData::setSingleDataToLocation(const int data) {
        this->location.push_back(data);
    }

    void AreaCoordinateSamplingData::setAreaPoint(const Triangle &triangle) {
        delete this->areaPoint;

        float overallArea = triangle.GetTriangleArea();

        Triangle triangle_u(this->getPoint(), triangle.getVertexB(), triangle.getVertexC());
        Triangle triangle_v(this->getPoint(), triangle.getVertexC(), triangle.getVertexA());
        Triangle triangle_w(this->getPoint(), triangle.getVertexA(), triangle.getVertexB());
        float u_area = triangle_u.GetTriangleArea() / overallArea;
        float v_area = triangle_v.GetTriangleArea() / overallArea;
        float w_area = triangle_w.GetTriangleArea() / overallArea;

        this->areaPoint = new AreaPoint(u_area, v_area, w_area);
    }

    void AreaCoordinateSamplingData::QuantifyParameter() {
        std::vector<float> res;

        for (auto model:this->fitting_para) {
            res.push_back(std::round(model / 20) * 20.0f);
        }

        this->fitting_para = res;
    }

}
