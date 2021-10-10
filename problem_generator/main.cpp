#include <iostream>
#include <Eigen/Dense>
#include "../utils/show_matrix.h"

namespace plt = matplotlibcpp;

int main(){
    std::cout << "Generate matrix ..." << std::endl;

    int N = 50;
    Eigen::MatrixXd matrix = Eigen::MatrixXd::Random(N,N);
    
    show_matrix(matrix);

    return 0;
}