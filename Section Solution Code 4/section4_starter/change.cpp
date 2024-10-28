/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 3
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Chase Davis for CS106B
 * Fall 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "error.h"
#include "stack.h"
#include "set.h"
using namespace std;

/*
 * Make Chance (Code Writing)
 * --------------------------------------------------------
 * Your task is to write a function fewestCoinsFor that takes
 * as input a number of cents and a Set indicating the different
 * denominations of coins used in a country, then returns the
 * minimum number of coins required to make change for that total.
 */


//Important Note: I will adding additional solutions to this! - RC

/**
 * @brief fewestCoinsForV1: Section Solution
 * @param cents
 * @param coins
 * @return
 */
int fewestCoinsForV1(int cents, Set<int>& coins) {
    // Base Case
    if (cents == 0) {
        return 0;
    }

    // Recursive Cases
    int fewestCoins = cents + 1;
    for (int coin : coins) {
        if (coin <= cents) {
            int currFewestCoins = fewestCoinsForV1(cents - coin, coins);
            // Update the minimum number of coins
            fewestCoins = min(fewestCoins, currFewestCoins);
        }
    }
    return fewestCoins + 1; // Include the coin we chose
}

/**
 * @brief fewestCoinsForV2: Here we follow the same mechanics of V1, but
 *                      everytime we deduct from `coins` we are adding a
 *                      `coin`. This is why we have the +1 at the end of line 78.
 * @param cents
 * @param coins
 * @return
 */

int fewestCoinsForV2(int cents, Set<int>& coins) {
    // Base Case
    if (cents == 0) {
        return 0;
    }

    // Recursive Cases
    int fewestCoins = cents + 1;
    for (int coin : coins) {
        if (coin <= cents) { // Make sure we are not overshooting `cents`
            // We can do a +1 at the end because we're including this coin.
            int currFewestCoins = fewestCoinsForV2(cents - coin,
                                                         coins) + 1;
            // Update the minimum number of coins
            fewestCoins = min(fewestCoins, currFewestCoins);
        }
    }
    return fewestCoins;
}

/**
 * @brief fewestCoinsForV3: Here we avoid "Arms Length Recursion" by just
 *                  recursing and if we "overshoot" and give more change then
 *                  we return -1.
 * @param cents
 * @param coins
 * @return
 */
int fewestCoinsForV3(int cents, Set<int>& coins) {
    // Base Case: Failure Case - We overshot
    if (cents < 0) { // Overshot
        return -1;
    }
    // Base Case: We were able to Make Change for `cents`. If
    // we need to make 0 cents of change we return 0 coins.
    if (cents == 0) {
        return 0;
    }
    // Recursive Cases
    int fewestCoins = cents + 1;
    for (int coin : coins) {
        int currFewestCoins = fewestCoinsForV3(cents - coin,
                                             coins);
        // If we do not overshoot then let's perform a min
        // operation.
        if (currFewestCoins != -1) {
            fewestCoins = min(fewestCoins, currFewestCoins + 1);
        }
    }
    return fewestCoins;
}



int fewestCoinsForHelper(int cents, Set<int>& coins, int numCoinsSoFar) {
    // Base Case: Failure Case - We overshot
    if (cents < 0) { // Overshot
        return -1;
    }
    // Base Case: We were able to Make Change for `cents`. If
    // we need to make 0 cents of change we return 0 coins.
    if (cents == 0) {
        return 0;
    }
    for (int coin : coins) {
        int currFewestCoins = fewestCoinsForHelper(cents - coin, coins, numCoinsSoFar) + 1;
        // If we do not overshoot then let's perform a min
        // operation.
        if (currFewestCoins != -1) {
            numCoinsSoFar = min(currFewestCoins, numCoinsSoFar);
        }
    }
    return numCoinsSoFar;
}

int fewestCoinsFor(int cents, Set<int>& coins) {
    return fewestCoinsForHelper(cents, coins, cents + 1);
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: US Currency System") {
    Set<int> coins = {1, 5, 10, 25, 50};
    EXPECT_EQUAL(fewestCoinsForV3(31, coins), 3);
}

PROVIDED_TEST("Provided Test: Recursia Currency System") {
    Set<int> coins = {1, 12, 14, 63};
    EXPECT_EQUAL(fewestCoinsForV3(24, coins), 2);
}

PROVIDED_TEST("Section Example") {
    Set<int> coins = {1, 10, 25};
    EXPECT_EQUAL(fewestCoinsForV3(31, coins), 4);
    EXPECT_EQUAL(fewestCoinsForV3(0, coins), 0);
}

PROVIDED_TEST("Additional Examples") {
    Set<int> coins = {1, 6, 10};
    EXPECT_EQUAL(fewestCoinsForV3(1, coins), 1);
    EXPECT_EQUAL(fewestCoinsForV3(11, coins), 2);
    EXPECT_EQUAL(fewestCoinsForV3(12, coins), 2);
    Set<int> coinsEx2 = {1, 5, 10};
    EXPECT_EQUAL(fewestCoinsForV3(1, coinsEx2), 1);
    Set<int> coinsEx3 = {1, 25};
    EXPECT_EQUAL(fewestCoinsForV3(31, coinsEx3), 7);
}


