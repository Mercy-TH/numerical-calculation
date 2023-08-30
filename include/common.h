//
// Created by tanhe on 2023/8/29.
//

#ifndef NUMERICAL_CALCULATION_COMMON_H
#define NUMERICAL_CALCULATION_COMMON_H

#include <vector>

using namespace std;

template<typename T>
vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] - v2[i];
    }
    return v;
}

template<typename T>
vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] + v2[i];
    }
    return v;
}

template<typename T>
vector<T> operator*(const vector<T> &v1, const T &num) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] * num;
    }
    return v;
}

template<typename T>
vector<T> operator*(const T &num, const vector<T> &v1) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] * num;
    }
    return v;
}

template<typename T>
vector<T> operator/(const vector<T> &v1, const T &num) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / num;
    }
    return v;
}

template<typename T>
vector<T> operator/(const T &num, const vector<T> &v1) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / num;
    }
    return v;
}

template<typename T>
vector<T> operator/(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / v2[i];
    }
    return v;
}


#endif //NUMERICAL_CALCULATION_COMMON_H
