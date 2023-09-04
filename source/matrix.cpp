//
// Created by tanhe on 2023/8/31.
//
#include "matrix.h"

bool vectors_contain_zero(vector<vector<double>> &vec) {
    bool contain_zero = false;
    for (vector<double> &vv:vec) {
        if (contain_zero) { break; }
        for (double i:vv) {
            if (i == 0.0) {
                contain_zero = true;
                break;
            }
        }
    }
    return contain_zero;
}

bool vector_contain_zero(vector<double> &vec) {
    bool contain_zero = false;
    for (double i : vec) {
        if (i == 0.0) {
            contain_zero = true;
            break;
        }
    }
    return contain_zero;
}


Matrix::Matrix(vector<vector<double>> &vec) {
    rows = (int) vec.size();
    cols = (int) vec[0].size();
    val = vec;
    if (rows == cols) { det = getDet(); }
    shape = vector<int>{rows, rows};
}

Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    val = m.val;
    if (rows == cols) { det = getDet(); }
    shape = m.shape;
}

Matrix::Matrix(Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    val = m.val;
    if (rows == cols) { det = getDet(); }
    shape = m.shape;
}

bool Matrix::operator==(const Matrix &m) const {
    if (val == m.val) {
        return true;
    }
    return false;
}

Matrix Matrix::operator+(Matrix &m) {
    if (shape != m.shape) {
        std::cout << "Matrix shapes must be equal in order to add." << std::endl;
        exit(1);
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            val[r][c] += m.val[r][c];
        }
    }
    if (rows == cols) { det = getDet(); }
    return *this;
}

Matrix Matrix::operator-(Matrix &m) {
    if (shape != m.shape) {
        std::cout << "Matrix shapes must be equal in order to subtract." << std::endl;
        exit(1);
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            val[r][c] -= m.val[r][c];
        }
    }
    if (rows == cols) { det = getDet(); }
    return *this;
}

Matrix Matrix::operator*(double &num) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            val[r][c] *= num;
        }
    }
    if (rows == cols) { det = getDet(); }
    return *this;
}

Matrix Matrix::operator*(Matrix &m) {
    if (shape != m.shape) {
        std::cout << "Matrix shapes must be equal in order to dot multiply." << std::endl;
        exit(1);
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            val[r][c] *= m.val[r][c];
        }
    }
    if (rows == cols) { det = getDet(); }
    return *this;
}

Matrix Matrix::mul(Matrix &m) {
    if (cols != m.rows) {
        std::cout << "M1.mul(m2),the number of columns in m1 must be equal to the number of rows in m2." << std::endl;
        exit(1);
    }
    vector<vector<double>> res;
    for (int r = 0; r < rows; r++) {
        vector<double> temp;
        for (int c = 0; c < m.cols; c++) {
            double sum = 0.0;
            int idx = 0;
            while (idx < cols) {
                sum += val[r][idx] * m.val[idx][c];
                idx++;
            }
            temp.push_back(sum);
        }
        res.push_back(temp);
    }
    val = res;
    if (rows == cols) { det = getDet(); }
    shape = vector<int>{rows, m.cols};
    return *this;
}

double Matrix::getDet() {
    if (rows != cols) {
        std::cout << "Only square matrices have determinant." << std::endl;
        exit(1);
    }
    return Determinant(val).val;
}

Matrix Matrix::T() {
    vector<vector<double>> res;

    for (int r = 0; r < rows; r++) {
        vector<double> rr;
        rr.reserve(cols);
        for (int c = 0; c < cols; c++) {
            rr.push_back(val[c][r]);
        }
        res.push_back(rr);
    }
    val = res;
    if (rows == cols) { det = getDet(); }
    shape = vector<int>{cols, rows};
    return *this;
}

Matrix Matrix::Adj() {
    if (rows != cols) {
        std::cout << "Only square matrices have adjoint matrices." << std::endl;
        exit(1);
    }
    vector<vector<double>> res;
    for (int idx = 0; idx < rows; idx++) {
        vector<double> A;
        for (int idy = 0; idy < cols; idy++) {
            vector<vector<double>> res_temp;
            for (int r = 0; r < rows; r++) {
                vector<double> temp;
                for (int c = 0; c < cols; c++) {
                    if (r != idx and c != idy) {
                        temp.push_back(val[c][r]);
                    }
                }
                if (!temp.empty()) { res_temp.push_back(temp); }
            }
            A.push_back(Determinant(res_temp).val * pow(-1, idx + idy));
        }
        res.push_back(A);
    }
    Matrix mm(res);
    return mm;
}

Matrix Matrix::Inv() {
    if (det == 0.0) {
        std::cout << "Irreversibility of a square matrix with determinant zero." << std::endl;
        exit(1);
    }
    double tmp = 1 / det;
    Matrix adj0 = Adj();
    adj0 * tmp;
    return adj0;
}

Matrix Matrix::Pow(int n) {
    if (rows != cols) {
        std::cout << "Only square matrices and the powers of matrices are meaningful." << std::endl;
        exit(1);
    }
    for (int i = 1; i < n; i++) {
        this->mul(*this);
    }
    return *this;
}





