//
// Created by WalterWhite on 2021/6/24.
//

#include "TriangleVFunc.h"

namespace TriangleDomain {

    Eigen::MatrixXf TriangleVFunc::TriangleV_matrix(const std::vector<AreaPoint *> &image, int n) {
        //  得到结果矩阵
        int row = image.size();
        int col = 3 * pow(4, (n - 1));
        Eigen::MatrixXf A = Eigen::MatrixXf::Ones(row, col);

        //  添加第一组的三个
        FirstV(image, n, A);

        //  添加第二组的9个
        GenerateV(image, 1, A);

        //  之后的动态添加
        AddV(image, A, n);

        return A;
    }

    /*   三角域V系统的第一组   */
    void TriangleVFunc::FirstV(const std::vector<AreaPoint *> &image, int n, Eigen::MatrixXf &matrix) {

        for (int i = 0; i < image.size(); ++i) {
            float u = image[i]->getU();
            float v = image[i]->getV();

            matrix(i, 0) = sqrt(2.0f);
            matrix(i, 1) = 6.0f * u - 2.0f;
            matrix(i, 2) = 2.0f * sqrt(3.0f) * (u + 2 * v - 1);

        }
    }

    /*   三角域V系统的第二组（生成元）   */
    void
    TriangleVFunc::GenerateV(const std::vector<AreaPoint *> &image, float scale, Eigen::MatrixXf &matrix) {
        for (int i = 0; i < image.size(); ++i) {

            float u = image[i]->getU();
            float v = image[i]->getV();
            float w = image[i]->getW();

            //  如果点在第一个三角形中
            if (u > 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 5.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 5.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 5.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (18.0f * u - 12.0f);
                matrix(i, 4) = 0.0f;
                matrix(i, 5) = 0.0f;

                matrix(i, 6) = scale * (-12.0f * w + 12.0f * v);
                matrix(i, 7) = 0.0f;
                matrix(i, 8) = 0.0f;

                continue;
            }

            //  如果在第二个三角形中
            if (v > 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 1.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 1.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 1.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.0f);
                matrix(i, 4) = scale * 2.0f * sqrt(6.0f) / 3.0f * (-12.0 * u - 2.0f);
                matrix(i, 5) = 0.0f;

                matrix(i, 6) = scale * (4.0f * w - 4.0f * v + 2.0f);
                matrix(i, 7) = scale * -sqrt(8.0f) * (-4.0f * u - 8.0f * v + 6.0f);
                matrix(i, 8) = 0.0f;

                continue;
            }

            //  如果在第四个三角形中
            if (w > 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 1.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 1.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 1.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.0f);
                matrix(i, 4) = scale * 2.0f * sqrt(6.0f) / 3.0f * (-6.0 * u + 1.0f);
                matrix(i, 5) = scale * sqrt(8.0f) * (6.0f * u - 1.0f);

                matrix(i, 6) = scale * (4.0f * w - 4.0f * v - 2.0f);
                matrix(i, 7) = scale * -sqrt(8.0f) * (2.0f * u + 4.0f * v - 1.0f);
                matrix(i, 8) = scale * -sqrt(24.0f) * (-2.0f * u - 4.0f * v + 1.0f);

                continue;
            }

            //  如果在第三个三角形中
            if (u < 0.5f && v < 0.5f && w < 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 1.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 1.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 1.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 2.0f);
                matrix(i, 4) = scale * 2.0f * sqrt(6.0f) / 3.0f * (-6.0 * u + 2.0f);
                matrix(i, 5) = scale * sqrt(8.0f) * (-6.0f * u + 2.0f);

                matrix(i, 6) = scale * (4.0f * w - 4.0f * v);
                matrix(i, 7) = scale * -sqrt(8.0f) * (2.0f * u + 4.0f * v - 2.0f);
                matrix(i, 8) = scale * -sqrt(24.0f) * (2.0f * u + 4.0f * v - 2.0f);

