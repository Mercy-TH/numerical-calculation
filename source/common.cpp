//
// Created by tanhe on 2023/9/1.
//
#include "common.h"

bool vectors_contain_zero(const vector<vector<double>> &vec) {
    bool contain_zero = false;
    for (int i = 0; i < vec[0].size(); i++) {
        if (contain_zero) { break; }
        for (int j = 0; j < vec[1].size(); j++) {
            if (vec[i][j] == 0.0) {
                contain_zero = true;
                break;
            }
        }
    }
    return contain_zero;
}

bool vector_contain_zero(const vector<double> &vec) {
    bool contain_zero = false;
    for (double i : vec) {
        if (i == 0.0) {
            contain_zero = true;
            break;
        }
    }
    return contain_zero;
}

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
vector<T> operator*(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] * v2[i];
    }
    return v;
}

template<typename T>
vector<T> operator/(const vector<T> &v1, const T &num) {
    if (num == 0) {
        std::cout << "Warning: divide by Zero Error." << std::endl;
        exit(1);
    }
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / num;
    }
    return v;
}

template<typename T>
vector<T> operator/(const T &num, const vector<T> &v1) {
    bool contain_zero;
    if (typeid(v1).name() == typeid(vector<T>).name()) {
        contain_zero = vector_contain_zero(v1);
    }
    if (typeid(v1).name() == typeid(vector<vector<T>>).name()) {
        contain_zero = vectors_contain_zero(v1);
    }
    if (contain_zero) {
        std::cout << "Warning: the division vector contains zero elements." << std::endl;
        exit(1);
    }
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / num;
    }
    return v;
}

template<typename T>
vector<T> operator/(const vector<T> &v1, const vector<T> &v2) {
    bool contain_zero;
    if (typeid(v2[0]).name() == typeid(T).name()) {
        contain_zero = vector_contain_zero(v2);
    }
    if (typeid(v2[0]).name() == typeid(vector<T>).name()) {
        contain_zero = vectors_contain_zero(v2);
    }
    if (contain_zero) {
        std::cout << "Warning: the division vector contains zero elements." << std::endl;
        exit(1);
    }
//    double nan = std::numeric_limits<double>::quiet_NaN();
    vector<T> v(v1);
    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] / v2[i];
    }
    return v;
}