//
// Created by WalterWhite on 2021/6/7.
//

#include "Triangle.h"


namespace TriangleDomain {
    Triangle::Triangle() {
        vertexA = new Point();
        vertexB = new Point();
        vertexC = new Point();
    }

    Triangle::Triangle(Point *vertexA, Point *vertexB, Point *vertexC) {
        this->vertexA = new Point(*vertexA);
        this->vertexB = new Point(*vertexB);
        this->vertexC = new Point(*vertexC);
    }

    Triangle::Triangle(const Triangle &rhs) {
        this->vertexA = new Point(*rhs.vertexA);
        this->vertexB = new Point(*rhs.vertexB);
        this->vertexC = new Point(*rhs.vertexC);
    }

    Triangle::~Triangle() {
        delete this->vertexA;
        delete this->vertexB;
        delete this->vertexC;
    }

    Point *Triangle::getVertexA() const {
        return vertexA;
    }

    void Triangle::setVertexA(Point *vertexA) {
        delete this->vertexA;
        this->vertexA = new Point(*vertexA);
    }

    Point *Triangle::getVertexB() const {
        return vertexB;
    }

    void Triangle::setVertexB(Point *vertexB) {
        delete this->vertexB;
        this->vertexB = new Point(*vertexB);
    }

    Point *Triangle::getVertexC() const {
        return vertexC;
    }

    void Triangle::setVertexC(Point *vertexC) {
        delete this->vertexC;
        this->vertexC = new Point(*vertexC);
    }

    bool Triangle::operator==(const Triangle &rhs) const {
        return vertexA == rhs.vertexA &&
               vertexB == rhs.vertexB &&
               vertexC == rhs.vertexC;
    }

    bool Triangle::operator!=(const Triangle &rhs) const {
        return !(rhs == *this);
    }

    bool Triangle::operator<(const Triangle &rhs) const {
        if (vertexA < rhs.vertexA)
            return true;
        if (rhs.vertexA < vertexA)
            return false;
        if (vertexB < rhs.vertexB)
            return true;
        if (rhs.vertexB < vertexB)
            return false;
        return vertexC < rhs.vertexC;
    }

    bool Triangle::operator>(const Triangle &rhs) const {
        return rhs < *this;
    }

    bool Triangle::operator<=(const Triangle &rhs) const {
        return !(rhs < *this);
    }

    bool Triangle::operator>=(const Triangle &rhs) const {
        return !(*this < rhs);
    }

    Triangle &Triangle::operator=(const Triangle &rhs) {
        if (this != &rhs) {
            delete this->vertexA;
            delete this->vertexB;
            delete this->vertexC;

            vertexA = new Point(*rhs.vertexA);
            vertexB = new Point(*rhs.vertexB);
            vertexC = new Point(*rhs.vertexC);
        }
        return *this;
    }

    /*   判断是否在三角形内   */
    int Triangle::isPointInTriangle(const Point *point) const {
        Vector edge_ab(this->vertexA, this->vertexB);
        Vector edge_bc(this->vertexB, this->vertexC);
        Vector edge_ca(this->vertexC, this->vertexA);

        Vector edge_ap(this->vertexA, point);
        Vector edge_bp(this->vertexB, point);
        Vector edge_cp(this->vertexC, point);

        float value_1 =
                cross(edge_ab.normal(), edge_ap.normal()) * cross(edge_ab.normal(), edge_ca.opposite().normal());
        float value_2 =
                cross(edge_bc.normal(), edge_bp.normal()) * cross(edge_bc.normal(), edge_ab.opposite().normal());
        float value_3 =
                cross(edge_ca.normal(), edge_cp.normal()) * cross(edge_ca.normal(), edge_bc.opposite().normal());

        if(value_1 < 0.0f || value_2 < 0.0f || value_3 < 0.0f)
            return -1;
        if(value_1 == 0.0f || value_2 == 0.0f || value_3 == 0.0f)
            return 0;
        return 1;
    }

    float Triangle::GetTriangleArea() const {

//        float a = this->GetLengthOfA();
//        float b = this->GetLengthOfB();
//        float c = this->GetLengthOfC();
//        float area = 0.25f * sqrt((a+b+c) * (a+b-c) * (a-b+c) * (-a+b+c));

        float area = 0.5f * (this->vertexA->getX() * (this->vertexB->getY() - this->vertexC->getY()) +
                             this->vertexB->getX() * (this->vertexC->getY() - this->vertexA->getY()) +
                             this->vertexC->getX() * (this->vertexA->getY() - this->vertexB->getY()));

        return area;
    }

    float Triangle::GetLengthOfA() const {
        return sqrt(pow(this->vertexB->getX() - this->vertexC->getX(), 2) +
                    pow(this->vertexB->getY() - this->vertexC->getY(), 2));
    }

    float Triangle::GetLengthOfB() const {
        return sqrt(pow(this->vertexA->getX() - this->vertexC->getX(), 2) +
                    pow(this->vertexA->getY() - this->vertexC->getY(), 2));
    }

    float Triangle::GetLengthOfC() const {
        return sqrt(pow(this->vertexA->getX() - this->vertexB->getX(), 2) +
                    pow(this->vertexA->getY() - this->vertexB->getY(), 2));
    }

    std::vector<Triangle> Triangle::triangleSection() const {
        std::vector<Triangle> res;

        Point *A = this->vertexA;
        Point *B = this->vertexB;
        Point *C = this->vertexC;

        Point *AB = new Point(
                (A->getX() + B->getX()) / 2.0f,
                (A->getY() + B->getY()) / 2.0f
        );
        Point *AC = new Point(
                (A->getX() + C->getX()) / 2.0f,
                (A->getY() + C->getY()) / 2.0f
        );
        Point *BC = new Point(
                (B->getX() + C->getX()) / 2.0f,
                (B->getY() + C->getY()) / 2.0f
        );
        //  第一个三角形
        Triangle triangle_1(A, AB, AC);
        res.push_back(triangle_1);

        //  第二个三角形
        Triangle triangle_2(AB, B, BC);
        res.push_back(triangle_2);

        //  第三个三角形
        Triangle triangle_3(BC, AC, AB);
        res.push_back(triangle_3);

        //  第四个三角形
        Triangle triangle_4(AC, BC, C);
        res.push_back(triangle_4);

        return res;
    }
}
