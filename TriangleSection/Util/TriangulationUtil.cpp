//
// Created by WalterWhite on 2021/6/9.
//

#include "TriangulationUtil.h"

namespace TriangleDomain {

    /*   面积坐标下的三角剖分   */
    std::vector<std::vector<std::vector<SamplingData>>>
    TriangulationUtil::AreaCoordinateTriangulation(const std::vector<std::vector<SamplingData>> &image,
                                                   int fittingType, float permitError) {
        // 将数据转换为面积坐标形式
        auto AreaCoordinateData = ConvertImageToAreaCoordinate(image);
        // 初始三角网格划分
        auto initialTriangleList = TriangulationUtil::initialTriangulation(image);
        int flag = 1;

        std::vector<AreaCoordinateSamplingData *> model;
        for (const auto &initialTriangle : initialTriangleList) {
            //  对每个初始划分好的三角形进行拟合
            auto samplingData = AreaCoordinateSelectPoint(initialTriangle, AreaCoordinateData, flag, fittingType,
                                                          permitError);
            flag++;

            //  将计算得到的数据添加到结果集合
            model.insert(model.end(), samplingData.begin(), samplingData.end());
        }

        //  将计算得到的记过转换为重建信息
        std::vector<std::vector<std::vector<SamplingData>>> result;

        result = ReconstructionUtil::ConvertAreaCoordinateCalculateDataToImageData(model, image.size(), image[0].size(),
                                                                                   fittingType);

        return result;
    }

    /*   直角坐标下的三角剖分   */
    std::vector<std::vector<std::vector<SamplingData>>>
    TriangulationUtil::DescartesCoordinatesTriangulation(const std::vector<std::vector<SamplingData>> &image,
                                                         int fittingType, float permitError) {
        // 将数据转换为面积坐标形式
        auto DescartesCoordinateData = ConvertImageToDescartesCoordinate(image);
        // 初始三角网格划分
        auto initialTriangleList = TriangulationUtil::initialTriangulation(image);
        int flag = 1;

        std::vector<DescartesCoordinateSamplingData *> model;
        for (const auto &initialTriangle : initialTriangleList) {
            //  对每个初始划分好的三角形进行拟合
            auto samplingData = DescartesCoordinateSelectPoint(initialTriangle, DescartesCoordinateData, flag,
                                                               fittingType,
                                                               permitError);
            flag++;

            //  将计算得到的数据添加到结果集合
            model.insert(model.end(), samplingData.begin(), samplingData.end());
        }

        //  将计算得到的记过转换为重建信息
        std::vector<std::vector<std::vector<SamplingData>>> result;

        result = ReconstructionUtil::ConvertDescartesCoordinateCalculateDataToImageData(model, image.size(),
                                                                                        image[0].size(),
                                                                                        fittingType);

        return result;
    }

    /*   将图像转换为携带面积坐标信息的数据   */
    std::vector<AreaCoordinateSamplingData *>
    TriangulationUtil::ConvertImageToAreaCoordinate(const std::vector<std::vector<SamplingData>> &imageData) {
        std::vector<AreaCoordinateSamplingData *> result;

        for (int i = 0; i < imageData.size(); ++i) {
            for (int j = 0; j < imageData[0].size(); ++j) {
                result.push_back(new AreaCoordinateSamplingData(imageData[i][j]));
            }
        }

        return result;
    }

    /*   将图像转换为携带直角坐标信息的数据  */
    std::vector<DescartesCoordinateSamplingData *>
    TriangulationUtil::ConvertImageToDescartesCoordinate(const std::vector<std::vector<SamplingData>> &imageData) {
        std::vector<DescartesCoordinateSamplingData *> result;

        for (int i = 0; i < imageData.size(); ++i) {
            for (int j = 0; j < imageData[0].size(); ++j) {
                result.push_back(new DescartesCoordinateSamplingData(imageData[i][j]));
            }
        }

        return result;
    }

    /*   获得初始的三角形   */
    std::vector<Triangle> TriangulationUtil::initialTriangulation(const std::vector<std::vector<SamplingData>> &image) {
        std::vector<Triangle> result;

        unsigned int row = image.size() - 1;
        unsigned int col = image[0].size() - 1;

        Point vertexA;
        Point vertexB;
        Point vertexC;

        vertexA.setX(image[0][0].getPoint()->getX() - 0.5f);
        vertexA.setY(image[0][0].getPoint()->getY() - 0.5f);
        vertexB.setX(image[row][0].getPoint()->getX() + 0.5f);
        vertexB.setY(image[row][0].getPoint()->getY() - 0.5f);
        vertexC.setX(image[row][col].getPoint()->getX() + 0.5f);
        vertexC.setY(image[row][col].getPoint()->getY() + 0.5f);

        Triangle model(&vertexA, &vertexB, &vertexC);
        result.push_back(model);

        vertexB.setX(image[0][col].getPoint()->getX() - 0.5f);
        vertexB.setY(image[0][col].getPoint()->getY() + 0.5f);
        model = Triangle(&vertexC, &vertexB, &vertexA);

        result.push_back(model);

        return result;
    }

