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
    // Recursive Case
    int currentSquare = n * n; // Calculate the current square for this number
    int nextSquare = sumOfSquaresV1(n - 1); // Capture answer from next recursive call
    int sumOfSquare = currentSquare + nextSquare; // Aggregate current n and answer from next recursive call
    return sumOfSquare;
}

int sumOfSquaresV2(int n) {
    // Error Checking
    if (n < 0) error("Reporting error per section handout spec");
    // Base Case
    if (n == 0) return 0; // 0^2 = 0
    // Recursive Case
    return (n * n) + sumOfSquaresV2(n - 1); // Add the square of this and our next recursive call
}

int sumOfSquaresV3(int n) {
    // Error Checking
    if (n < 0) error("Reporting error per section handout spec");
    // Base Case
    if (n == 0) return 0; // 0^2 = 0
    // Recursive Case
    int currentSquare = pow(n, 2);
    return currentSquare + sumOfSquaresV3(n - 1);
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Example Tests") {
    EXPECT_EQUAL(sumOfSquaresV1(3), 14);
    EXPECT_EQUAL(sumOfSquaresV1(4), 30);
    EXPECT_EQUAL(sumOfSquaresV1(5), 55);
    EXPECT_EQUAL(sumOfSquaresV1(6), 91);
}


