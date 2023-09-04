//
// Created by tanhe on 2023/8/28.
//
#include "determinant.h"


Determinant::Determinant(vector<double> &vec) {
    if (fmod((double) sqrt(vec.size()), 1.0) != 0.0) {
        std::cout << "The rows and columns of the determinant must be equal." << std::endl;
        exit(1);
    }
    v1 = vec;
    int n = (int) sqrt(vec.size());
    for (int i = 0; i < n; i++) {
        vector<double> tmp;
        tmp.reserve(n);
        for (int j = 0; j < n; j++) {
            tmp.push_back(vec[i * n + j]);
        }
        v2.push_back(tmp);
    }
    degree = n;
    val = getVal();
}

Determinant::Determinant(vector<vector<double>> &vec) {

    if ((int) vec.size() != (int) vec[0].size()) {
        std::cout << "The rows and columns of the determinant must be equal." << std::endl;
        exit(1);
    }
    v2 = vec;
    vector<double> v;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            v.push_back(vec[i][j]);
        }
    }
    v1 = v;
    degree = (int) vec.size();
    val = getVal();
}

Determinant::Determinant(const Determinant &det) {
    v1 = det.v1;
    v2 = det.v2;
    degree = det.degree;
    val = det.val;
}

double Determinant::getVal() {
    if (degree == 1) { return v1[0]; }
    //索引值
    vector<int> nums;
    nums.reserve(degree);
    for (int i = 0; i < degree; i++) { nums.push_back(i); }
    //全排列
    vector<vector<int>> permutations;
    permute(0, nums, permutations);
    //行列式值
    double res = 0.0;
    for (auto &permutation : permutations) {
        //逆序数
        double tao = -1;
        if (fmod(Determinant::inverseOrderNum(permutation), 2) == 0) {
            tao = 1;
        }
        double num = 1.0;
        for (int ii = 0; ii < degree; ii++) {
            num *= v2[ii][permutation[ii]];
        }
        res += tao * num;
    }
    return res;
}

int Determinant::inverseOrderNum(vector<int> &vec) {
    int tao = 0;
    for (int i = 0; i < vec.size(); i++) {
        int j = i;
        while (j < vec.size()) {
            if (vec[j] < vec[i]) { tao += 1; }
            j++;
        }
    }
    return tao;
}

int Determinant::cal_factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * cal_factorial(n - 1);
    }
}

void Determinant::permute(int start, vector<int> &vec, vector<vector<int>> &result) {
    if (start == vec.size() - 1) {
        result.push_back(vec);
        return;
    }
    for (int i = start; i < vec.size(); i++) {
        Determinant::swap(vec, i, start);
        permute(start + 1, vec, result);
        Determinant::swap(vec, start, i);
    }
}

void Determinant::swap(vector<int> &vec, int a, int b) {
    int c = vec[a];
    vec[a] = vec[b];
    vec[b] = c;
}