#include <gtest/gtest.h>
#include "money.h"

TEST(MoneyExample, Multiplication) {
  MoneyFactory mf;
  std::unique_ptr<Money> five = mf.money(MoneyFactory::USD, 5);

  // !! Risk: test for eqality and multiplication both depends on function
  // equals
  EXPECT_TRUE(five->times(2)->equals(mf.money(MoneyFactory::USD, 10)))
      << "The amount is not correct";
  EXPECT_TRUE(five->times(3)->equals(mf.money(MoneyFactory::USD, 15)))
      << "The amount is not correct";
}

TEST(MoneyExample, Equality) {
MoneyFactory mf;
  std::unique_ptr<Money> five = mf.money(MoneyFactory::USD, 5);

  // triangulation
  EXPECT_TRUE( mf.money(MoneyFactory::USD, 5)->equals(mf.money(MoneyFactory::USD, 5)))
      << "Equals failed";
  EXPECT_FALSE(mf.money(MoneyFactory::USD, 5)->equals(mf.money(MoneyFactory::USD, 6)))
      << "Equals failed";
  EXPECT_TRUE(mf.money(MoneyFactory::CHF, 5)->equals(mf.money(MoneyFactory::CHF, 5)))
      << "Equals failed";
  EXPECT_FALSE(mf.money(MoneyFactory::CHF, 5)->equals(mf.money(MoneyFactory::CHF, 6)))
      << "Equals failed";
  EXPECT_FALSE(mf.money(MoneyFactory::CHF, 5)->equals(mf.money(MoneyFactory::USD, 5)))
      << "Franc, Dollars shouldn't be equal";
}

TEST(MoneyExample, Franc_Multiplication) {
  MoneyFactory mf;
  std::unique_ptr<Money> five = mf.money(MoneyFactory::CHF, 5);

  EXPECT_TRUE(five->times(2)->equals(mf.money(MoneyFactory::CHF, 10)))
      << "The amount is not correct";
  EXPECT_TRUE(five->times(3)->equals(mf.money(MoneyFactory::CHF, 15)))
      << "The amount is not correct";
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}