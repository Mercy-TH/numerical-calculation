//
// Created by tanhe on 2023/8/28.
//

#include <iostream>
#include "determinant.h"

using namespace std;

int main() {
////    system("pause");
    vector<vector<double>> vvv = {{8,  1,  -5, 1},
                                  {9,  -3, 0,  -6},
                                  {-5, 2,  -1, 2},
                                  {0,  4,  -7, 6}};//81
    Det det(vvv);
    double vv = det.getValue();
    cout << vv << endl;
    return 0;
}

