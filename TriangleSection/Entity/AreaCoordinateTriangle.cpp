//
// Created by WalterWhite on 2021/6/28.
//

#include "AreaCoordinateTriangle.h"

namespace TriangleDomain {

    AreaCoordinateTriangle::AreaCoordinateTriangle() {}

    AreaCoordinateTriangle::AreaCoordinateTriangle(AreaPoint *vertex1, AreaPoint *vertex2, AreaPoint *vertex3) {
        this->vertex1 = new AreaPoint(*vertex1);
        this->vertex2 = new AreaPoint(*vertex2);
        this->vertex3 = new AreaPoint(*vertex3);
    }

    AreaCoordinateTriangle::AreaCoordinateTriangle(const AreaCoordinateTriangle &rhs) {
        this->vertex1 = new AreaPoint(*rhs.vertex1);
        this->vertex2 = new AreaPoint(*rhs.vertex2);
        this->vertex3 = new AreaPoint(*rhs.vertex3);
    }

    AreaCoordinateTriangle::~AreaCoordinateTriangle() {
        delete this->vertex1;
        delete this->vertex2;
        delete this->vertex3;
    }

    AreaPoint *AreaCoordinateTriangle::getVertex1() const {
        return vertex1;
    }

    void AreaCoordinateTriangle::setVertex1(AreaPoint *vertex1) {
        delete this->vertex1;
        AreaCoordinateTriangle::vertex1 = new AreaPoint(*vertex1);
    }

    AreaPoint *AreaCoordinateTriangle::getVertex2() const {
        return vertex2;
    }

    void AreaCoordinateTriangle::setVertex2(AreaPoint *vertex2) {
        delete this->vertex2;
        AreaCoordinateTriangle::vertex2 = new AreaPoint(*vertex2);
    }

    AreaPoint *AreaCoordinateTriangle::getVertex3() const {
        return vertex3;
    }

    void AreaCoordinateTriangle::setVertex3(AreaPoint *vertex3) {
        delete this->vertex3;
        AreaCoordinateTriangle::vertex3 = new AreaPoint(*vertex3);
    }
}