# Part 3: Solving Performance Issues

## Scenario
You are now asssisting with Market Making Oleos. Due to some changes to legislation, it is now very costly to enter and exit the market. As a result, your team wants you to help them identify the best day to enter and exit the market, where you want to maximize the traded volume over the days. You are given a list of trading volumes, and need to find the optimal trading window. you only need one per list. Note that you can only trade up to the minimum volume of the entry or exit day while you are deployed in the market, otherwise you risk jail time. This must be done very quickly, so there is a runtime limit. (You are not permitted to read the mechanics of the testing system.)

## Instructions
- [ ] Read and understand the problem.
- [ ] Make `task test` pass. You will to use multiple tools we have covered up until this point. 

## Questions
Please include the following when you are writing your PR:   
General things:   
1. What is the purpose of this PR?
finished step 3

2. What changes did you make? Why?
Changed the brute force approach into using two pointers.

3. What bugs did you find while testing?
n/a. Poetry wouldn't work so I just made sure that my code works :))

This PR Specific:
1. What was the bug you found?
It is too slow.
2. How did you address it?
I used a two pointer approach. It would at most take O(n) time.
3. What did you struggle with?
//
4. Is there anything you would change about this step?
// Perhaps don't use a LC problem tho:)
5. What was the code given to you by the tests?
Looked at it afterwards. its a binary string?