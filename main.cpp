//
// Created by tanhe on 2023/8/28.
//

#include <iostream>
#include "determinant.h"
#include "matrix.h"
#include <chrono>
#include <ctime>
#include <map>
#include <string>

using namespace std;


int main() {
    vector<vector<double>> vvv = {{8,  1,  -5, 1},
                                  {9,  -3, 0,  -6},
                                  {-5, 2,  -1, 2},
                                  {0,  4,  -7, 6}};//81
//    Determinant det(vvv);
//    double val = det.val;
//    cout << val << endl;
//
//    vector<vector<double>> v1 = {{-2, 4},
//                                 {1,  -2}};
//    vector<vector<double>> v2 = {{2,  4},
//                                 {-3, -6}};
//    Matrix m1(v1);
//    Matrix m2(v2);
//    m1.mul(m2);
//    m1.T();

    vector<vector<double>> vv = {{0, 1, 1, 1},
                                 {1, 0, 0, 0},
                                 {0, 1, 0, 0},
                                 {1, 0, 1, 0}};
    Matrix m3(vv);
    Matrix mm = m3.Pow(2);


    return 0;
}

