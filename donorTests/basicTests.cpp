//
// Created by David Wise on 30/03/2017.
//

#include "gtest/gtest.h"
#include "../donorClass.h"
#include <Eigen/Dense>



class DonorTest: public ::testing::Test {
public:
//    DonorTest() {};
//    ~DonorTest(){};
    MatrixXcd Iz2Hard;
    MatrixXcd Iz4Hard;
    MatrixXcd Iz6Hard;
    Donor phosTest2;
    Donor phosTest4;
    Donor phosTest6;
protected:
    virtual void SetUp() {
        phosTest2.initialise(0.5, 7.29e-26);
        std::cout << "phos2 Iz \n" << phosTest2.Iz << "\n";
        phosTest4.initialise(1.5, 7.29e-26);
        phosTest6.initialise(2.5, 7.29e-26);
        const double h_bar = 1.055e-34;
//        const double h_bar = 1.0;
        Iz2Hard.resize(2,2);
        Iz2Hard << 1, 0, 0, -1;
        Iz2Hard *= h_bar / 2;

        Iz4Hard.resize(4,4);
        Iz4Hard(0, 0) = 1.5;
        Iz4Hard(1, 1) = 0.5;
        Iz4Hard(2, 2) = -0.5;
        Iz4Hard(3, 3) = -1.5;
        Iz4Hard *= h_bar;

        Iz6Hard.resize(6,6);
        Iz6Hard(0, 0) = 2.5;
        Iz6Hard(1, 1) = 1.5;
        Iz6Hard(2, 2) = 0.5;
        Iz6Hard(3, 3) = -0.5;
        Iz6Hard(4, 4) = -1.5;
        Iz6Hard(5, 5) = -2.5;
        Iz6Hard *= h_bar;
    }



};

// Test the creation of the 0.5 nucSpin matrices
TEST_F(DonorTest, test_eq_2) {
    ASSERT_TRUE(phosTest2.Iz(0,0) == Iz2Hard(0,0));
    ASSERT_TRUE(phosTest2.Iz(1,1) == Iz2Hard(1,1));
}

// Test the creation of the 1.5 nucSpin matrices
TEST_F(DonorTest, test_eq_4) {
    ASSERT_TRUE(phosTest4.Iz(0,0) == Iz4Hard(0,0));
    ASSERT_TRUE(phosTest4.Iz(1,1) == Iz4Hard(1,1));
    ASSERT_TRUE(phosTest4.Iz(2,2) == Iz4Hard(2,2));
    ASSERT_TRUE(phosTest4.Iz(3,3) == Iz4Hard(3,3));
}

// Test the creation of the 2.5 nucSpin matrices
TEST_F(DonorTest, test_eq_6) {
    ASSERT_TRUE(phosTest6.Iz(0,0) == Iz6Hard(0,0));
    ASSERT_TRUE(phosTest6.Iz(1,1) == Iz6Hard(1,1));
    ASSERT_TRUE(phosTest6.Iz(2,2) == Iz6Hard(2,2));
    ASSERT_TRUE(phosTest6.Iz(3,3) == Iz6Hard(3,3));
    ASSERT_TRUE(phosTest6.Iz(4,4) == Iz6Hard(4,4));
    ASSERT_TRUE(phosTest6.Iz(5,5) == Iz6Hard(5,5));
}

// Test throw for non-halfint/int value
TEST_F(DonorTest, test_throw) {
    EXPECT_ANY_THROW(Donor wrongSpin(0.33, 5));
}

// Test setting and getting of nucSpin
TEST_F(DonorTest, test_setSpin) {
    Donor setNucTest(0.5, 1);
    ASSERT_EQ(setNucTest.getNucSpin(), 0.5);
    setNucTest.setNucSpin(1.5);
    ASSERT_EQ(setNucTest.getNucSpin(), 1.5);
}

// Test setting and getting of hypCoup
TEST_F(DonorTest, test_setHyp) {
    Donor setHypTest(0.5, 1);
    ASSERT_EQ(setHypTest.getHypCoup(), 1);
    setHypTest.setHypCoup(2);
    ASSERT_EQ(setHypTest.getHypCoup(), 2);
}

// Test calculation of eigenvalues
TEST_F(DonorTest, test_EigSize) {
    ASSERT_EQ(phosTest2.getEigs(0.1).size(), 4);
    ASSERT_EQ(phosTest4.getEigs(0.1).size(), 8);
    ASSERT_EQ(phosTest6.getEigs(0.1).size(), 12);
}

// Test calculation of eigenvalues
TEST_F(DonorTest, test_Eigs) {
    std::complex<double> up{1.8225e-26,0};
    std::complex<double> down{-5.4675e-26, 0};
    ASSERT_TRUE(phosTest2.getEigs(0)(0,0) == up);
    ASSERT_TRUE(phosTest2.getEigs(0)(1,0) == up);
    ASSERT_TRUE(phosTest2.getEigs(0)(2,0) == up);
    ASSERT_TRUE(phosTest2.getEigs(0)(3,0) == down);
}


