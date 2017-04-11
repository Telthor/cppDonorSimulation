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

// Initialise a donor with required nuclear spin and hyperfine coupling
	Donor phos;
    phos.initialise(0.5, 7.29e-26);

// Create a savefile for the eigen values
    std::ofstream saveFile("donorsgotest.txt");

// Create matrices to store eigenvalues (need (nucSpin + 0.5) * 4)
    MatrixXcd eig1;
    MatrixXcd eig2;
    MatrixXcd eig3;
    MatrixXcd eig4;
    MatrixXcd fields;


// Loop through a number of steps in magnetic field finding eigenvalues at each step
    int numSteps = 1000;
    for (double incr = 0; incr <numSteps; ++incr) {
        double maxField = 1;
        eig1.resize(numSteps, 1);
        eig2.resize(numSteps, 1);
        eig3.resize(numSteps, 1);
        eig4.resize(numSteps, 1);
        fields.resize(numSteps, 1);
        MatrixXcd Eigs = phos.getEigs(incr);
        eig1(incr) = Eigs(0);
        eig2(incr) = Eigs(1);
        eig4(incr) = Eigs(2);
        eig3(incr) = Eigs(3);
        fields(incr) = (maxField/numSteps)*incr;
    };

// Save eigenvalues to file
    saveFile << "Fields \n" << fields << "\n Eigs 1 \n" << eig1 << "\n Eigs 2 \n" << eig2 << "\n Eigs 3 \n" << eig3 << "\n Eigs 4 \n" << eig4;
    saveFile.close();



	return 0;
}
