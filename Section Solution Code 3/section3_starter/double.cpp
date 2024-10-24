/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "error.h"
#include "stack.h"
using namespace std;

/*
 * doubleStack (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named doubleStack that takes
 * a reference to a stack of ints and replaces each integer
 * with two copies of that integer. For example, if s stores
 * {1, 2, 3}, then doubleStack(s) changes it to
 * {1, 1, 2, 2, 3, 3}.
 */

void doubleStackV1(Stack<int> & s) {
    // Base Case
    if (s.isEmpty()) {
        return;
    }
    // Recursive Case
    int current = s.pop(); // Remove the top element
    doubleStackV1(s); // We made the problem smaller
    // Push the values back on
    s.push(current);
    s.push(current);
}

void doubleStack(Stack<int> & s) {
    if (!s.isEmpty()) {
        int topOfStack = s.peek();
        s.pop(); // Remove top element and make the problem smaller
        doubleStack(s);
        s.push(topOfStack);
        s.push(topOfStack);
    }
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Examples from handout.") {
    Stack<int> input = {1, 2, 3};
    Stack<int> output = {1, 1, 2, 2, 3, 3};
    doubleStack(input);
    EXPECT_EQUAL(input, output);
}


