#include <assert.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

/*
Done:
    1) 5+10chf = $10
O   2) 5*2 = 10
O   3) make "amount" private
O   4) side effect of dollar?
    5) money rounding?
O   6) equals()
    7) HashCode()
    8) Equal null
    9) Equal object
O   10) 5CHF * 2 = 10 CHF (multi currency)
    11) Dollar/Franc duplication
    12) Common equals
    13) Common times

    - Couldn’t tackle a big test, so we invented a small test that represented
progress
    - Wrote the test by shamelessly duplicating and editing
    - Even worse, made the test work by copying and editing model code wholesale
    - Promised ourselves we wouldn’t go home until the duplication was gone

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
O   10) 5CHF * 2 = 10 CHF (multi currency)
    11) Dollar/Franc duplication
O   12) Common equals
    13) Common times

    - Stepwise moved common code from one class(Dollar) to a superclass(Money)
    - Made a second class (Franc) also a subclass
    - Reconciled two implementations (equals()) before eliminating the redundant
one
*/

class Money {
 protected:
  double amount;

 public:
  Money(double amount) : amount(amount) { ; }

  bool equals(const std::shared_ptr<Money> money) {
    return amount == money->amount;
  }
};

class Dollar : public Money {
 private:
 public:
  Dollar(double amount) : Money(amount) { ; }

  std::shared_ptr<Dollar> times(const int multiplier) {
    return std::make_shared<Dollar>(amount * multiplier);
  }
};

class Franc : public Money {
 private:
 public:
  Franc(double amount) : Money(amount) { ; }

  std::shared_ptr<Franc> times(const int multiplier) {
    return std::make_shared<Franc>(amount * multiplier);
  }
};

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
      << " Same amount";
  EXPECT_FALSE(std::make_shared<Dollar>(5)->equals(std::make_shared<Dollar>(6)))
      << " Not a same";
  EXPECT_TRUE(std::make_shared<Franc>(5)->equals(std::make_shared<Franc>(5)))
      << " Same amount";
  EXPECT_FALSE(std::make_shared<Franc>(5)->equals(std::make_shared<Franc>(6)))
      << " Not a same";
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