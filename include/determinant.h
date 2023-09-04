//
// Created by tanhe on 2023/8/28.
//

#ifndef NUMERICAL_CALCULATION_DETERMINANT_H
#define NUMERICAL_CALCULATION_DETERMINANT_H

#include <vector>
#include <iostream>
#include <cmath>
#include "common.h"

using namespace std;


class Determinant {
public:
    explicit Determinant(vector<double> &vec);

    explicit Determinant(vector<vector<double>> &vec);

    Determinant(Determinant const &det);

    ~Determinant() = default;

    vector<double> v1;
    vector<vector<double>> v2;
    //行列式的阶数
    int degree;
    //行列式的值
    double val;
private:
    double getVal();

    //逆序数
    static int inverseOrderNum(vector<int> &vec);

    //求阶乘
    int cal_factorial(int n);

    //全排列
    void permute(int start, vector<int> &vec, vector<vector<int>> &result);

    //按索引交换vector里面的元素
    static void swap(vector<int> &vec, int a, int b);

};


#endif //NUMERICAL_CALCULATION_DETERMINANT_H
