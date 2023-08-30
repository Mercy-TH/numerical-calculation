//
// Created by tanhe on 2023/8/28.
//

#ifndef NUMERICAL_CALCULATION_DET_H
#define NUMERICAL_CALCULATION_DET_H
#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include "common.h"

using namespace std;

class Det {
public:
    explicit Det(const vector<vector<double>> &vector);

    Det(Det const &det);

    double getValue(int i, int j);

    int getDegree() const;

    double getValue();

private:
    //行列式的阶数
    int _degree = (int) this->_v.size();
    vector<vector<double>> _v;

    //求阶乘
    int _cal_factorial(int n);

    //化上三角
    vector<vector<double>> _2uppertriangle(vector<vector<double>> &vec);

    //化主对角为非0
    vector<vector<double>> _2nonzerodiagonal(vector<vector<double>> &vec);

    //交换vector
    static void swap(vector<double> &v1, vector<double> &v2);

    //判断行列式某列是否成比例或者为0
    bool _judgedet(vector<vector<double>> &vec);

    //判断是否是上三角
    bool _istriangle(vector<vector<double>> &vec);
};


#endif //NUMERICAL_CALCULATION_DET_H
