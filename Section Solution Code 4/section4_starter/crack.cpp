/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 2
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
#include "strlib.h"
using namespace std;

/*
 * Cracking Passwords (Code Writing)
 * --------------------------------------------------------
 * Write a function crack that takes in the maximum length a
 * site allows for a user's password and tries to find the
 * password into an account by using recursive backtracking to
 * attempt all possible passwords up to that length (inclusive).
 */

bool login(string password) {
    return (password == "LA");
}


/**
 * @brief crackPasswordHelperV1: In this version we are building up the password
 *              as `soFar` and our base case will be the following:
 *              soFar.length() == n
 * @param n
 * @param soFar
 * @return
 */
string crackPasswordHelperV1(int n, string soFar) {
    // Base Case
    cout << soFar << endl;
    if (login(soFar)) {
        return soFar;
    }
    if (soFar.length() == n) {
        return "";
    }

    // Recursive Case
    for (char letter = 'a'; letter <= 'z'; letter++) {
        string triedPassword = crackPasswordHelperV1(n, soFar + letter);
        if (triedPassword != "") {
            return triedPassword;
        }
        // Try an Uppercase letter
        char upperLetter = toUpperCase(letter);

        triedPassword = crackPasswordHelperV1(n, soFar + upperLetter);
        if (triedPassword != "") {
            return triedPassword;
        }
    }
    return "";
}

/**
 * @brief crackPasswordHelperV2: In this version we are building up the password
 *              as `soFar` and our base case will be the following:
 *              n == 0. Essentially decrementing n
 * @param n
 * @param soFar
 * @return
 */
string crackPasswordHelperV2(int n, string soFar) {
    // Base Case
    if (login(soFar)) {
        return soFar;
    }
    if (n == 0) {
        return "";
    }

    // Recursive Case
    for (char letter = 'a'; letter <= 'z'; letter++) {
        string triedPassword = crackPasswordHelperV2(n - 1, soFar + letter);
        if (triedPassword != "") {
            return triedPassword;
        }
        // Try an Uppercase letter
        char upperLetter = toUpperCase(letter);

        triedPassword = crackPasswordHelperV2(n - 1, soFar + upperLetter);
        if (triedPassword != "") {
            return triedPassword;
        }
    }
    return "";
}

/**
 * @brief crackPasswordHelperV3: In this version we are building up the password
 *              as `soFar`, but we are showing the choose/unchoose step in the
 *              recursive calls.
 * @param n
 * @param soFar
 * @return
 */
string crackPasswordHelperV3(int n, string soFar) {
    // Base Case
    if (login(soFar)) {
        return soFar;
    }
    if (n == 0) { // This can also be if (n == soFar.size())
        return "";
    }

    // Recursive Case
    for (char letter = 'a'; letter <= 'z'; letter++) {
        // Choose: Choose this `letter` (Lowercase)
        soFar += letter;
        string triedPassword = crackPasswordHelperV2(n - 1, soFar);
        if (triedPassword != "") {
            return triedPassword;
        }
        // Unchoose: Unchoose this `letter` (Lowercase)
        soFar.erase(soFar.size() - 1, 1);


        // Try an Uppercase letter
        char upperLetter = toUpperCase(letter);
        // Choose: Choose this `letter` (Uppercase)
        soFar += upperLetter;
        triedPassword = crackPasswordHelperV2(n - 1, soFar);
        if (triedPassword != "") {
            return triedPassword;
        }
        // Unchoose: Unchoose this `letter` (Uppercase)
        soFar.erase(soFar.size() - 1, 1);
    }
    return "";
}

string crackingPasswords(int n){
    // TODO: Your code here
    // return "";
    if (n < 0) {
        throw n;
    }
    return crackPasswordHelperV1(n, "");
}



/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Example from handout.") {
    EXPECT_EQUAL(crackingPasswords(2), "LA");
}
