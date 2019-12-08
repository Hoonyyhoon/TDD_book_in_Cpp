#include <assert.h>
#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <typeinfo> // typeid
#include <string>

/*
Done:
    Francs != Dollars
    $5*2 = $10
    Make "amount" private
    Dollar side effects?
    Equals()
    5 CHF * 2 = 10 CHF
    Common equals
Todo:
    5 + 10 CHF = 10 if CHF:USD is 2:1
    Money rounding?
    HashCode()
    Equal null
    Equal object
    Dollar/Franc duplication
    Common times
    Currency?

  - Took an objection that was bothering us and turned into a test
  - Made the test run a reasonable, but not perfect way (getClass())
  - Decided not to introduce more design until we had a better motivation
*/

class Money {
 protected:
  double amount_;
  std::string type_name_;   // store typeid name()

 public:
  Money(double amount, std::string type_name) {
    amount_ = amount; 
    type_name_ = type_name;
  }
  
  // Any better idea to implement getClass?
  std::string getClass(){
      return type_name_;
  }

  bool equals(const std::shared_ptr<Money> money) {
    return amount_ == money->amount_ && type_name_ == money->getClass();
  }
};

class Dollar : public Money {
 private:
 public:
  Dollar(double amount) : Money(amount, typeid(Dollar).name()) { ; }

  std::shared_ptr<Dollar> times(const int multiplier) {
    return std::make_shared<Dollar>(amount_ * multiplier);
  }
};

class Franc : public Money {
 private:
 public:
  Franc(double amount) : Money(amount, typeid(Franc).name()) { ; }

  std::shared_ptr<Franc> times(const int multiplier) {
    return std::make_shared<Franc>(amount_ * multiplier);
  }
};