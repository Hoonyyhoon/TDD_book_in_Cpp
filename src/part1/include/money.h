#include <assert.h>
#include <iostream>
#include <memory>  // unique_ptr, make_unique
#include <string>

class Money {
 protected:
  double amount_;
  std::string type_name_;  // store typeid name()
  std::string currency_;

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
  Money(double amount, std::string currency) {
    amount_ = amount;
    currency_ = currency;
  }
  virtual ~Money() = default;

  std::string getCurrency() {return currency_;}

  bool equals(const std::unique_ptr<Money> money) {
    return amount_ == money->amount_ && currency_ == money->getCurrency();
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
  Dollar(double amount, std::string currency) : Money(amount, currency) { ; }

  // 3)
  std::unique_ptr<Dollar> times(const int multiplier) const {
    return std::make_unique<Dollar>(amount_ * multiplier, currency_);
  }
};

class Franc : public Money {
 private:
  // 2)
  virtual std::unique_ptr<Money> doDetour(int multiplier) const final override {
    return times(multiplier);
  }

 public:
  Franc(double amount, std::string currency) : Money(amount, currency) { ; }

  // 3)
  std::unique_ptr<Franc> times(const int multiplier) const {
    return std::make_unique<Franc>(amount_ * multiplier, currency_);
  }
};

class MoneyFactory {
  public:
    static std::unique_ptr<Money> money(std::string mtype, int amount_) {
      if (mtype == "USD") return std::make_unique<Dollar>(amount_, mtype);
      else if ( mtype=="CHF" ) return std::make_unique<Franc>(amount_, mtype);
      else return nullptr;
    }
};