                continue;
            }

            //  在第一和第三个三角形的交界处
            if (u == 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 3.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 3.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 3.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (6.0f * u - 5.0f);
                matrix(i, 4) = scale * sqrt(6.0f) / 3.0f * (-6.0f * u + 2.0f);
                matrix(i, 5) = scale * sqrt(2.0f) * (-6.0f * u + 2.0f);

                matrix(i, 6) = scale * (-4.0f * w + 4.0f * v);
                matrix(i, 7) = scale * -sqrt(2.0f) * (2.0f * u + 4.0f * v - 2.0f);
                matrix(i, 8) = scale * -sqrt(6.0f) * (2.0f * u + 4.0f * v - 2.0f);

                continue;
            }

            //  在第二个和第三个三角形的交界处
            if (v == 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 1.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 1.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 1.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.5f);
                matrix(i, 4) = scale * sqrt(24.0f) / 3.0f * (-9.0 * u);
                matrix(i, 5) = scale * sqrt(2.0f) * (-6.0 * u + 2.0f);

                matrix(i, 6) = scale * (4.0f * w - 4.0f * v + 1.0f);
                matrix(i, 7) = scale * -sqrt(2.0f) * (-2.0f * u - 4.0f * v + 4.0f);
                matrix(i, 8) = scale * -sqrt(6.0f) * (2.0f * u + 4.0f * v - 2.0f);

                continue;
            }

            //  在第三个和第四个三角形的交界处
            if (w == 0.5f) {
                matrix(i, 0) = scale * sqrt(2.0f) * (-6.0f * u + 1.0f);
                matrix(i, 1) = scale * sqrt(2.0f) * (-6.0f * v + 1.0f);
                matrix(i, 2) = scale * sqrt(2.0f) * (-6.0f * w + 1.0f);

                matrix(i, 3) = scale * 2.0f / sqrt(3.0f) * (-6.0f * u + 1.5f);
                matrix(i, 4) = scale * sqrt(24.0f) / 3.0f * (-6.0 * u + 1.5f);
                matrix(i, 5) = scale * sqrt(2.0f);

                matrix(i, 6) = scale * (4.0f * w - 4.0f * v - 1.0f);
                matrix(i, 7) = scale * -sqrt(2.0f) * (4.0f * u + 8.0f * v - 3.0f);
                matrix(i, 8) = scale * sqrt(6.0f);

                continue;
            }
        }

    }

    /*   第三组开始的三角域V系统（迭代生成）   */
    void TriangleVFunc::AddV(const std::vector<AreaPoint *> &image, Eigen::MatrixXf &matrix, int groupCount) {
        //  设置初始三角形
        AreaCoordinateTriangle triangle(new AreaPoint(1.0f, 0.0f, 0.0f),
                                        new AreaPoint(0.0f, 1.0f, 0.0f),
                                        new AreaPoint(0.0f, 0.0f, 1.0f));

        //  进行迭代求矩阵
        SetVmatrix(image, matrix, triangle, 3, groupCount);

    }

    /*   求解第三组之后的矩阵   */
    void TriangleVFunc::SetVmatrix(const std::vector<AreaPoint *> image, Eigen::MatrixXf matrix,
                                   AreaCoordinateTriangle triangle, int currentGroup, int groupCount) {
        //  先得到剖分后的三角形
        std::vector<AreaCoordinateTriangle> subTriangle = GetSubTriangle(triangle);

        //  判断图像中哪些点在三角形中，并对其中的点进行仿射变换
        for (auto currentTriangle: subTriangle) {
//            std::vector<AreaPoint *> current
        }
    }

    /*   得到剖分后的三角形   */
    std::vector<AreaCoordinateTriangle> TriangleVFunc::GetSubTriangle(AreaCoordinateTriangle originTriangle) {
        std::vector<AreaCoordinateTriangle> res;

        AreaPoint *A = originTriangle.getVertex1();
        AreaPoint *B = originTriangle.getVertex2();
        AreaPoint *C = originTriangle.getVertex3();

        AreaPoint *AB = new AreaPoint(
                (A->getU() + B->getU()) / 2.0f,
                (A->getV() + B->getU()) / 2.0f,
                (A->getW() + B->getW()) / 2.0f
        );
        AreaPoint *BC = new AreaPoint(
                (B->getU() + C->getU()) / 2.0f,
                (B->getV() + C->getV()) / 2.0f,
                (B->getW() + C->getW()) / 2.0f
        );
        AreaPoint *CA = new AreaPoint(
                (C->getU() + A->getU()) / 2.0f,
                (C->getV() + A->getV()) / 2.0f,
                (C->getW() + A->getW()) / 2.0f
        );

        AreaCoordinateTriangle sub_1(A, AB, CA);
        AreaCoordinateTriangle sub_2(AB, B, BC);
        AreaCoordinateTriangle sub_3(BC, CA, AB);
        AreaCoordinateTriangle sub_4(CA, BC, C);

        res.push_back(sub_1);
        res.push_back(sub_2);
        res.push_back(sub_3);
        res.push_back(sub_4);


        delete CA;
        delete BC;
        delete AB;
        return res;
    }


}
