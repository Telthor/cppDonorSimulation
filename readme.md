# Readme

A simple C++ library to enable calculation of eigenvalues for a spin Hamiltonian corresponding to an electron-nuclear spin system.

## Usage

Usage is simplest via the modification of the main.cpp file to suit the needs of the user. 

* Create a donor class with the desired nuclear spin and hyperfine coupling values (in joules).
* Add enough matrices to correspond to the total number of eigenvalues of the spin system ((nucSpin + 0.5) x 2)
* Select the desired number of magnetic field steps and final field
* Modify the for loop to include all eigvalue matrices
* Create a savefile
* Run main.cpp
