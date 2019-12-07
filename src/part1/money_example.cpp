#include <assert.h>
#include <memory>
#include <iostream>
#include <gtest/gtest.h>

/*
TODO
    1) 5+10chf = $10
O   2) 5*2 = 10
    3) make amount to private
O   4) side effect of dollar?
    5) floor money?
*/

class Dollar { 
    public:
        Dollar(double amount) : amount(amount){;}
        double amount;

        std::shared_ptr<Dollar> times(int multiplier) {
            return std::make_shared<Dollar>( amount * multiplier );
        }
};

// void testMultiplication() {
//     std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
//     five->times(2);
//     assert(10 == five->amount);
// }

//our first unit test
TEST(IntegerInputsSuite, simpleMul)
{
    std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
    std::shared_ptr<Dollar> product = five->times(2);
    EXPECT_EQ(product->amount, 10) << "The amount is not correct";
    product = five->times(3);
    EXPECT_EQ(product->amount, 15) << "The amount is not correct";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
