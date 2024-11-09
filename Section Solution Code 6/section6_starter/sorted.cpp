/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 6
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "vector.h"
using namespace std;

/*
 * All out of Sorts (Code Writing)
 * --------------------------------------------------------
 * Write a function that takes in a pointer to the front of a
 * linked list of integers and returns whether or not the list
 * that's pointed to is in sorted (nondecreasing) order. An
 * empty list is considered to be sorted.
 */

/**
 * @brief isSorted: Recall from `lastElementOfV1` in `utility.cpp` we can loop
 *                  the way we do on `line 38` because we're comparing 2 values.
 * @param front
 * @return
 */
bool isSortedV1(Node* front) {
    if (front == nullptr || front->next == nullptr) return true; // This checks for an empty `linked list` or a `linked list` of size 1.
    Node* current = front;
    while (current->next != nullptr) {
        if (current->data > current->next->data) { // Perform sorted comparison.
            return false;
        }
        current = current->next;
    }
    // After iterating through the entire `linked list` we know that the `linked list` is sorted.
    return true;
}

/**
 * @brief isSorted: Similar to `isSortedV1`, but we are using a `for loop` here.
 * @param front
 * @return
 */
bool isSortedV2(Node* front) {
    if (front == nullptr || front->next == nullptr) return true; // This checks for an empty `linked list` or a `linked list` of size 1.
    for (Node* current = front; current->next != nullptr; current = current->next) {
        if (current->data > current->next->data) { // Perform sorted comparison.
            return false;
        }
    }
    return true;
}
/**
 * @brief isSortedV3: Here we have a recursive solution, but once again
 *                       although the code is elegant, the downside here is
 *                       that if we have a LONG `list` we can potentially
 *                       stack overflow.
 * @param front
 * @return
 */
bool isSortedV3(Node* front) {
    // Base Case: Empty List or List of Size 1
    if (front == nullptr || front->next == nullptr) {
        return true;
    }
    // Perform Sorted comparisons
    if (front->data > front->next->data) {
        return false;
    }
    // Recursive Case: We move to the next `link` in the `linked list`
    return isSortedV3(front->next);
}

bool isSorted(Node* front) {
    return isSortedV1(front);
}

/* * * * * Provided Tests Below This Point * * * * */


PROVIDED_TEST("Simple Sorted Example") {
    Node *list = createListFromVector({1,2,3,3,4,5});
    EXPECT(isSorted(list));
    freeList(list);
}

PROVIDED_TEST("Simple Unsorted Example") {
    Node *list = createListFromVector({1,2,3,1,4});
    EXPECT(!isSorted(list));
    freeList(list);
}
