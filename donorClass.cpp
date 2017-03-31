// Copyright 2017 David Wise
#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/KroneckerProduct>
#include "donorClass.h"

using namespace Eigen;

void Donor::setNucSpin(const double value) {
    Donor::coeffs.clear();
    Donor::nucSpin = value;
    setSpinsMats();
}
double Donor::getNucSpin() {
	return nucSpin;
}
void Donor::setHypCoup(const double value) {
	Donor::A = value;
}
double Donor::getHypCoup() {
	return A;
}
void Donor::setSpinsMats() {
//  Set up Electron spin operators
    Donor::Sx << 0,1,1,0;
    Donor::Sx *= (h_bar/2);
    Donor::Sy << 0,-i,i,0;
    Donor::Sy *= h_bar/2;
    Donor::Sz << 1,0,0,-1;
    Donor::Sz *= h_bar/2;
    Donor::IdS = MatrixXcd::Identity(2*nucSpin+1, 2*nucSpin+1);
    Donor::IdI = MatrixXcd::Identity(2, 2);

//  Set up Nuclear spin operators

    for (int inc = 1; inc <= (2*nucSpin); ++inc) {
        double cInc = pow((2*nucSpin*inc + inc*(1-inc)),0.5);
        Donor::coeffs.push_back(cInc);
    }

    Donor::Icr.resize(nucSpin*2+1, nucSpin*2+1);
    Donor::Ian.resize(nucSpin*2+1, nucSpin*2+1);
    for (int inc = 0; inc <= (2*nucSpin-1); ++inc) {
        Icr(inc, inc+1) = Donor::coeffs[inc];
        Ian(inc+1, inc) = Donor::coeffs[inc];
    }

    Donor::Ix = h_bar*(1.0/2.0)*(Icr+Ian);
    Donor::Iy = h_bar*(-i/(2.0))*(Icr-Ian);
    Donor::Iz = h_bar*((Ix*Iy) - (Iy*Ix))/i;



    Donor::Sx_f = kroneckerProduct(Sx, IdS);
    Donor::Sy_f = kroneckerProduct(Sy, IdS);
    Donor::Sz_f = kroneckerProduct(Sz, IdS);
    Donor::Ix_f = kroneckerProduct(IdI, Ix);
    Donor::Iy_f = kroneckerProduct(IdI, Iy);
    Donor::Iz_f = kroneckerProduct(IdI, Iz);

    Donor::S_I = kroneckerProduct(Sx, Ix) + kroneckerProduct(Sy, Iy) + kroneckerProduct(Sz, Iz);

}

MatrixXcd Donor::getEigs(const double B_0) {
    Donor::Ham = (ge*mu_e/h_bar)*B_0*Sz_f - (gn*mu_n/h_bar)*B_0*Iz_f + A/(pow(h_bar,2))*S_I;
    ComplexEigenSolver<MatrixXcd> es(Ham);
    es.compute(Ham);
    return es.eigenvalues();
}

void Donor::initialise() {

}