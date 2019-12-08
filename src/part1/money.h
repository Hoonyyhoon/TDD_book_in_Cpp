#include <assert.h>
#include <iostream>
#include <memory>  // unique_ptr, make_unique
#include <string>
#include <typeinfo>  // typeid

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

  - Took a step towards eliminating duplication by reconciling the signatures of
two variants of the same method (times())
  - Moved at least a declaration of the method to the common superclass (Not onto a superclass but factory class)
  - Decoupled test code from the existence of concrete subclasses by introducing
factory methods (extra MoneyFactory class for c++)
  - Noticed that when the subclasses disappear some tests will be redundant, but
took no action
*/

class Money {
 protected:
  double amount_;
  std::string type_name_;  // store typeid name()

  // Somewhat struggling to fit in with the book using smart pointer
  // https://stackoverflow.com/questions/6924754/return-type-covariance-with-smart-pointers
  // https://arne-mertz.de/2016/05/covariant-smart-pointers/
 private:
  // another layer of indirection for covariants(not so fancy)
  // 1) called times in the base class
  // 2) doDetour called implemented in each derived class
  // 3) times called implemented in each derived class
  virtual std::unique_ptr<Money> doDetour(int amount) const = 0;

 public:
  Money(double amount, std::string type_name) {
    amount_ = amount;
    type_name_ = type_name;
  }
  virtual ~Money() = default;

  std::string getClass() { return type_name_; }

  bool equals(const std::unique_ptr<Money> money) {
    return amount_ == money->amount_ && type_name_ == money->getClass();
  }

  // 1)
  std::unique_ptr<Money> times(const int multiplier) const {
    return doDetour(multiplier);
  }
};

class Dollar : public Money {
 private:
  // 2)
  virtual std::unique_ptr<Money> doDetour(int multiplier) const final override {
    return times(multiplier);
  }

 public:
  Dollar(double amount) : Money(amount, typeid(Dollar).name()) { ; }

  // 3)
  std::unique_ptr<Dollar> times(const int multiplier) const {
    return std::make_unique<Dollar>(amount_ * multiplier);
  }
};

class Franc : public Money {
 private:
  // 2)
  virtual std::unique_ptr<Money> doDetour(int multiplier) const final override {
    return times(multiplier);
  }

 public:
  Franc(double amount) : Money(amount, typeid(Franc).name()) { ; }

  // 3)
  std::unique_ptr<Franc> times(const int multiplier) const {
    return std::make_unique<Franc>(amount_ * multiplier);
  }
};

class MoneyFactory {
  public:
    enum MoneyType {
      USD,
      CHF
    };
    static std::unique_ptr<Money> money(MoneyType mtype, int amount_) {
      switch (mtype) {
        case USD: return std::make_unique<Dollar>(amount_);
        case CHF: return std::make_unique<Franc>(amount_);
      }
      throw "invalid currency.";
    }
};