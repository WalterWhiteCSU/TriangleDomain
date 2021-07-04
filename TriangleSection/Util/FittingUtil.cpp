//
// Created by WalterWhite on 2021/6/9.
//

#include "FittingUtil.h"

namespace TriangleDomain {

    /*   面积坐标拟合   */
    float
    FittingUtil::AreaCoordinateFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data, const int fittingType,
                                       std::vector<float> &fittingPara) {
        switch (fittingType) {
            case 1:
                return AreaCoordinateLinearFitting(sampling_data, fittingPara);
            case 2:
                return AreaCoordinateQuadraticFitting(sampling_data, fittingPara);
            default:
                return -1.0f;
        }
    }

    /*   直角坐标拟合   */
    float FittingUtil::DescartesCoordinateFitting(std::vector<DescartesCoordinateSamplingData *> &sampling_data,
                                                  int fittingType, std::vector<float> &fittingPara) {
        switch (fittingType) {
            case 1:
                return DescartesCoordinateLinearFitting(sampling_data, fittingPara);
            case 2:
                return DescartesCoordinateQuadraticFitting(sampling_data, fittingPara);
            default:
                return -1.0f;
        }
    }

    /*   面积坐标一次拟合   */
    float FittingUtil::AreaCoordinateLinearFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data,
                                                   std::vector<float> &fittingPara) {
        float fittingError = 0.0f;

        Eigen::MatrixXf A = Eigen::MatrixXf::Ones(sampling_data.size(), 3);
        Eigen::MatrixXf Y = Eigen::MatrixXf::Ones(sampling_data.size(), 1);

        //  矩阵赋值
        for (int i = 0; i < sampling_data.size(); ++i) {
            A(i, 0) = sampling_data[i]->getAreaPoint()->getU();
            A(i, 1) = sampling_data[i]->getAreaPoint()->getV();
            A(i, 2) = sampling_data[i]->getAreaPoint()->getW();
            Y(i) = sampling_data[i]->getValue();
        }
        Eigen::MatrixXf parameter = A.colPivHouseholderQr().solve(Y);
        fittingPara.push_back((float) parameter(0, 0));
        fittingPara.push_back((float) parameter(1, 0));
        fittingPara.push_back((float) parameter(2, 0));

        fittingError = AreaCoordinateMES(fittingPara, sampling_data, 1);
        return fittingError;
    }

    /*   直角坐标一次拟合   */
    float FittingUtil::DescartesCoordinateLinearFitting(std::vector<DescartesCoordinateSamplingData *> &sampling_data,
                                                        std::vector<float> &fittingPara) {
        float fittingError = 0.0f;

        Eigen::MatrixXf A = Eigen::MatrixXf::Ones(sampling_data.size(), 3);
        Eigen::MatrixXf Y = Eigen::MatrixXf::Ones(sampling_data.size(), 1);

        //  矩阵赋值
        for (int i = 0; i < sampling_data.size(); ++i) {
            A(i, 0) = sampling_data[i]->getPoint()->getX();
            A(i, 1) = sampling_data[i]->getPoint()->getY();
            A(i, 2) = 1.0f;

            Y(i) = sampling_data[i]->getValue();
        }
        Eigen::MatrixXf parameter = A.colPivHouseholderQr().solve(Y);
        fittingPara.push_back((float) parameter(0, 0));
        fittingPara.push_back((float) parameter(1, 0));
        fittingPara.push_back((float) parameter(2, 0));

        fittingError = DescartesCoordinateMES(fittingPara, sampling_data, 1);
        return fittingError;
    }

    /*   面积坐标二次拟合   */
    float FittingUtil::AreaCoordinateQuadraticFitting(std::vector<AreaCoordinateSamplingData *> &sampling_data,
                                                      std::vector<float> &fittingPara) {
        float fittingError = 0.0f;

        Eigen::MatrixXf A = Eigen::MatrixXf::Ones(sampling_data.size(), 6);
        Eigen::MatrixXf Y = Eigen::MatrixXf::Ones(sampling_data.size(), 1);

        //  矩阵赋值
        for (int i = 0; i < sampling_data.size(); ++i) {
            float u = sampling_data[i]->getAreaPoint()->getU();
            float v = sampling_data[i]->getAreaPoint()->getV();
            float w = sampling_data[i]->getAreaPoint()->getW();
            A(i, 0) = u * u;
            A(i, 1) = v * v;
            A(i, 2) = w * w;
            A(i, 3) = u * v;
            A(i, 4) = v * w;
            A(i, 5) = w * u;

            Y(i) = sampling_data[i]->getValue();
        }
        Eigen::MatrixXf parameter = A.colPivHouseholderQr().solve(Y);
        fittingPara.push_back((float) parameter(0, 0));
        fittingPara.push_back((float) parameter(1, 0));
        fittingPara.push_back((float) parameter(2, 0));
        fittingPara.push_back((float) parameter(3, 0));
        fittingPara.push_back((float) parameter(4, 0));
        fittingPara.push_back((float) parameter(5, 0));

        fittingError = AreaCoordinateMES(fittingPara, sampling_data, 2);
        return fittingError;
    }

    /*   直角坐标二次拟合  */
    float FittingUtil::DescartesCoordinateQuadraticFitting(
            std::vector<DescartesCoordinateSamplingData *> &sampling_data, std::vector<float> &fittingPara) {
        float fittingError = 0.0f;

        Eigen::MatrixXf A = Eigen::MatrixXf::Ones(sampling_data.size(), 6);
        Eigen::MatrixXf Y = Eigen::MatrixXf::Ones(sampling_data.size(), 1);

        //  矩阵赋值
        for (int i = 0; i < sampling_data.size(); ++i) {
            float x = sampling_data[i]->getPoint()->getX();
            float y = sampling_data[i]->getPoint()->getY();
            A(i, 0) = x * x;
            A(i, 1) = y * y;
            A(i, 2) = x * y;
            A(i, 3) = x;
            A(i, 4) = y;
            A(i, 5) = 1.0f;

            Y(i) = sampling_data[i]->getValue();
        }
        Eigen::MatrixXf parameter = A.colPivHouseholderQr().solve(Y);
        fittingPara.push_back((float) parameter(0, 0));
        fittingPara.push_back((float) parameter(1, 0));
        fittingPara.push_back((float) parameter(2, 0));
        fittingPara.push_back((float) parameter(3, 0));
        fittingPara.push_back((float) parameter(4, 0));
        fittingPara.push_back((float) parameter(5, 0));

        fittingError = DescartesCoordinateMES(fittingPara, sampling_data, 2);
        return fittingError;
    }

    /*   面积坐标一次拟合的函数   */
    float FittingUtil::AreaCoordinateLinearFunction(std::vector<float> &parameterList, AreaPoint &areaPoint) {
        float result = 0.0f;

        result = areaPoint.getU() * parameterList[0] + areaPoint.getV() * parameterList[1] +
                 areaPoint.getW() * parameterList[2];

        return result;
    }

    /*   直角坐标一次拟合的函数   */
    float FittingUtil::DescartesCoordinateLinearFunction(std::vector<float> &parameterList, Point &point) {
        float result = 0.0f;

        result = point.getX() * parameterList[0] + point.getY() * parameterList[1] + parameterList[2];

        return result;
    }

    /*   面积坐标二次拟合的函数   */
    float FittingUtil::AreaCoordinateQuadraticFunction(std::vector<float> &parameterList, AreaPoint &areaPoint) {
        float result = 0.0f;

        float u = areaPoint.getU();
        float v = areaPoint.getV();
        float w = areaPoint.getW();
        result = u * u * parameterList[0] + v * v * parameterList[1] + w * w * parameterList[2] +
                 u * v * parameterList[3] + v * w * parameterList[4] + w * u * parameterList[5];

        return result;
    }

    /*   直角坐标二次拟合的函数   */
    float FittingUtil::DescartesCoordinateQuadraticFunction(std::vector<float> &parameterList, Point &point) {
        float result = 0.0f;

        float x = point.getX();
        float y = point.getY();
        result = x * x * parameterList[0] + y * y * parameterList[1] + x * y * parameterList[2] + x * parameterList[3] +
                 y * parameterList[4] + parameterList[5];

        return result;
    }

    /*   面积坐标拟合的误差   */
    float FittingUtil::AreaCoordinateMES(std::vector<float> &parameterList,
                                         std::vector<AreaCoordinateSamplingData *> &areaPointList, int fittingType) {
        float result = 0.0f;

        for (auto point : areaPointList) {
            float value = fittingType == 1 ? AreaCoordinateLinearFunction(parameterList, *point->getAreaPoint()) :
                          fittingType == 2 ? AreaCoordinateQuadraticFunction(parameterList, *point->getAreaPoint())
                                           : -1.0f;
            float model = pow(point->getValue() - value, 2);
            result += model;
        }

        result /= (areaPointList.size());
        return result;
    }

    /*   直角坐标拟合的误差   */
    float FittingUtil::DescartesCoordinateMES(std::vector<float> &parameterList,
                                              std::vector<DescartesCoordinateSamplingData *> &PointList,
                                              int fittingType) {
        float result = 0.0f;


        for (auto point : PointList) {
            float value = fittingType == 1 ? DescartesCoordinateLinearFunction(parameterList, *point->getPoint()) :
                          fittingType == 2 ? DescartesCoordinateQuadraticFunction(parameterList, *point->getPoint())
                                           : -1.0f;
            float model = pow(point->getValue() - value, 2);
            result += model;
        }

        result /= PointList.size();
        return result;
    }


}