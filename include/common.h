//
// Created by tanhe on 2023/8/29.
//

#ifndef NUMERICAL_CALCULATION_COMMON_H
#define NUMERICAL_CALCULATION_COMMON_H

#include <vector>
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;

bool vectors_contain_zero(const vector<vector<double>> &vec);

bool vector_contain_zero(const vector<double> &vec);

template<typename T>
vector<T> operator-(const vector<T> &v1, const vector<T> &v2);

template<typename T>
vector<T> operator+(const vector<T> &v1, const vector<T> &v2);

template<typename T>
vector<T> operator*(const vector<T> &v1, const T &num);

template<typename T>
vector<T> operator*(const T &num, const vector<T> &v1);

template<typename T>
vector<T> operator*(const vector<T> &v1, const vector<T> &v2);

template<typename T>
vector<T> operator/(const vector<T> &v1, const T &num);

template<typename T>
vector<T> operator/(const T &num, const vector<T> &v1);

template<typename T>
vector<T> operator/(const vector<T> &v1, const vector<T> &v2);


#endif //NUMERICAL_CALCULATION_COMMON_H
