//
// Created by David Wise on 30/03/2017.
//

#include "gtest/gtest.h"
#include "../donorClass.h"
#include <Eigen/Dense>



class DonorTest: public ::testing::Test {
public:
    Matrix2cd Iz2Hard;
    Matrix4cd Iz4Hard;
    MatrixXcd Iz6Hard;
    Donor phosTest2;
    Donor phosTest4;
    Donor phosTest6;
protected:
    virtual void SetUp() {
        phosTest2.initialise(0.5, 7.29e-26);
        phosTest4.initialise(1.5, 7.29e-26);
        phosTest6.initialise(2.5, 7.29e-26);
        const double h_bar = 1.055e-34;
        Iz2Hard << 1, 0, 0, -1;
        Iz2Hard *= h_bar / 2;

        Iz4Hard(0, 0) = 3 / 2;
        Iz4Hard(1, 1) = 1 / 2;
        Iz4Hard(2, 2) = -1 / 2;
        Iz4Hard(3, 3) = -3 / 2;
        Iz4Hard *= h_bar / 2;

        Iz6Hard.resize(6,6);
        Iz6Hard(0, 0) = 5 / 2;
        Iz6Hard(1, 1) = 3 / 2;
        Iz6Hard(2, 2) = 1 / 2;
        Iz6Hard(3, 3) = -1 / 2;
        Iz6Hard(4, 4) = -3 / 2;
        Iz6Hard(5, 5) = -5 / 2;
        Iz6Hard *= h_bar / 2;
    }



};


TEST_F(DonorTest, test_eq_2) {
    EXPECT_EQ(1,1);
}

//TEST_F(DonorFixture, test_eq_4) {
//    EXPECT_EQ(phosTest4.Iz, Iz4Hard);
//}





