//
// Created by David Wise on 24/03/2017.
//

#ifndef DONORSIMULATION_DONORCLASS_H
#define DONORSIMULATION_DONORCLASS_H

#endif //DONORSIMULATION_DONORCLASS_H
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

class Donor {
	Donor(){};
	float nucSpin;
	float hypCoup;

	// Values of constants
	const double ge = 1.9985;
	const double gn = 2.2632;
	const double mu_e = 9.274e-24;
	const double h_bar = 1.055e-34;
	const double mu_n = 5.051e-27;
	const double A = 7.29e-26;
	const double k_B = 1.380e-23;




    //Spin Matrices Setters
    void setSpinsMats();

public:
	Donor(const float nucVal, const float hypVal) {
		nucSpin = nucVal;
		hypCoup = hypVal;
        setSpinsMats();
	}
    ~Donor(){std::cout << "destruction \n";};
    void setNucSpin(const float value);
    float getNucSpin();
    void setHypCoup(const float value);
    float getHypCoup();
    //Electron Spin Matrices
    Matrix2cd Sx;
    Matrix2cd Sy;
    Matrix2cd Sz;

    // Nuclear Spin Matrices
    MatrixXcd Ix;
    MatrixXcd Iy;
    MatrixXcd Iz;

    std::complex<double> i{0,1};
};
