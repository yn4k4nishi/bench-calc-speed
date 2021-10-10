#include <iostream>
#include <Eigen/Dense>
#include "../utils/show_matrix.h"
#include "../utils/matrix_io.h"

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cerr << "invaild argument." << std::endl;
        return 1;
    }

    Eigen::MatrixXd matrix = loadMatrix(argv[1]);

    Eigen::MatrixXd A, B;
    A = matrix.block(0,0,matrix.rows(),matrix.rows());
    B = matrix.block(0,matrix.rows(),matrix.rows(),1);

    std::cout << "A : " << A.rows() << "," << A.cols() << std::endl;
    std::cout << "B : " << B.rows() << "," << B.cols() << std::endl;

    Eigen::MatrixXd L(A.rows(), A.cols());
    Eigen::MatrixXd U(A.rows(), A.cols());
    L.setIdentity();
    U.setZero();

    for(int i=0; i<A.rows(); i++){
        U(i,0) = A(i,0);
    }

    show_matrix(L);
    show_matrix(U);

    return 0;
}