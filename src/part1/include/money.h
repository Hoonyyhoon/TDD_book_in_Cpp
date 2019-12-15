#include <assert.h>
#include <iostream>
#include <memory>  // unique_ptr, make_unique
#include <string>

class Money {
 protected:
  double amount_;
  std::string currency_;

 private:

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

  std::unique_ptr<Money> times(const int multiplier) const {
    return std::make_unique<Money>( multiplier * amount_, currency_ );
  }
};