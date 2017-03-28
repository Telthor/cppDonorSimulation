// Copyright 2017 David Wise
#include <iostream>
#include <Eigen/Dense>
#include "donorClass.h"

using namespace Eigen;

void Donor::setNucSpin(const float value) {
    Donor::coeffs.clear();
    Donor::nucSpin = value;
    setSpinsMats();
}
float Donor::getNucSpin() {
	return nucSpin;
}
void Donor::setHypCoup(const float value) {
	Donor::hypCoup = value;
}
float Donor::getHypCoup() {
	return hypCoup;
}
void Donor::setSpinsMats() {
//  Set up Electron spin operators
    Donor::Sx << 0,1,1,0;
    Donor::Sx *= (h_bar/2);
    Donor::Sy << 0,-i,i,0;
    Donor::Sy *= h_bar/2;
    Donor::Sz << 1,0,0,-1;
    Donor::Sz *= h_bar/2;

//  Set up Nuclear spin operators

    for (int inc = 1; inc <= (2*nucSpin); ++inc) {
        double cInc = pow((2*nucSpin*inc + inc*(1-inc)),0.5);
        Donor::coeffs.push_back(cInc);
    }
}

