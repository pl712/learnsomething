#include <gtest/gtest.h>

TEST(sampleTest, sample) {
    EXPECT_EQ(4, 4);
}


//pu has getVal() and calcVal(float prevPrice, float interest, float oleoConstant)
//Theoretical Value = (Previous Price * (0.9 + Interest Rate)) * Oleo Constant

TEST(PricingUtilTest, zeroEverything) {
    PricingUtil pu;
    EXPECT_EQ(0.0, pu.calcVal(0.0, 0.0, 0.0));
}

TEST(PricingUtilTest, negPrevPrice) {
    PricingUtil pu;
    EXPECT_EQ(-1.0, pu.calcVal(-1.0, 0.1, 1.0));
}

TEST(PricingUtilTest, zeroConstant) {
    PricingUtil pu;
    EXPECT_EQ(0.0, pu.calcVal(-1.0, 0.1, 0.0));

}

TEST(PricingUtilTest, negInterest) {
    PricingUtil pu;
    EXPECT_EQ(-0.8, pu.calcVal(-1.0, -0.1, 1.0));
}

TEST(PricingUtilTest, getVal) {
    PricingUtil pu;
    EXPECT_EQ(0, pu.getVal());
    float calculated = pu.calcVal(-1.0, -0.1, 1.0);
    EXPECT_EQ(calculated, pu.getVal());
    EXPECT_EQ(calculated, -0.8);

}