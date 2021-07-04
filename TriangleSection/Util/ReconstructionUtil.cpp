//
// Created by WalterWhite on 2021/6/19.
//

#include "ReconstructionUtil.h"

namespace TriangleDomain {

    /*   将面积坐标下的拟合数据复原为图像的二维矩阵   */
    std::vector<std::vector<std::vector<SamplingData>>>
    ReconstructionUtil::ConvertAreaCoordinateCalculateDataToImageData(
            std::vector<AreaCoordinateSamplingData *> &calculateData, int row, int col, int fittingType) {
        std::vector<std::vector<std::vector<SamplingData>>> result;
        //  建立图像的二维矩阵
        std::vector<std::vector<SamplingData>> fitting;
        std::vector<std::vector<SamplingData>> mask;
        for (int i = 0; i < row; ++i) {
            std::vector<SamplingData> model(col);
            fitting.push_back(model);
            mask.push_back(model);
        }

        int max = -2147483648;
        int min = 2147483647;
        //  为每一个像素点赋值
        for (auto model:calculateData) {
            for (auto value:model->getFittingPara()) {
                if (value > max) {
                    max = value;
                    continue;
                }
                if (value < min) {
                    min = value;
                    continue;
                }
            }
            int modelRow = model->getPoint()->getX();
            int modelCol = model->getPoint()->getY();
            fitting[modelRow][modelCol].setPoint(model->getPoint());
            mask[modelRow][modelCol].setPoint(model->getPoint());
            model->QuantifyParameter();
            int value = AreaCoordinateFittingValue(model->getAreaPoint(), model->getFittingPara(), fittingType);
            if (value < 0)
                value = 0;
            if (value > 255)
                value = 255;
            fitting[modelRow][modelCol].setValue(value);
            mask[modelRow][modelCol].setValue(model->getLocation()[0] == 0 ? 255 : value);
        }

        result.push_back(fitting);
        result.push_back(mask);
        //  返回结果
        return result;
    }

    /*   将直角坐标下的拟合数据复原为图像的二维矩阵   */
    std::vector<std::vector<std::vector<SamplingData>>>
    ReconstructionUtil::ConvertDescartesCoordinateCalculateDataToImageData(
            std::vector<DescartesCoordinateSamplingData *> &calculateData, int row, int col, int fittingType) {
        std::vector<std::vector<std::vector<SamplingData>>> result;
        //  建立图像的二维矩阵
        std::vector<std::vector<SamplingData>> fitting;
        std::vector<std::vector<SamplingData>> mask;
        for (int i = 0; i < row; ++i) {
            std::vector<SamplingData> model(col);
            fitting.push_back(model);
            mask.push_back(model);
        }

        //  为每一个像素点赋值
        for (auto model:calculateData) {
            int modelRow = model->getPoint()->getX();
            int modelCol = model->getPoint()->getY();
            fitting[modelRow][modelCol].setPoint(model->getPoint());
            mask[modelRow][modelCol].setPoint(model->getPoint());
            int value = DescartesCoordinateFittingValue(model->getPoint(), model->getFittingPara(), fittingType);
            if (value < 0)
                value = 0;
            if (value > 255)
                value = 255;
            fitting[modelRow][modelCol].setValue(value);
            mask[modelRow][modelCol].setValue(model->getLocation()[0] == 0 ? 255 : value);
        }

        result.push_back(fitting);
        result.push_back(mask);
        //  返回结果
        return result;
    }

    /*   面积坐标下计算单个数据的拟合值   */
    float ReconstructionUtil::AreaCoordinateFittingValue(AreaPoint *areaPoint, std::vector<float> fitting_para,
                                                         int fittingType) {
        float result;

        switch (fittingType) {
            //  一次拟合
            case 1:
                result = FittingUtil::AreaCoordinateLinearFunction(fitting_para, *areaPoint);
                break;
                //  二次拟合
            case 2:
                result = FittingUtil::AreaCoordinateQuadraticFunction(fitting_para, *areaPoint);
                break;
        }

        return result;
    }

    /*   直角坐标下计算单个数据的拟合值   */
    float ReconstructionUtil::DescartesCoordinateFittingValue(Point *point, std::vector<float> fitting_para,
                                                              int fittingType) {
        float result;

        switch (fittingType) {
            //  一次拟合
            case 1:
                result = FittingUtil::DescartesCoordinateLinearFunction(fitting_para, *point);
                break;
                //  二次拟合
            case 2:
                result = FittingUtil::DescartesCoordinateQuadraticFunction(fitting_para, *point);
                break;
        }

        return result;
    }

    float ReconstructionUtil::ImagePSNR(std::vector<std::vector<SamplingData>> oringinImage,
                                        std::vector<std::vector<SamplingData>> recontructedImage) {
        if (oringinImage.size() != recontructedImage.size() || oringinImage[0].size() != recontructedImage[0].size())
            return -1.0f;

        float psnr = 0.0f;
        float mse = 0.0f;
        for (int i = 0; i < oringinImage.size(); ++i) {
            for (int j = 0; j < oringinImage[0].size(); ++j) {
                mse += pow(oringinImage[i][j].getValue() - recontructedImage[i][j].getValue(), 2);
            }
        }
        mse /= (oringinImage.size() * oringinImage[0].size());
        psnr = 20 * log10(255 / sqrt(mse));
        return psnr;
    }
}
