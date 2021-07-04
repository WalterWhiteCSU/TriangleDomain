/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/28
 *      @Last Modified Date:    2021/6/28
 *
 *      @Descript:
 *          面积坐标构成的三角形
 *
 ***************************************************************
 * */

#ifndef TRIANGLEDOMAIN_AREACOORDINATETRIANGLE_H
#define TRIANGLEDOMAIN_AREACOORDINATETRIANGLE_H

#include "AreaPoint.h"

namespace TriangleDomain {

    class AreaCoordinateTriangle {
    private:
        AreaPoint *vertex1;
        AreaPoint *vertex2;
        AreaPoint *vertex3;
    public:
        AreaCoordinateTriangle();

        AreaCoordinateTriangle(AreaPoint *vertex1, AreaPoint *vertex2, AreaPoint *vertex3);

        AreaCoordinateTriangle(const AreaCoordinateTriangle &rhs);

        virtual ~AreaCoordinateTriangle();

        AreaPoint *getVertex1() const;

        void setVertex1(AreaPoint *vertex1);

        AreaPoint *getVertex2() const;

        void setVertex2(AreaPoint *vertex2);

        AreaPoint *getVertex3() const;

        void setVertex3(AreaPoint *vertex3);
    };
}


#endif //TRIANGLEDOMAIN_AREACOORDINATETRIANGLE_H
