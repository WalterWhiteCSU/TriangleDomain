/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                CalculateData.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/11
  *Description:             每个数据点的信息
  *Others:
  *Function List:
**********************************************************************************/

#ifndef TRIANGLEDOMAIN_CALCULATEDATA_H
#define TRIANGLEDOMAIN_CALCULATEDATA_H

#include "../../include/SamplingData.h"
#include "../../include/AreaPoint.h"
#include "../../include/Triangle.h"

namespace TriangleV {
    class CalculateData {
    public:
        TriangleDomain::SamplingData *data;
        TriangleDomain::AreaPoint *areaPoint;

        CalculateData() {
            this->data = new TriangleDomain::SamplingData();
            this->areaPoint = new TriangleDomain::AreaPoint();
        }

        CalculateData(TriangleDomain::SamplingData *m_sampling) {
            this->data = new TriangleDomain::SamplingData(*m_sampling);
            this->areaPoint = new TriangleDomain::AreaPoint();
        }

        CalculateData(TriangleDomain::SamplingData *m_sampling, TriangleDomain::AreaPoint *m_area) {
            this->data = new TriangleDomain::SamplingData(*m_sampling);
            this->areaPoint = new TriangleDomain::AreaPoint(*m_area);
        }

        CalculateData(const CalculateData &rhs) {
            this->data = rhs.data;
            this->areaPoint = rhs.areaPoint;
        }

        ~CalculateData() {
            delete this->data;
            delete this->areaPoint;
        }

        CalculateData &operator=(const CalculateData &rhs) {
            if (this != &rhs) {
                this->data = rhs.data;
                this->areaPoint = rhs.areaPoint;
            }

            return *this;
        }

        void SetAreaPoint(const TriangleDomain::Triangle &triangle) {
            delete this->areaPoint;

            float overallArea = triangle.GetTriangleArea();

            TriangleDomain::Triangle triangle_u(this->data->getPoint(), triangle.getVertexB(), triangle.getVertexC());
            TriangleDomain::Triangle triangle_v(this->data->getPoint(), triangle.getVertexC(), triangle.getVertexA());
            TriangleDomain::Triangle triangle_w(this->data->getPoint(), triangle.getVertexA(), triangle.getVertexB());
            float u_area = triangle_u.GetTriangleArea() / overallArea;
            float v_area = triangle_v.GetTriangleArea() / overallArea;
            float w_area = triangle_w.GetTriangleArea() / overallArea;

            this->areaPoint = new TriangleDomain::AreaPoint(u_area, v_area, w_area);
        }
    };
}


#endif //TRIANGLEDOMAIN_CALCULATEDATA_H
