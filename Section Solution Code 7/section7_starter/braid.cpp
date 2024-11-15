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
#include "stack.h"
#include "set.h"
using namespace std;

/*
 * Braiding a Linked List (Code Writing)
 * --------------------------------------------------------
 * Write a function braid that takes a linked list, and weaves
 * the reverse of that list into the original. (In this case,
 * you will need to create new nodes.)
 */

/**
 * @brief reversedListV1: This is version 1 of reversing a linked list. Notice
 *          that `front` is passed by value.
 * @param front: Because `front` is passed by value after exiting the scope of
 *              this function the original pointer to `front` won't be changed.
 * @return
 */
Node* reversedListV1(Node* front) {
    Node* reversed = nullptr;
    while (front != nullptr) {
        Node* currNode = new Node();
        currNode->data = front->data;
        currNode->next = reversed;
        reversed = currNode;
        front = front->next;
    }
    return reversed;
}
/**
 * @brief reversedListV1: This is version 1 of reversing a linked list. Notice
 *          that `front` is passed by reference.
 * @param front: Because `front` is passed by referened after exiting the scope of
 *              this function the original pointer to `front` will be at
 *              `nullptr`. Therefore, we need to have `current` to make sure
 *              `front` doesn't change within this function.
 * @return
 */
Node* reversedListV2(Node* &front) {
    Node* reversed = nullptr;
    Node* current = front;
    while (current != nullptr) {
        Node* currNode = new Node();
        currNode->data = current->data;
        currNode->next = reversed;
        reversed = currNode;
        current = current->next;
    }
    return reversed;
}
/**
 * @brief reversedListV3: This is another version of reversing a linked list,
 *          but using a `for loop`.
 * @param front
 * @return
 */
Node* reversedListV3(Node* &front) {
    Node* reversed = nullptr;
    for (Node* current = front; current != nullptr; current = current->next) {
        Node* currNode = new Node();
        currNode->data = current->data;
        currNode->next = reversed;
        reversed = currNode;
    }
    return reversed;
}

/**
 * @brief braidV1: Here we have reversed the original Linked List. Then
 *              we braid it by iterating through the original linked list
 *              and rewire.
 * @param front
 */
void braidV1(Node*& front) {
    Node* current = front;
    // Step 1: Reveresed the Linked List
    Node* reversed = reversedListV1(front);
    // Step 2: Braiding
    while (current != nullptr) {
        Node* tempReversed = reversed->next;
        reversed->next = current->next;
        current->next = reversed;
        reversed = tempReversed;
        current = current->next->next;
    }
}

/**
 * @brief braidV2: Similar to version, we have decided to create 2 temporary
 *              pointers to update `current` and `reversed` after re-wiring.
 * @param front
 */
void braidV2(Node*& front) {
    Node* current = front;
    // Step 1: Reveresed the Linked List
    Node* reversed = reversedListV3(front);
    // Step 2: Braiding
    while (current != nullptr) {
        Node* tempCurrent = current->next;
        Node* tempReversed = reversed->next;
        current->next = reversed;
        reversed->next = tempCurrent;
        reversed = tempReversed;
        current = current->next->next;
    }
}

/**
 * @brief braidV3: Here we just iterate until `reversed` is pointing at `nullptr`
 * @param front
 */

void braidV3(Node*& front) {
    Node* current = front;
    // Step 1: Reveresed the Linked List
    Node* reversed = reversedListV3(front);
    while(reversed != nullptr) {
        Node* tempReversed = reversed->next;
        reversed->next = current->next;
        current->next = reversed;
        reversed = tempReversed;
        current = current->next->next;
    }
}

/**
 * @brief braidV4: Similar to V1, but instead of setting
 *          `current` = `current->next->next` we can just
 *          set it `reversed->next` because it's already pointing there. Then
 *          we can update where `reversed`.
 * @param front
 */
void braidV4(Node*& front) {
    Node* current = front;
    // Step 1: Reveresed the Linked List
    Node* reversed = reversedListV3(front);
    while(current != nullptr) {
        Node* tempReversed = reversed->next;
        reversed->next = current->next;
        current->next = reversed;
        current = reversed->next;
        reversed = tempReversed;
    }
}

void braid(Node*& front) {
    braidV1(front); // You can just which option you want.
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("First example from handout") {
    Node *originalList = createListFromVector({1, 4, 2});
    Node *braidedList = createListFromVector({1, 2, 4, 4, 2, 1});

    braid(originalList);

    EXPECT(listEqual(originalList, braidedList));
}

PROVIDED_TEST("Second example from handout") {
    Node *originalList = createListFromVector({3});
    Node *braidedList = createListFromVector({3, 3});

    braid(originalList);

    EXPECT(listEqual(originalList, braidedList));
}

PROVIDED_TEST("Third example from handout") {
    Node *originalList = createListFromVector({1, 3, 6, 10, 15});
    Node *braidedList = createListFromVector({1, 15, 3, 10, 6, 6, 10, 3, 15, 1});

    braid(originalList);

    EXPECT(listEqual(originalList, braidedList));
}
