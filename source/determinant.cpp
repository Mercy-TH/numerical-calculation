//
// Created by tanhe on 2023/8/28.
//
#include "determinant.h"


double Det::getValue() {
    double val = 1.0;
    if (this->_judgedet(this->_v)) { return 0; }
    if (this->_istriangle(this->_v)) {
        for (int i = 0; i < this->_degree; i++) {
            val *= this->_v[i][i];
        }
        return val;
    }
    this->_v = this->_2nonzerodiagonal(this->_v);
    for (int i = 0; i < this->_degree; i++) {
        val *= this->_2uppertriangle(this->_v)[i][i];
    }
    return val;
}

Det::Det(const vector<vector<double>> &vec) {
    if (vec.size() != vec[0].size()) {
        std::cout << "The rows and columns of the determinant must be equal." << std::endl;
        exit(1);
    }
    this->_v = vec;
    this->_degree = (int) vec.size();
}

double Det::getValue(int i, int j) {
    if (i > this->_degree or j > this->_degree) {
        std::cout << "Index value exceeding determinant." << std::endl;
        exit(1);
    }
    double v;
    for (int i_ = 0; i_ < this->_degree; i_++) {
        for (int j_ = 0; j_ < this->_degree; j_++) {
            if (i_ == i and j_ == j) { v = this->_v[i][j]; }
        }
    }
    return v;
}

Det::Det(Det const &det) {
    this->_v = det._v;
    this->_degree = det._degree;
}

int Det::getDegree() const {
    return this->_degree;
}

int Det::_cal_factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * this->_cal_factorial(n - 1);
    }
}

bool Det::_judgedet(vector<vector<double>> &vec) {
    bool is_zero = false;
    bool is_times = false;
    for (int i = 0; i < this->_degree; i++) {

        //判断是否有0行
        is_zero = std::all_of(this->_v[i].begin(), this->_v[i].end(), [](double ii) { return ii == 0.0; });
        if (is_zero) {
            is_zero = true;
            break;
        }

        //判断行是否成比例
        int idx = i + 1;
        while (idx < this->_degree) {
            auto r = this->_v[i] / this->_v[idx];
            double data = r[0];
            int n = 0;
            for (int lll = 1; lll < r.size(); lll++) {
                if (data == r[lll]) {
                    n += 1;
                }
            }
            if (n == r.size() - 1) { is_times = true; }

            if (is_times) { break; }
            idx++;
        }
        if (is_times) { break; }

        //判断是否有0列
        int idy = 0;
        vector<double> temp;
        while (idy < this->_degree) {
            temp.push_back(this->_v[idy][i]);
            idy++;
        }
        is_zero = std::all_of(temp.begin(), temp.end(), [](double ii) { return ii == 0.0; });
        if (is_zero) {
            is_zero = true;
            break;
        }

        //判断列是否成比例
        vector<double> cur_col;
        cur_col.reserve(this->_degree);
        for (int cc = 0; cc < this->_degree; cc++) {
            cur_col.push_back(this->_v[cc][i]);
        }
        int col = 0;
        vector<double> ind;
        while (col < this->_degree) {
            if (col != i) {
                ind.push_back(col);
            }
            col++;
        }
        for (double k : ind) {
            vector<double> cur_col1;
            cur_col1.reserve(this->_degree);
            for (int ppp = 0; ppp < this->_degree; ppp++) {
                cur_col1.push_back(this->_v[ppp][(int) k]);
            }
            vector<double> cur_div = cur_col / cur_col1;
            double data = cur_div[0];
            int num = 0;
            for (int lll = 1; lll < cur_div.size(); lll++) {
                if (data == cur_div[lll]) {
                    num += 1;
                }
            }
            if (num == cur_div.size() - 1) { is_times = true; }
            if ((is_times)) { break; }
        }
        if (is_times) { break; }
    }
    return is_zero or is_times;
}

bool Det::_istriangle(vector<vector<double>> &vec) {
    vector<double> down_fac;
    vector<double> upper_fac;
    for (int i = 0; i < this->_degree; i++) {
        for (int j = i + 1; j < this->_degree; j++) {
            down_fac.push_back(this->_v[i][j]);
            upper_fac.push_back(this->_v[j][i]);
        }
    }
    bool is_down = std::all_of(down_fac.begin(), down_fac.end(), [](double i) { return i == 0.0; });
    bool is_upper = std::all_of(upper_fac.begin(), upper_fac.end(), [](double i) { return i == 0.0; });
    return is_upper or is_down;
}

vector<vector<double>> Det::_2uppertriangle(vector<vector<double>> &vec) {
    int degree = (int) vec.size();
    for (int i = 0; i < degree; i++) {
        for (int j = degree - 1; j > i; j--) {
            double times = -this->_v[j][i] / this->_v[i][i];
            vec[j] = vec[i] * times + vec[j];
        }
    }
    return vec;
}

vector<vector<double>> Det::_2nonzerodiagonal(vector<vector<double>> &vec) {
    vector<double> n1, n2;
    for (int i = 0; i < this->_degree; i++) {
        if (vec[i][i] != 0) {
            n1.push_back(i);
        } else(n2.push_back(i));
    }
    if (n2.empty()) {
        return vec;
    }
    double flag = 1.0;
    for (auto idx:n2) {
        for (int i = 0; i < this->_degree; i++) {
            if (this->_v[i][i + 1] != 0 and this->_v[(int) idx + 1][(int) idx] != 0) {
                Det::swap(this->_v[i + 1], this->_v[(int) idx]);
                flag *= -1.0;
                break;
            }
        }
    }
    for (int i = 0; i < this->_degree; i++) {
        this->_v[i] = this->_v[i] * flag;
    }
    return vec;
}

void Det::swap(vector<double> &v1, vector<double> &v2) {
    vector<double> tmp = v1;
    v1 = v2;
    v2 = tmp;
}