    /*   面积坐标下的三角剖分拟合   */
    std::vector<AreaCoordinateSamplingData *> TriangulationUtil::AreaCoordinateSelectPoint(const Triangle triangle,
                                                                                           std::vector<AreaCoordinateSamplingData *> &AreaCoordinateData,
                                                                                           int triangleNumber,
                                                                                           int fittingType,
                                                                                           float permitError) {
        std::vector<AreaCoordinateSamplingData *> selectedPoint;

        // 先判断是否在三角形中
        for (auto point:AreaCoordinateData) {
            int flag = triangle.isPointInTriangle(point->getPoint());
            if (flag >= 0) {
                point->setSingleDataToLocation(triangleNumber);
                if (flag == 0 || isNearEdge(triangle, point->getPoint()))
                    point->setLocation(std::vector<int>{0});
                point->setTriangle(const_cast<Triangle *>(&triangle));
                point->setAreaPoint(triangle);
                selectedPoint.push_back(point);
            }
        }
        std::vector<float> fittingParameter;
        // 做最小二乘拟合
        float error = FittingUtil::AreaCoordinateFitting(selectedPoint, fittingType, fittingParameter);

        //当误差大于阈值时，继续剖分
        if (error > permitError && selectedPoint.size() > 10) {
            auto subTriangleList = triangle.triangleSection();

            AreaCoordinateSelectPoint(subTriangleList[0], selectedPoint, 1, fittingType, permitError);
            AreaCoordinateSelectPoint(subTriangleList[1], selectedPoint, 2, fittingType, permitError);
            AreaCoordinateSelectPoint(subTriangleList[2], selectedPoint, 3, fittingType, permitError);
            AreaCoordinateSelectPoint(subTriangleList[3], selectedPoint, 4, fittingType, permitError);
        }
        //  如果已经满足要求，则将拟合系数写入
        if (error <= permitError || selectedPoint.size() <= 10) {
            for (int i = 0; i < selectedPoint.size(); ++i) {
                selectedPoint[i]->setFittingPara(fittingParameter);
            }
        }

        return selectedPoint;
    }

    /*   直角坐标下的三角剖分拟合   */
    std::vector<DescartesCoordinateSamplingData *>
    TriangulationUtil::DescartesCoordinateSelectPoint(const Triangle triangle,
                                                      std::vector<DescartesCoordinateSamplingData *> &DescartesCoordinateData,
                                                      int triangleNumber, int fittingType, float permitError) {
        std::vector<DescartesCoordinateSamplingData *> selectedPoint;

        // 先判断是否在三角形中
        for (auto point:DescartesCoordinateData) {
            int flag = triangle.isPointInTriangle(point->getPoint());
            if (flag >= 0) {
                point->setSingleDataToLocation(triangleNumber);
                if (flag == 0 || isNearEdge(triangle, point->getPoint()))
                    point->setLocation(std::vector<int>{0});
                point->setTriangle(const_cast<Triangle *>(&triangle));
                selectedPoint.push_back(point);
            }
        }
        std::vector<float> fittingParameter;
        // 做最小二乘拟合
        float error = FittingUtil::DescartesCoordinateFitting(selectedPoint, fittingType, fittingParameter);

        //当误差大于阈值时，继续剖分
        if (error > permitError && selectedPoint.size() > 10) {
            auto subTriangleList = triangle.triangleSection();

            DescartesCoordinateSelectPoint(subTriangleList[0], selectedPoint, 1, fittingType, permitError);
            DescartesCoordinateSelectPoint(subTriangleList[1], selectedPoint, 2, fittingType, permitError);
            DescartesCoordinateSelectPoint(subTriangleList[2], selectedPoint, 3, fittingType, permitError);
            DescartesCoordinateSelectPoint(subTriangleList[3], selectedPoint, 4, fittingType, permitError);
        }
        //  如果已经满足要求，则将拟合系数写入
        if (error <= permitError || selectedPoint.size() <= 10) {
            for (int i = 0; i < selectedPoint.size(); ++i) {
                selectedPoint[i]->setFittingPara(fittingParameter);
            }
        }

        return selectedPoint;
    }

    bool TriangulationUtil::isNearEdge(const Triangle triangle, Point *point) {
        int x;
        int y;

        std::vector<int> x_list;
        std::vector<int> y_list;
        x_list.push_back(triangle.getVertexA()->getX());
        y_list.push_back(triangle.getVertexA()->getY());

        x_list.push_back(triangle.getVertexB()->getX());
        y_list.push_back(triangle.getVertexB()->getY());

        x_list.push_back(triangle.getVertexC()->getX());
        y_list.push_back(triangle.getVertexC()->getY());

        x_list.push_back(triangle.getVertexA()->getX());
        y_list.push_back(triangle.getVertexA()->getY());

        for (int i = 0; i < 3; ++i) {
            if (x_list[i] == x_list[i + 1]) {
                x = x_list[i];
            }
            if (y_list[i] == y_list[i + 1]) {
                y = y_list[i];
            }
        }

        if ((int) point->getX() == x || (int) point->getY() == y) {
            return true;
        }
        return false;
    }
}