//
// Created by David Wise on 30/03/2017.
//

#include "gtest/gtest.h"
#include "../donorClass.h"
#include <Eigen/Dense>


TEST(basic_test, test_eq) {
    EXPECT_EQ(1, 1);
}
TEST(basic_test, test_neq) {
    EXPECT_NE(1, 0);
}

class DonorFixture : public ::testing::Test {
public:
    virtual void SetUp() {
        Donor phosTest2;
        Donor phosTest4;
        Donor phosTest6;
        const double h_bar = 1.055e-34;
        MatrixXcd Iz2Hard;
        Iz2Hard << 1, 0, 0, -1;
        Iz2Hard *= h_bar / 2;

        MatrixXcd Iz4Hard;
        Iz4Hard(0, 0) = 3 / 2;
        Iz4Hard(1, 1) = 1 / 2;
        Iz4Hard(2, 2) = -1 / 2;
        Iz4Hard(3, 3) = -3 / 2;
        Iz4Hard *= h_bar / 2;

        MatrixXcd Iz6Hard;
        Iz6Hard(0, 0) = 5 / 2;
        Iz6Hard(1, 1) = 3 / 2;
        Iz6Hard(2, 2) = 1 / 2;
        Iz6Hard(3, 3) = -1 / 2;
        Iz6Hard(4, 4) = -3 / 2;
        Iz6Hard(5, 5) = -5 / 2;
        Iz6Hard *= h_bar / 2;
    }

    Donor phosTest2(0.5, 7.29e-26);

};

    TEST_F(DonorFixture, test_eq) {
        EXPECT_EQ(phosTest2.Iz, Iz2Hard);
    }





};