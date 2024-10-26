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
#include "vector.h"
using namespace std;

/*
 * Win some, lose sum (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named canMakeSum that takes a
 * reference to a Vector<int> and an int target value and
 * returns true if it is possible to have some selection of
 * values from the Vector that sum to the target value.
 */
/**
 * @brief canMakeSumV1: Solve this by removing from the front of
 *          of 'values'.
 * @param values
 * @param target
 * @return True/False to indicate if it's possible to have some
 *          selection of `values` to sum to `target`
 */
bool canMakeSumV1(Vector<int>& values, int target) {
    // Base Case
    if (values.isEmpty()) {
        // Success Case
        if (target == 0) {
            return true;
        } else {
            // Failure Base Case
            return false;
        }
    }
    // Recursive Cases: Choose & Unchoose

    // Choose
    int currValue = values.remove(0);
    bool withValue = canMakeSumV1(values, target - currValue);
    bool withoutValue = canMakeSumV1(values, target);
    // Unchoose: Need to place this choice back into 'values' so
    // we can backtrack and explore other paths.
    values.insert(0, currValue);
    return withValue || withoutValue;
}

/**
 * @brief canMakeSumV2: This version is similar to `canMakeSumV1`;
 *              however, it reduces "some" overhead by removing
 *              a value from the end of `values`
 * @param values
 * @param target
 * @return
 */
bool canMakeSumV2(Vector<int>& values, int target) {
    // Base Case
    if (values.isEmpty()) {
        // Success Case
        if (target == 0) {
            return true;
        } else {
            // Failure Base Case
            return false;
        }
    }
    // Recursive Cases: Choose & Unchoose

    // Choose
    int currValue = values.remove(values.size() - 1);
    bool withValue = canMakeSumV2(values, target - currValue);
    bool withoutValue = canMakeSumV2(values, target);
    // Unchoose: Need to place this choice back into 'values' so
    // we can backtrack and explore other paths.
    values.add(currValue);
    return withValue || withoutValue;
}

/**
 * @brief canMakeSumHelperV3: This function serves as the helper function
 *              for canMakeSumV3
 * @param values
 * @param target
 * @param total
 * @return
 */
bool canMakeSumHelperV3(Vector<int>& values, int target, int total) {
    // Base Case
    if (values.isEmpty()) {
        // Success Case
        if (total == target) {
            return true;
        } else {
            // Failure Base Case
            return false;
        }
    }
    // Recursive Cases: Choose & Unchoose

    // Choose
    int currValue = values.remove(values.size() - 1);
    int updatedTotal = total + currValue;
    bool withValue = canMakeSumHelperV3(values, target, updatedTotal);
    bool withoutValue = canMakeSumHelperV3(values, target, total);
    // Unchoose:Need to place this choice back into 'values' so
    // we can backtrack and explore other paths.
    values.add(currValue);
    return withValue || withoutValue;
}

/**
 * @brief canMakeSumV3: This implementation uses a helper function
 *                  where we add an additional parameter `total`
 *                  to compare itself to `target`
 * @param values
 * @param target
 * @return
 */
bool canMakeSumV3(Vector<int>& values, int target) {
    return canMakeSumHelperV3(values, target, 0);
}

/**
 * @brief canMakeSumHelperV4: This function serves as the helper function
 *              for canMakeSumV4
 * @param values
 * @param target
 * @param index
 * @return
 */
bool canMakeSumHelperV4(Vector<int>& values, int target, int index) {
    // Base Case
    if (index >= values.size()) {
        // Success Case
        if (target == 0) {
            return true;
        } else {
            // Failure Case
            return false;
        }
    }
    // Recursive Cases
    // Choose
    int currValue = values[index];
    bool withValue = canMakeSumHelperV4(values, target - currValue, index + 1);
    bool withoutValue = canMakeSumHelperV4(values, target, index + 1);
    // There is no need to to put `currValue` back into `values` because
    // we did not remove it from `values`
    return withValue || withoutValue;

}

/**
 * @brief canMakeSum: This implementation uses a helper function where we
 *                  add an additional parameter `index` to traverse
 *                  through `value` without removing elements from `values`.
 * @param values
 * @param target
 * @return
 */
bool canMakeSum(Vector<int>& values, int target) {
    return canMakeSumHelperV4(values, target, 0);

}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Positive example from handout.") {
    Vector<int> nums = {1,1,2,3,5};
    EXPECT(canMakeSum(nums, 9));
}

PROVIDED_TEST("Provided Test: Negative example from handout") {
    Vector<int> nums = {1,4,5,6};
    EXPECT(!canMakeSum(nums, 8));
}

PROVIDED_TEST("Provided Test: Section Example") {
    Vector<int> nums = {1,1,2};
    EXPECT(canMakeSum(nums, 3));
}

PROVIDED_TEST("Stress Test: Additional Examples") {
    Vector<int> nums = {1, 1, 2, 3, 5};
    EXPECT(canMakeSum(nums, 9));
    nums = {1, 4, 5, 6};
    EXPECT(!canMakeSum(nums, 8));
    nums = {7, 30, 8, 22, 6, 1, 14};
    EXPECT(canMakeSum(nums, 22));
    EXPECT(!canMakeSum(nums, 19));
    nums = {5, 30, 15, 13, 8};
    EXPECT(!canMakeSum(nums, 42));
    EXPECT(canMakeSum(nums, 41));
}
