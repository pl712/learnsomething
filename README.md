# Part 4: Making things fasterer

## Scenario
An intern has made a function to calculate all the unique prime factors for numbers in range of 2 through 1000 as part of their work. However, their code is extrememly slow and has been causing major slippage issues. You, after proving your knowledge through the previous steps are now tasked with optimizing their code.

## Instructions
- [ ] OPTIONAL: Run the initial code to see the time.
- [ ] Optimize the given code to run below .07 seconds for calculating the prime factorization of all numbers from 2-2500, including 2, excluding 2500.
- [ ] PR this change. 
- [ ] Write code that runs below .0001 seconds for calculating the prime factorization of all numbers from 2-2500, including 2, excluding 2500.
- [ ] PR.


## Questions
Please include the following when you are writing your PR:   
General things:   
1. What is the purpose of this PR?
finsihed task 4

2. What changes did you make? Why?
computed upto sqrt(n), since that number squared would lead to the number

3. What bugs did you find while testing?
N/A. Slow tho

This PR Specific:
1. How does this make the code faster? How much headroom do you have?
Reduced the # of itnerations (runtime). 

Tried Cpp with pybind, apparently that's slower?

Also I guess i could use sieve to first calculate all primes...
