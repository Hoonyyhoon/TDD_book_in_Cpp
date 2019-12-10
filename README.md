## Chapter 9. Times We're Livin' In
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
- [X] Currency?
- [ ] Delete testFrancMultiplication?

- Were a little stuck on big design ideas, so we worked on something small we
noticed earlier
- Reconciled the two constructors by moving the variation to the caller (the
factory method)
- Interrupted a refactoring for a little twist (using the factory method in times())
- Repeated an analogous refactoring (doing to Dollar what we just did to Franc)
in one big step
- Pushed up the identical constructors

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