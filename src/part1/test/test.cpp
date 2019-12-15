#include <gtest/gtest.h>
#include "money.h"

TEST(MoneyExample, Multiplication) {
  // !! Risk: test for eqality and multiplication both depends on function
  // equals
  EXPECT_TRUE(std::make_unique<Money>(5, "USD")->times(2)->equals(std::make_unique<Money>(10, "USD")))
      << "The amount is not correct";
  EXPECT_TRUE(std::make_unique<Money>(5, "USD")->times(3)->equals(std::make_unique<Money>(15, "USD")))
      << "The amount is not correct";
}

TEST(MoneyExample, Equality) {
  // triangulation
  EXPECT_TRUE(std::make_unique<Money>(5, "USD")->equals(
      std::make_unique<Money>(5, "USD")))
      << "Equals failed";
  EXPECT_FALSE(std::make_unique<Money>(5, "USD")->equals(
      std::make_unique<Money>(6, "USD")))
      << "Equals failed";
  EXPECT_TRUE(std::make_unique<Money>(5, "CHF")->equals(
      std::make_unique<Money>(5, "CHF")))
      << "Equals failed";
  EXPECT_FALSE(std::make_unique<Money>(5, "CHF")->equals(
      std::make_unique<Money>(6, "CHF")))
      << "Equals failed";
  EXPECT_FALSE(std::make_unique<Money>(5, "CHF")->equals(
      std::make_unique<Money>(5, "USD")))
      << "Franc, Dollars shouldn't be equal";
}

TEST(MoneyExample, Franc_Multiplication) {
  EXPECT_TRUE(std::make_unique<Money>(5, "CHF")->times(2)->equals(
      std::make_unique<Money>(10, "CHF")))
      << "The amount is not correct";
  EXPECT_TRUE(std::make_unique<Money>(5, "CHF")->times(3)->equals(
      std::make_unique<Money>(15, "CHF")))
      << "The amount is not correct";
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}