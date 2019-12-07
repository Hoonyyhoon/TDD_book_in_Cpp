#include <assert.h>
#include <memory>
#include <iostream>

/*
TODO
1) 5+10chf = $10
2) 5*2 = 10
*/

class Dollar { 
    public:
        Dollar(double amount) : amount(amount){;}
        double amount;

        void times(int multiplier) {
            amount *= multiplier;
        }
};

void testMultiplication() {
    std::shared_ptr<Dollar> five = std::make_shared<Dollar>(5);
    five->times(2);
    assert(10 == five->amount);
}

int main() {
    testMultiplication();
    return 0;
}