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
using namespace std;

/*
 * isSubsequence (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named isSubsequence that takes
 * two strings and returns true if the second string is a
 * subsequence of the first string. A string is a subsequence
 * of another if it contains the same letters in the same order,
 * but not necessarily consecutively. You can assume both
 * strings are already lower-cased.
 */

bool isSubsequence(string big, string small) {
    // Base Case: Success - The empty string is a subsequence of 'big'
    if (small.empty()) {
        return true;
    }
    // Base Case: Failure - 'small' cannot be a subsequence of 'big' if 'big' is
    //                      empty.
    if (big.empty()) {
        return false;
    }
    // Recursive Cases: Compare the Characters at Index 0
    if (big[0] == small[0]) { // Same Letters at Same Position
        big = big.substr(1);
        small = small.substr(1);
    } else {
        // Letters are not the same at the same position
        // so let's make the problem smaller by making 'big'
        // smaller
        big = big.substr(1);
    }
    return isSubsequence(big, small);
}




bool isSubsequenceV2(string big, string small) {
    // Base Case: Success - The empty string is a subsequence of 'big'
    if (small.empty() && big.empty()) {
        return true;
    }
    // Base Case: Failure - 'small' cannot be a subsequence of 'big' if 'big' is
    //                      empty.
    if (big.empty() && !small.empty()) {
        return false;
    }
    // Recursive Cases: Compare the Characters at Index 0
    if (big[0] == small[0]) { // Same Letters at Same Position
        big = big.substr(1);
        small = small.substr(1);
    } else {
        // Letters are not the same at the same position
        // so let's make the problem smaller by making 'big'
        // smaller
        big = big.substr(1);
    }
    return isSubsequenceV2(big, small);
}


bool isSubsequenceV3(string big, string small) {
    // Base Case: Success - The empty string is a subsequence of 'big'
    if (small.empty()) {
        return true;
    }
    // Base Case: Failure - 'small' cannot be a subsequence of 'big' if 'big' is
    //                      empty.
    if (big.empty()) {
        return false;
    }
    // Recursive Cases: Compare the Characters at Index 0
    if (big[0] == small[0]) { // Same Letters at Same Position
        small = small.substr(1); // Make `small` smaller
    }
    // No matter what we need to small `big` smaller
    big = big.substr(1);

    return isSubsequenceV3(big, small);
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Examples from handout.") {
    EXPECT_EQUAL(isSubsequence("computer", "core"), false);
    EXPECT_EQUAL(isSubsequence("computer", "cope"), true);
    EXPECT_EQUAL(isSubsequence("computer", "computer"), true);
}


