/*
 * CS106B Section Handout Test Harness: Section 7
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
#include "treenode.h"
#include "utility.h"
#include "error.h"
#include "stack.h"
#include "set.h"
using namespace std;

/*
 * Tree Equality (Code Writing)
 * --------------------------------------------------------
 * Write a function that take as input pointers to the roots
 * of two binary trees (not necessarily binary search trees),
 * then returns whether the two trees have the exact same
 * shape and contents.
 */

bool areEqualV1(TreeNode* one, TreeNode* two) {
    // ** Base Cases **
    // Success Base Case
    if (one == nullptr && two == nullptr) return true;

    // Failure Base Case 1: One of them is pointing at nullptr while the other isn't
    if (one == nullptr || two == nullptr) return false;
    // Failure Base Case 2: The data for each respective tree doesn't match up
    if (one->data != two->data) return false;

    // ** Recursive Cases **
    bool leftSide = areEqualV1(one->left, two->left);
    bool rightSide = areEqualV1(one->right, two->right);
    return leftSide && rightSide;
}

bool areEqual(TreeNode* one, TreeNode* two) {
    // ** Base Cases **
    // Success Base Case
    if (one == nullptr && two == nullptr) return true;

    // Failure Base Case
    if (one == nullptr || two == nullptr) return false;

    // ** Recursive Cases **
    return one->data == two->data && // Value Comparisons
        areEqual(one->left, two->left) && // Compare the Left Subtree
        areEqual(one->right, two->right); // Compare the Right Subtree
}

PROVIDED_TEST("Simple Tests for Tree Equality") {
    TreeNode *a = nullptr;
    TreeNode *b = nullptr;

    EXPECT(areEqual(a,b));

    a = createTreeFromVector({/* Level 1*/ 1});
    EXPECT(!areEqual(a,b));

    b = createTreeFromVector({/* Level 1*/ 1});
    EXPECT(areEqual(a,b));

    // same values but different structure
    freeTree(a);
    a = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ 3, EMPTY});

    freeTree(b);
    b = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ EMPTY, 3});

    EXPECT(!areEqual(a, b));

    freeTree(a);
    freeTree(b);

    // one tree is a subset of another but not equal
    a = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ 2, 3});
    b = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ 2, 3, /* Level 3*/ 4, EMPTY, EMPTY, 2});
    EXPECT(!areEqual(a, b));

    // complex trees that are equal
    freeTree(a);
    freeTree(b);

    a = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ 2, 3, /* Level 3*/ 4, 7, EMPTY, 2, /* Level 4 */ 5});
    b = createTreeFromVector({/* Level 1*/ 1, /* Level 2*/ 2, 3, /* Level 3*/ 4, 7, EMPTY, 2, /* Level 4 */ 5});
    EXPECT(areEqual(a, b));

    freeTree(a);
    freeTree(b);
}
