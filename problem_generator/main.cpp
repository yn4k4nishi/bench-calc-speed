#include <iostream>
#include <Eigen/Dense>
#include "../utils/show_matrix.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cerr << "invaild argument." << std::endl;
        return 1;
    }

    int N = std::stoi(argv[1]);
    Eigen::MatrixXd matrix = Eigen::MatrixXd::Random(N,N);
    
    show_matrix(matrix);

    return 0;
}