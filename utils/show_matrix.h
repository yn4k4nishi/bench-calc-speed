#include <iostream>
#include <Eigen/Dense>
#include "../matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

void show_matrix(Eigen::MatrixXd matrix){
    int nrow = matrix.rows();
    int ncol = matrix.cols();

    Eigen::MatrixXf f = matrix.cast<float>();
    const float* fp = f.data();

    PyObject* pobj;
    plt::imshow(fp, nrow, ncol, 1, {{"cmap","Blues"}}, &pobj);
    plt::colorbar(pobj);
    plt::show();
}
