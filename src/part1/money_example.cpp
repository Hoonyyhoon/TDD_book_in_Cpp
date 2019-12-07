#include <assert.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

/*
Done:
    1) 5+10chf = $10
O   2) 5*2 = 10
    3) make "amount" private
O   4) side effect of dollar?
    5) money rounding?
O   6) equals()
    7) HashCode()
    8) Equal null
    9) Equal object

    - Noticed that our design pattern (Value Object) implied an operation
    - Tested for that operation
    - Implemented it simply
    - Didn't refactor immediately, but instead tested further
    - Refactored to capture the two cases at once

To do:
    1) 5+10chf = $10
O   2) 5*2 = 10
O   3) make "amount" private
O   4) side effect of dollar?
    5) money rounding?
O   6) equals()
    7) HashCode()
    8) Equal null
    9) Equal object

    - Used functionality just developed to improve a test
    - Noticed that if two tests fail at once we're sunk
    - Proceeded in spite of the risk
    - Used new functionality in the object under test to reduce coupling between
the tests and the code
*/

class Dollar {
 private:
  double amount;

 public:
  Dollar(double amount) : amount(amount) { ; }

  std::shared_ptr<Dollar> times(const int multiplier) {
    return std::make_shared<Dollar>(amount * multiplier);
  }

  bool equals(const std::shared_ptr<Dollar> comp) {
    return amount == comp->amount;
  }
};

TEST(MoneyExample, multiplication) {
  std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
  // override EXPECT_EQ?
  // EXPECT_EQ(five->times(2), std::make_shared<Dollar>(10))
  // << "The amount is not correct";
  // EXPECT_EQ(five->times(3), std::make_shared<Dollar>(15))
  // << "The amount is not correct";

  // !! Risk: test for eqality and multiplication both depends on function
  // equals
  EXPECT_TRUE(five->times(2)->equals(std::make_shared<Dollar>(10)))
      << "The amount is not correct";
  EXPECT_TRUE(five->times(3)->equals(std::make_shared<Dollar>(15)))
      << "The amount is not correct";
}

TEST(MoneyExample, equality) {
  std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);

  // triangulation
  EXPECT_TRUE(five->equals(std::make_shared<Dollar>(5))) << " Same amount";
  EXPECT_FALSE(five->equals(std::make_shared<Dollar>(6))) << " Not a same";
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}