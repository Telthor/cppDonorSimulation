//
// Created by David Wise on 24/03/2017.
//

#include <iostream>
#include "donorClass.h"
#include <stdio.h>
#include <Eigen/Dense>

int main() {
	Donor phos(2.5, 1.5);
	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
	phos.setHypCoup(5);
	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
	std::cout << "Sx is \n" << phos.Sx << "\n";
    std::cout << "Sy is \n" << phos.Sy << "\n";
    std::cout << "Sz is \n" << phos.Sz << "\n";
    std::cout << "complex \n" << phos.i;
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
