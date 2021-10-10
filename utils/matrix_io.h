#include <iostream>
#include<Eigen/Dense>
#include<fstream>

void saveMatrix(std::string filename, Eigen::MatrixXd matrix){
    const static Eigen::IOFormat CSVFormat(Eigen::FullPrecision, Eigen::DontAlignCols, ",", "\n");
    std::ofstream file(filename);
    if(file.is_open()){
        file << matrix.format(CSVFormat);
        file.close();
    }
}

Eigen::MatrixXd loadMatrix(std::string filename){
    std::vector<double> matrixEntries;
 
    std::ifstream matrixDataFile(filename);
 
    std::string matrixRowString;
    std::string matrixEntry;
 
    int matrixRowNumber = 0;
 
    while (getline(matrixDataFile, matrixRowString)){
        std::stringstream matrixRowStringStream(matrixRowString); 
        while (getline(matrixRowStringStream, matrixEntry, ',')) {
            matrixEntries.push_back(stod(matrixEntry));   
        }
        matrixRowNumber++; 
    }
 
    return Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>>(matrixEntries.data(), matrixRowNumber, matrixEntries.size() / matrixRowNumber);
}