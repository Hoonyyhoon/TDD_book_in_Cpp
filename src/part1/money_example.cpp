#include <assert.h>
#include <memory>
#include <iostream>
#include <gtest/gtest.h>

/*
Done:
    1) 5+10chf = $10
O   2) 5*2 = 10
    3) make "amount" private
O   4) side effect of dollar?
    5) money rounding?
    6) equals()

To do:
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
*/

class Dollar { 
    public:
        Dollar(double amount) : amount(amount){;}
        double amount;

        std::shared_ptr<Dollar> times(int multiplier) {
            return std::make_shared<Dollar>( amount * multiplier );
        }

        bool equals(const std::shared_ptr<Dollar> comp) {
            return amount == comp->amount;
        }
};

// void testMultiplication() {
//     std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
//     five->times(2);
//     assert(10 == five->amount);
// }

//our first unit test
TEST(MoneyExample, multiplication)
{
    std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
    std::shared_ptr<Dollar> product = five->times(2);
    EXPECT_EQ(product->amount, 10) << "The amount is not correct";
    product = five->times(3);
    EXPECT_EQ(product->amount, 15) << "The amount is not correct";
}

TEST(MoneyExample, equality) {
    std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
    
    // triangulation
    EXPECT_TRUE( five->equals( std::make_shared<Dollar>(5) ) ) << " Same amount";
    EXPECT_FALSE( five->equals( std::make_shared<Dollar>(6) ) )<<" Not a same";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}

