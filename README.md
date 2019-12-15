## Chapter 11. The Root of All Evil
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
- [X] Dollar/Franc duplication
- [X] Common equals
- [X] Common times
- [X] Compare Francs to Dollars
- [X] Currency?
- [X] Delete testFrancMultiplication?

- Finished gutting subclasses and deleted them
- Eliminated tests that made sense with the old code structure but were redundant with
the new code structure

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