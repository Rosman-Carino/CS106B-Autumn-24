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
#include "error.h"
#include "vector.h"
using namespace std;

/*
 * Linked List Warmup (Code Writing)
 * --------------------------------------------------------
 * Write a function that adds up the values of all the elements
 * in the linked list. Next, write a function that returns a
 * pointer to the last element of a linked list (and reports an
 * error if the list is empty).
 */


/**
 * @brief sumOfElementsInV1: Here we use a `while loop` to iterate through
 *          `list`
 * @param list
 * @return
 */
int sumOfElementsInV1(Node* list) {
    int sum = 0;
    Node *current = list;
    while (current != nullptr) {
        sum += current->data;
        current = current->next; // Need to make sure we update `current` to
                                // the next node.
    }
    return sum;
}


/**
 * @brief sumOfElementsInV2: In this version we use a `for loop` to iterate
 * through `list`
 * @param list
 * @return
 */
int sumOfElementsInV2(Node* list) {
    int sum = 0;
    for (Node* current = list; current != nullptr; current = current->next) {
        sum += current->data;
    }
    return sum;
}

/**
 * @brief sumOfElementsInV3: In this version we are using recursion to iterate
 *          through `list`. Although the code is elegant, the downside here is
 *          that if we have a LONG `list` we can potentially stack overflow.
 * @param list
 * @return
 */
int sumOfElementsInV3(Node* list) {
    if (list == nullptr) {
        return 0;
    }
    int currValue = list->data;
    return currValue + sumOfElementsInV3(list->next);
}

int sumOfElementsIn(Node* list) {
    return sumOfElementsInV1(list);
}

/**
 * @brief lastElementOf: Here we are using a `while loop` approach to obtain the
 *              last `Node` of `list`. We want to be one linked behind whenever
 *              we want to return the last thing. This mechnanics of this code
 *              below is important for rewiring linked lists for the following
 *              scenarios:
 *                  - Adding a Node to a linked list.
 *                  - Deleting a Node from a linked list.
 *                  - Performing comparisons between 2 `Nodes`
 *
 * @param list
 * @return
 */
Node* lastElementOfV1(Node* list) {
    Node* current = list;
    while (current->next) {
        current = current->next;
    }
    return current;
}

/**
 * @brief lastElementOf: Here we have a recursive solution, but once again
 *                       although the code is elegant, the downside here is
 *                       that if we have a LONG `list` we can potentially
 *                       stack overflow.
 * @param list
 * @return
 */
Node* lastElementOfV2(Node* list) {
    if (list->next == nullptr) {
        return list;
    }
    return lastElementOfV2(list->next);
}

/**
 * @brief lastElementOfV3: Here we have a `for loop` version. Notice that we
 *                       peform a check if the `next node` will be pointing to
 *                       `nullptr`.
 * @param list
 * @return
 */
Node* lastElementOfV3(Node* list) {
    Node* result = nullptr;
    for(Node* current = list; current != nullptr; current = current->next) {
        // We're about to reach the end, so let's break out of here.
        if (current->next == nullptr) {
            result = current;
            break;
        }
    }
    return result;
}

Node* lastElementOf(Node * list) {
    return lastElementOfV1(list);
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Basic Sum Example") {
    Node *list = createListFromVector({1, 2, 3, 4, 5});
    EXPECT_EQUAL(sumOfElementsIn(list), 15);
    freeList(list);
}

PROVIDED_TEST("Basic Find Last Example") {
    Node *list = createListFromVector({1,2,3});
    EXPECT_EQUAL(lastElementOf(list), list->next->next);
    freeList(list);
}


