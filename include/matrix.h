//
// Created by tanhe on 2023/8/31.
//

#ifndef NUMERICAL_CALCULATION_MATRIX_H
#define NUMERICAL_CALCULATION_MATRIX_H

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <limits>
#include <numeric>
#include <map>
#include <string>
#include "determinant.h"
#include "common.h"

using namespace std;

bool vectors_contain_zero(vector<vector<double>> &vec);

bool vector_contain_zero(vector<double> &vec);

class Matrix {
public:
    Matrix(Matrix &m);

    Matrix(Matrix const &m);

    explicit Matrix(vector<vector<double>> &vec);


    ~Matrix() = default;

    //行数
    int rows{};
    //列数
    int cols{};
//    //秩
//    double rank;
    //方阵乘积的行列式
    double det{};

    double getDet();

    vector<vector<double>> val;
    //形状
    vector<int> shape;

    //转置    T
    Matrix T();

    //伴随    adj
    Matrix Adj();

    //逆     inv
    Matrix Inv();

    //幂     power
    Matrix Pow(int n);

    bool operator==(const Matrix &m) const;

    //加法
    Matrix operator+(Matrix &m);

    //减法
    Matrix operator-(Matrix &m);

    //数乘
    Matrix operator*(double &num);

    //点乘
    Matrix operator*(Matrix &m);

    //矩阵乘法
    Matrix mul(Matrix &m);
    //零矩阵
    //单位矩阵
    //对角矩阵
    //反对称矩阵
    //上三角矩阵
    //下三角矩阵
    //对称矩阵
    //正交矩阵
    //矩阵方程

private:
//    int getRank();
//    double getDet();
};

#endif //NUMERICAL_CALCULATION_MATRIX_H
