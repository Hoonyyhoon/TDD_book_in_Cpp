#include "money.h"
#include <gtest/gtest.h>

TEST(MoneyExample, Multiplication) {
  std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);

  // !! Risk: test for eqality and multiplication both depends on function
  // equals
  EXPECT_TRUE(five->times(2)->equals(std::make_shared<Dollar>(10)))
      << "The amount is not correct";
  EXPECT_TRUE(five->times(3)->equals(std::make_shared<Dollar>(15)))
      << "The amount is not correct";
}

TEST(MoneyExample, Equality) {
  // triangulation
  EXPECT_TRUE(std::make_shared<Dollar>(5)->equals(std::make_shared<Dollar>(5)))
      << "Equals failed";
  EXPECT_FALSE(std::make_shared<Dollar>(5)->equals(std::make_shared<Dollar>(6)))
      << "Equals failed";
  EXPECT_TRUE(std::make_shared<Franc>(5)->equals(std::make_shared<Franc>(5)))
      << "Equals failed";
  EXPECT_FALSE(std::make_shared<Franc>(5)->equals(std::make_shared<Franc>(6)))
      << "Equals failed";
  EXPECT_FALSE(std::make_shared<Franc>(5)->equals(std::make_shared<Dollar>(5))) 
      << "Franc, Dollars shouldn't be equal";
}

TEST(MoneyExample, Franc_Multiplication) {
  std::shared_ptr<Franc> five = std::make_shared<Franc>(5);
  EXPECT_TRUE(five->times(2)->equals(std::make_shared<Franc>(10)))
      << "The amount is not correct";
  EXPECT_TRUE(five->times(3)->equals(std::make_shared<Franc>(15)))
      << "The amount is not correct";
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}