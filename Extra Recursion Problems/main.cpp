/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "error.h"
#include "strlib.h"
#include "SimpleTest.h" // IWYU pragma: keep (needed to quiet spurious warning)
using namespace std;


int main()
{
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }

    string name = getLine("What is your name?");
    cout << "Hello, " << name << endl;
    return 0;
}
/**
 * @brief Goal: Given an integer `n` return the sum of the digits. Look at the
 *          provided test cases all the way at the bottom.
 * @param n
 * @return
 */
int digitSum(int n) {
    // Base Case
    if (n == 0) {
        return 0;
    }
    // Recurive Case 1725 -> 1 + 7 + 2 + 5
    // E.X. 1725 % 10 = 5 (Value to add)
    //      1725 / 10 = 172 (Making the problem smaller)
    return n % 10 + digitSum(n / 10);
}

/**
 * @brief Goal: Given an integer, print all base 10 numbers that have exactly that
 *              many `digits`
 * E.X. digits = 2. We should print out the following:
 * 00
 * 01
 * 02
 * 03
 * ..
 * 96
 * 97
 * 98
 * 99
 * @param digits
 */
void printNumbersRec(int digits, string soFar) {
    // Base Case
    if (digits == 0) {
        cout << soFar << endl;
    } else {
        // Recursive Cases: We need to loop through all base 10 number
        for (int i = 0; i < 10; i++) {
            printNumbersRec(digits - 1,
                                soFar + integerToString(i));
        }
    }
}

void printNumbers(int digits) {
    printNumbersRec(digits, "");
}



/**
 * @brief Goal: Given an integer `digits`, print all binary numbers that have exactly
 *          that many `digits`
 * E.X. digits = 2. We should print out the following:
 * 00
 * 01
 * 10
 * 11
 * E.X. digits = 3. We should print out the following:
 * 000
 * 001
 * 010
 * 011
 * 100
 * 101
 * 110
 * 111
 * @param digits
 */
void printAllBinaryHelper(int digits, string soFar) {
    // Base Case
    if (digits == 0) {
        cout << soFar << endl;
        return; // I need this return so I can return
                // from my base case in the call stack.
                // Avoid Stack Overflow. You can also just do `else`
    }
    // Recursive Cases
    printAllBinaryHelper(digits - 1, soFar + '0');
    printAllBinaryHelper(digits - 1, soFar + '1');

}

void printAllBinary(int digits) {
    // This is similar to generateCoinSequences
    printAllBinaryHelper(digits, "");
}


PROVIDED_TEST("Digit Sum ") {
    EXPECT_EQUAL(digitSum(1725), 15);
    EXPECT_EQUAL(digitSum(123456), 21);
    EXPECT_EQUAL(digitSum(2300005), 10);
    EXPECT_EQUAL(digitSum(-1729), -19);
    EXPECT_EQUAL(digitSum(-7), -7);
    EXPECT_EQUAL(digitSum(5), 5);
    EXPECT_EQUAL(digitSum(0), 0);
}

PROVIDED_TEST("Print Numbers") {
    printNumbers(3);
}

PROVIDED_TEST("Print Binary") {
    printAllBinary(3);
}
