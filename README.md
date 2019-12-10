## Chapter 8. Makin' Objects [![Build Status](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp.svg?branch=Ch8)](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp)
- [ ] $5 + 10 CHF = 10 if CHF:USD is 2:1
- [X] $5*2 = $10
- [X] Make "amount" private
- [X] Dollar side effects?
- [ ] Money rounding?
- [X] Equals()
- [ ] HashCode()
- [ ] Equal null
- [ ] Equal object
- [X] 5 CHF * 2 = 10 CHF
- [ ] Dollar/Franc duplication
- [X] Common equals
- [ ] Common times
- [X] Compare Francs to Dollars
- [ ] Currency?
- [ ] Delete testFrancMultiplication?

- Took a step towards eliminating duplication by reconciling the signatures of
two variants of the same method (times())
- Moved at least a declaration of the method to the common superclass (Not onto a superclass but factory class)
- Decoupled test code from the existence of concrete subclasses by introducing
factory methods (extra MoneyFactory class for c++)
- Noticed that when the subclasses disappear some tests will be redundant, but
took no action

## Run code
The structure of the CMake highly referenced from a great project, **Modern CMake**[[link](https://gitlab.com/CLIUtils/modern-cmake)]

To configure:
```
cmake -S . -B build
```

To build:
```
cmake --build build
```

To test
```
cmake --build build --target test ARGS=-V
```
