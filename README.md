# Programming Languages, Fall 2023

## Project #1: 100 Prisoners Problem
**Due Date:** 9/29/23 (email file to instructor)

### Description
Write a C program to estimate the probability of all 100 prisoners escaping in the **100 Prisoner Problem**. In this problem, 100 prisoners, numbered 1 to 100, are imprisoned. A room contains 100 closed numbered boxes, each containing a unique number from 1 to 100 in a random order. Each prisoner is given the opportunity to find their number by opening a maximum of 50 boxes. Prisoners cannot see what any other prisoner does, but they are allowed to discuss strategy beforehand.

If **all 100 prisoners** find their number, then they are set free. If **any prisoner fails** to find their number, **all 100 prisoners are executed**. Your goal is to find and implement the optimal strategy that maximizes the probability that all prisoners will find their number.

For more details on the problem, refer to the [100 Prisoners Problem on Wikipedia](https://en.wikipedia.org/wiki/100_prisoners_problem).

### Task
Write a C program to implement the optimal strategy and estimate the success probability. Represent the room with the boxes as an array of length 100, where each box contains a unique number from 1 to 100. Your program should include the following functions:

1. **Initialize the room** with a random permutation of numbers from 1 to 100.
2. **Determine if a prisoner finds their number** within 50 steps, given a prisoner number and the room.
3. **Determine if all prisoners find their numbers** given a room setup.

Given these functions, your code is to run the last function on a large number (e.g. 100,000) of randomly chosen rooms and estimate the probability that all prisoners find their number. Print this probability. Run the third function on a large number (e.g., 100,000) of randomly generated rooms to estimate the probability that all prisoners find their number. Print this probability.

### Extra Credit
Consider implementing the following features for extra credit:

1. **Optimize the third function**: Avoid a naïve approach by leveraging chains. For example, if a prisoner finds their number in a chain of 20 boxes, all prisoners on that chain will find their number.
2. **Custom Random Number Generator**: Use a random number generator better than the standard `rand()` function. For example, consider implementing the **Mersenne Twister**.
3. **Explore larger prisoner counts**: Investigate how the success probability changes as the number of prisoners increases. For example, create a table of probabilities for values like 100, 200, 300, ..., up to 2000 prisoners.
4. **Additional Features**: Include any other enhancements that are both related to the project and use C.
