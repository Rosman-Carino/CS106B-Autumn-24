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
#include "vector.h"
using namespace std;

/*
 * Weights and Balances (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function that determines whether it is
 * possible to measure out the desired target amount with a
 * given set of weights, which is stored in the vector
 * weights.
 */

bool isMeasurableV1(int target, Vector<int>& weights){
    // Base Case
    if (weights.size() == 0) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights.remove(0);
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableV1(target - currWeight, weights);
    bool leftScaleChoice = isMeasurableV1(target + currWeight, weights);
    bool excludeChoice = isMeasurableV1(target, weights);
    weights.insert(0, currWeight);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}

bool isMeasurableV2(int target, Vector<int>& weights){
    // Base Case
    if (weights.size() == 0) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights.remove(weights.size() - 1);
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableV2(target - currWeight, weights);
    bool leftScaleChoice = isMeasurableV2(target + currWeight, weights);
    bool excludeChoice = isMeasurableV2(target, weights);
    weights.add(currWeight);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}


bool isMeasurableRecV3(int target, Vector<int>& weights, int index){
    // Base Case
    if (index >= weights.size()) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights[index];
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableRecV3(target - currWeight,
                                              weights, index + 1);
    bool leftScaleChoice = isMeasurableRecV3(target + currWeight,
                                             weights, index + 1);
    bool excludeChoice = isMeasurableRecV3(target, weights, index + 1);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}

bool isMeasurableV3(int target, Vector<int>& weights) {
    return isMeasurableRecV3(target, weights, 0);

}


bool isMeasurableRecV4(int target, Vector<int>& weights, int index) {
    // Base Case
    if (target < 0) return false; // Prune Case
    if (target == 0) return true; // Success Case
    if (index >= weights.size()) return false; // We've explored all `weights`
    // Recursive Cases
    int currWeight = weights[index];
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableRecV4(target - currWeight,
                                              weights, index + 1);
    bool leftScaleChoice = isMeasurableRecV4(target + currWeight,
                                             weights, index + 1);
    bool excludeChoice = isMeasurableRecV4(target, weights, index + 1);
    return rightScaleChoice || leftScaleChoice || excludeChoice;
}

bool isMeasurable(int target, Vector<int>& weights) {
    return isMeasurableRecV4(target, weights, 0);

}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Simple Positive Example") {
    Vector<int> weights = {1, 3};
    EXPECT(isMeasurable(2, weights));
}

PROVIDED_TEST("Provided Test: Simple Negative Example") {
    Vector<int> weights = {1, 3};
    EXPECT(!isMeasurable(5, weights));
}

PROVIDED_TEST("Provided Test: Complex Positive Example") {
    Vector<int> weights = {1, 3, 7};
    EXPECT(isMeasurable(6, weights));
}


PROVIDED_TEST("Additional Stress Test Cases - 1") {
    Vector <int> weights = {1, 3};
    EXPECT(isMeasurable(1, weights));
    EXPECT(isMeasurable(2, weights));
    EXPECT(isMeasurable(3, weights));
    EXPECT(isMeasurable(4, weights));
    EXPECT(!isMeasurable(5, weights));
    EXPECT(isMeasurable(0, weights));
}

PROVIDED_TEST("Additional Stress Test Cases - 2") {
    Vector <int> weights = {3, 10, 7, 8};
    EXPECT(!isMeasurable(9, weights));
    EXPECT(isMeasurable(14, weights));
    EXPECT(isMeasurable(15, weights));
    EXPECT(!isMeasurable(16, weights));
    EXPECT(isMeasurable(17, weights));
    EXPECT(isMeasurable(18, weights));
    EXPECT(!isMeasurable(19, weights));
    EXPECT(isMeasurable(21, weights));
    EXPECT(!isMeasurable(10000, weights));
}

PROVIDED_TEST("Additional Stress Test Cases - 3") {
    Vector <int> weights = {2, 4, 2, 6, 2, 8, 2,
                           10, 2, 12, 2, 14};
    EXPECT(isMeasurable(28, weights));
    EXPECT(isMeasurable(14, weights));
    EXPECT(isMeasurable(34, weights));
    EXPECT(isMeasurable(66, weights));
    EXPECT(!isMeasurable(68, weights));
}
