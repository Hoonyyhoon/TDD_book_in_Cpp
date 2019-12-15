## Chapter 10. Interesting Times [![Build Status](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp.svg?branch=Ch10)](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp)
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
- [X] Common times
- [X] Compare Francs to Dollars
- [X] Currency?
- [ ] Delete testFrancMultiplication?

- Reconciled two methods (times()) by first inlining the methods they called and
then replacing constants with variables
- Wrote a toString() without a test just to help us debug
- Tried a change (returning Money instead of Franc) and let the tests tell us
whether it worked

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
