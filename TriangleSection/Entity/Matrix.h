//
// Created by WalterWhite on 2021/6/10.
//

#ifndef TRIANGLEDOMAIN_MATRIX_H
#define TRIANGLEDOMAIN_MATRIX_H

#include <vector>
#include <iostream>

namespace TriangleDomain {
    template<typename T>
    class Matrix {
    private:
        std::vector<std::vector<T>> matrix;
        int rows;
        int cols;

    public:
        static Matrix Zeros(int row, int col);

        static Matrix Ones(int row, int col);

        Matrix();

        explicit Matrix(const std::vector<std::vector<T>> &matrix);

        Matrix(const Matrix<T> &rhs);

        Matrix &operator=(const Matrix<T> &rhs);

        const std::vector<std::vector<T>> &getMatrix() const;

        void setMatrix(const std::vector<std::vector<T>> &matrix);

        int getRows() const;

        void setRows(int rows);

        int getCols() const;

        void setCols(int cols);

        Matrix operator*(const Matrix<T> &lhs, const Matrix<T> &rhs);

        Matrix &transpose();

        Matrix inverse();

    };

    template<typename T>
    Matrix Matrix<T>::Zeros(int row, int col) {
        Matrix<T> result;
        result.setRows(row);
        result.setCols(col);

        std::vector<std::vector<T>> matrix;
        for (int i = 0; i < rows; ++i) {
            std::vector<T> model;
            for (int j = 0; j < col; ++j) {
                model.push_back(0);
            }
            matrix.push_back(model);
        }
        result.setMatrix(matrix);
        return result;
    }

    template<typename T>
    Matrix Matrix<T>::Ones(int row, int col) {
        Matrix<T> result;
        result.setRows(row);
        result.setCols(col);

        std::vector<std::vector<T>> matrix;
        for (int i = 0; i < rows; ++i) {
            std::vector<T> model;
            for (int j = 0; j < col; ++j) {
                model.push_back(1);
            }
            matrix.push_back(model);
        }
        result.setMatrix(matrix);
        return result;
    }


    template<typename T>
    Matrix<T>::Matrix() {
        this->rows = 0;
        this->cols = 0;
    }

    template<typename T>
    Matrix<T>::Matrix(const std::vector<std::vector<T>> &matrix):matrix(matrix) {
        this->rows = matrix.size();
        this->cols = matrix[0].size();
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix<T> &rhs) {
        this->matrix = rhs.matrix;
        this->rows = rhs.rows;
        this->cols = rhs.cols;
    }

    template<typename T>
    Matrix &Matrix<T>::operator=(const Matrix<T> &rhs) {
        this->matrix = rhs.matrix;
        this->rows = rhs.rows;
        this->cols = rhs.cols;
        return *this;
    }

    template<typename T>
    Matrix Matrix<T>::operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        if (lhs.cols != rhs.rows) {
            std::cout << "ERROR::Matrix Multiplication has Error::the row and col is incorrect" << std::endl;
            return;
        }
        Matrix<T> res;
        std::vector<std::vector<T>> matrix;

        for (int i = 0; i < lhs.rows; ++i) {
            std::vector<T> model;
            for (int j = 0; j < rhs.cols; ++j) {
                T element;
                for (int k = 0; k < lhs.cols; ++k) {
                    element += lhs.matrix[i][k] * rhs.matrix[k][j];
                }
                model.push_back(element);
            }
            matrix.push_back(model);
        }
        res.setMatrix(matrix);
        res.setRows(lhs.rows);
        res.setCols(rhs.cols);

        return res;
    }


    template<typename T>
    Matrix &Matrix<T>::transpose() {
        int row = this->cols;
        int col = this->rows;
        std::vector<std::vector<T>> res;

        for (int i = 0; i < row; ++i) {
            std::vector<T> model;
            for (int j = 0; j < col; ++j) {
                model.push_back(this->matrix[j][i]);
            }
            res.push_back(model);
        }

        this->matrix = res;
        return *this;
    }

    template<typename T>
    const std::vector<std::vector<T>> &Matrix<T>::getMatrix() const {
        return matrix;
    }

    template<typename T>
    void Matrix<T>::setMatrix(const std::vector<std::vector<T>> &matrix) {
        Matrix::matrix = matrix;
    }

    template<typename T>
    int Matrix<T>::getRows() const {
        return rows;
    }

    template<typename T>
    void Matrix<T>::setRows(int rows) {
        Matrix::rows = rows;
    }

    template<typename T>
    int Matrix<T>::getCols() const {
        return cols;
    }

    template<typename T>
    void Matrix<T>::setCols(int cols) {
        Matrix::cols = cols;
    }

}


#endif //TRIANGLEDOMAIN_MATRIX_H
