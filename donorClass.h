//
// Created by David Wise on 24/03/2017.
//

#ifndef DONORSIMULATION_DONORCLASS_H
#define DONORSIMULATION_DONORCLASS_H

#endif //DONORSIMULATION_DONORCLASS_H
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <unsupported/Eigen/KroneckerProduct>
#include <cmath>

using namespace Eigen;

class Donor {
    friend class DonorTest;

	double nucSpin;

	// Values of constants
	const double ge = 1.9985;
	const double gn = 2.2632;
	const double mu_e = 9.274e-24;
	const double h_bar = 1.055e-34;
//    const double h_bar = 1;
	const double mu_n = 5.051e-27;
	double A;
	const double k_B = 1.380e-23;




    //Spin Matrices Setters
    void setSpinsMats();

public:
    Donor(){};
	Donor(const double nucVal, const double hypVal) {
        if (floor(2*nucVal) != 2*nucVal) {
//            try {
                throw std::invalid_argument("Please use integer or half-integer value");
//            }
//            catch (std::invalid_argument){
//                std::cout << "Please use integer or half-integer value \n";
//            }
        }
		nucSpin = nucVal;
		A = hypVal;
        setSpinsMats();
	}
    ~Donor() {}
    void initialise(double nucVal, double hypVal);

    void setNucSpin(const double value);
    double getNucSpin();
    void setHypCoup(const double value);
    double getHypCoup();
	MatrixXcd getEigs(const double B_0);
    // Identity Matrix
    MatrixXcd IdS;
    MatrixXcd IdI;

    //Electron Spin Matrices
    Matrix2cd Sx;
    Matrix2cd Sy;
    Matrix2cd Sz;

    // Nuclear Spin Matrices
    MatrixXcd Ix;
    MatrixXcd Iy;
    MatrixXcd Iz;
    MatrixXcd Icr;
    MatrixXcd Ian;

    // Joint Spin Matrices
    MatrixXcd Sx_f;
    MatrixXcd Sy_f;
    MatrixXcd Sz_f;

    MatrixXcd Ix_f;
    MatrixXcd Iy_f;
    MatrixXcd Iz_f;

    MatrixXcd S_I;

    // Hamiltonian
	MatrixXcd Ham;

    std::vector<double> coeffs;

    std::complex<double> i{0,1};
};
