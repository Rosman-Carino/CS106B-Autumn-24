/*
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
using namespace std;

/*
 * sumOfSquares (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named sumOfSquares that takes
 * an int n and returns the sum of squares from 1 to n.
 */

int sumOfSquaresV1(int n) {
    // Error Checking
    if (n < 0) error("Reporting error per section handout spec");
    // Base Case
    if (n == 0) return 0; // 0^2 = 0
    // Recursive Cases
    int currentSquare = n * n; // Calculate the current square for this number
    int nextSquare = sumOfSquaresV1(n - 1);
    return currentSquare + nextSquare;
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Example Tests") {
    EXPECT_EQUAL(sumOfSquaresV1(3), 14);
    EXPECT_EQUAL(sumOfSquaresV1(4), 30);
    EXPECT_EQUAL(sumOfSquaresV1(5), 55);
    EXPECT_EQUAL(sumOfSquaresV1(6), 91);
}


