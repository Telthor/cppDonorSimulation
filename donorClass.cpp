// Copyright 2017 David Wise
#include <iostream>
// #include <eigen.h>

class Donor {
	Donor(){};
	float nucSpin;
	float hypCoup;

	// Values of constants
	const int ge = 1.9985;
	const int gn = 2.2632;
	const int mu_e = 9.274e-24;
	const int h_bar = 1.055e-34;
	const int mu_n = 5.051e-27;
	const int A = 7.29e-26;
	const int k_B = 1.380e-23;

public:
	Donor(const float nucVal, const float hypVal) {
		nucSpin = nucVal;
		hypCoup = hypVal;
	}
    ~Donor(){std::cout << "destruction \n";};
    void setNucSpin(const float value);
    float getNucSpin();
    void setHypCoup(const float value);
    float getHypCoup();
};
void Donor::setNucSpin(const float value) { 
    Donor::nucSpin = value;
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
int main() {
	Donor phos(0.5, 1);
	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
	phos.setNucSpin(2.5)
	phos.setHypCoup(5);
	std::cout << "nuc spin is:" << phos.getNucSpin() << "\n";
	std::cout << "hyp is:" << phos.getHypCoup() << "\n";
	return 0;
}



