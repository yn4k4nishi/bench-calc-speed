#include <iostream>
#include <Eigen/Dense>
#include "../matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(){
    std::cout << "Generate matrix ..." << std::endl;

    int N = 50;
    Eigen::MatrixXd matrix = Eigen::MatrixXd::Random(N,N);
    
    std::cout << matrix.size() << std::endl;

    // Prepare data
    int ncols = N, nrows = N;
    std::vector<float> z(ncols * nrows);
    for (int j=0; j<nrows; ++j) {
        for (int i=0; i<ncols; ++i) {
            z.at(ncols * j + i) = std::sin(std::hypot(i - ncols/2, j - nrows/2));
        }
    }

    Eigen::MatrixXf f = matrix.cast<float>();
    const float* fp = f.data();

    plt::title("My matrix");
    PyObject* pobj;
    plt::imshow(fp, N, N, 1, {{"cmap","Blues"}}, &pobj);
    plt::colorbar(pobj);
    plt::show();

    return 0;
}