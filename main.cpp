//
// Created by David Wise on 24/03/2017.
//

#include <iostream>
#include "donorClass.h"
#include <stdio.h>
#include <Eigen/Dense>
//#include "gnuplot-iostream/gnuplot-iostream.h"
#include <fstream>

using namespace std;

int main() {
	Donor phos;
    phos.initialise(2.5, 7.29e-26);
//    Donor bis(4.5, 7e-25);
//	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
//	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
//	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
//	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
    std::cout << "Id is \n" << phos.IdI << "\n";
	std::cout << "Sz is \n" << phos.Sz << "\n";
	std::cout << "Iz is \n" << phos.Iz << "\n";
    std::cout << "Ix is \n" << phos.Ix << "\n";
    std::cout << "Iy is \n" << phos.Iy << "\n";
    std::cout << "Szf is \n" << phos.Sz_f << "\n";
	phos.getEigs(1);
	std::cout << "Ham is \n" << phos.Ham << "\n";
	ComplexEigenSolver<MatrixXcd> ces;
    ces.compute(phos.Ham);
	std::cout << "Eigs are: \n" << phos.getEigs(0.000).size() << "\n";

//    Gnuplot gp;
//    std::vector<std::complex<double>> eig1;
//    std::vector<std::complex<double>> eig2;
//    std::vector<std::complex<double>> eig3;
//    std::vector<std::complex<double>> eig4;
//    std::vector<double> fields;
//
//    for (double incr = 0; incr <0.1; incr += 0.00001) {
//        MatrixXcd Eigs = phos.getEigs(incr);
//        eig1.push_back(Eigs(0,0));
//        eig2.push_back(Eigs(1,0));
//        eig4.push_back(Eigs(3,0));
//        eig3.push_back(Eigs(2,0));
//        fields.push_back(incr);
//    }
//
//    std::cout << "Eig1 is \n" << eig1[999] << "\n";
//
//    ofstream myFile;
//    myFile.open ("~/dataTest.txt");
//    myFile << "Try this";
//    myFile.close();



//    std::cout << "Sy is \n" << phos.Sy << "\n";
//    std::cout << "Cr is \n" << phos.Icr << "\n";
//    std::cout << "An is \n" << phos.Ian << "\n";
//    std::cout << "Iy is \n" << phos.Iy << "\n";
//    std::cout << "Iz is \n" << phos.Iz << "\n";
//	std::cout << "I_S is \n" << phos.S_I << "\n";
//    std::cout << "complex \n" << phos.i << "\n";
//    std::cout << "eiges are \n" << phos.getEigs(1) << "\n";
//    MatrixXd m(2,2);
//    m(0,0) = 3;
//    m(1,0) = 2.5;
//    m(0,1) = -1;
//    m(1,1) = m(1,0) + m(0,1);
//    std::cout << "Here is the matrix m:\n" << m << std::endl;
//    VectorXd v(2);
//    v(0) = 4;
//    v(1) = v(0) - 1;
//    std::cout << "Here is the vector v:\n" << v << std::endl;
//    Matrix3f Sd;
//    Sd(0,0) = 3;
//    std::cout << "Final Matrix \n" << Sd << "\n";
	return 0;
}
