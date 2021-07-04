/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/7
 *      @Last Modified Date:    2021/6/7
 *
 *      @Descript:
 *          三角形
 *          vertexA:  三角形的顶点A
 *          vertexB:  三角形的顶点B
 *          vertexC:  三角形的顶点C
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_TRIANGLE_H
#define TRIANGLEDOMAIN_TRIANGLE_H

#include <ostream>
#include <math.h>
#include <vector>
#include "Point.h"
#include "Vector.h"


namespace TriangleDomain {

    class Triangle {
    private:
        Point *vertexA;
        Point *vertexB;
        Point *vertexC;

    public:
        Triangle();

        Triangle(Point *vertexA, Point *vertexB, Point *vertexC);

        Triangle(const Triangle &rhs);

        virtual ~Triangle();

        Point *getVertexA() const;

        void setVertexA(Point *vertexA);

        Point *getVertexB() const;

        void setVertexB(Point *vertexB);

        Point *getVertexC() const;

        void setVertexC(Point *vertexC);

        bool operator==(const Triangle &rhs) const;

        bool operator!=(const Triangle &rhs) const;

        bool operator<(const Triangle &rhs) const;

        bool operator>(const Triangle &rhs) const;

        bool operator<=(const Triangle &rhs) const;

        bool operator>=(const Triangle &rhs) const;

        Triangle &operator=(const Triangle &rhs);

        /*   对三角形进行剖分   */
        std::vector<Triangle> triangleSection() const;

        friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
            os << "vertexA: " << *triangle.vertexA << " vertexB: " << *triangle.vertexB << " vertexC: "
               << *triangle.vertexC;
            return os;
        }

    public:
        int isPointInTriangle(const Point *point) const;

        float GetTriangleArea() const;

        float GetLengthOfA() const;

        float GetLengthOfB() const;

        float GetLengthOfC() const;
    };
}


#endif //TRIANGLEDOMAIN_TRIANGLE_H
