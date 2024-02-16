/*
** EPITECH PROJECT, 2024
** Matrix.hpp
** File description:
** Matrix.hpp
*/

#pragma once

#include <array>
#include <iostream>

template<unsigned int Row, unsigned int Column>
class Matrix {
public:
    Matrix()
    {
        for (auto& row : _matrix)
            for (auto& column : row)
                column = 0;
    }

    Matrix(const Matrix<Row, Column>& other) = default;
    Matrix<Row, Column>& operator=(const Matrix<Row, Column>& other) = default;

    ~Matrix() = default;

    double operator()(unsigned int row, unsigned int col) const
    {
        return _matrix[row][col];
    }

    double& operator()(unsigned int row, unsigned int col)
    {
        return _matrix[row][col];
    }

    template<unsigned int Column2>
    Matrix<Row, Column2> operator*(const Matrix<Column, Column2>& other) const
    {
        Matrix<Row, Column2> result;

        for (unsigned int row = 0; row < Row; row++)
            for (unsigned int col = 0; col < Column2; col++)
                for (unsigned int i = 0; i < Column; i++)
                    result(row, col) += _matrix[row][i] * other(i, col);

        return result;
    }

    template<unsigned int Row2>
    Matrix<Row, Row2>& operator*=(const Matrix<Column, Row2>& other)
    {
        *this = *this * other;
        return *this;
    }


private:
    std::array<std::array<double, Column>, Row> _matrix;
};

template<unsigned int Row, unsigned int Column>
std::ostream& operator<<(std::ostream& os, const Matrix<Row, Column>& matrix)
{
    os << "[";

    for (unsigned int row = 0; row < Row; row++) {
        if (row != 0)
            os << ", ";

        os << "[";

        for (unsigned int col = 0; col < Column; col++) {
            if (col != 0)
                os << ", ";
            os << matrix(row, col);
        }

        os << "]";
    }

    os << "]";

    return os;
}
