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
using namespace std;

/*
 * Validating a Binary Search Tree (Code Writing)
 * --------------------------------------------------------
 * Your task is to write a function isBST that accepts a pointer to 
 * the root of a tree and then determines whether or not that tree
 * satisfies the binary search tree properties. You can assume that what 
 * you’re getting as input is actually a tree, so, for example, you won’t 
 * have a node that has multiple pointers into it, no node will point at itself, 
 * etc.
 */

bool isBSTHelperV1(TreeNode* root, TreeNode* lowerBound, TreeNode* upperBound) {
    // ** Base Cases**
    if (root == nullptr) return true; // Success Case

    // Check if `root` is not less than or equal to the lowerBound
    if(lowerBound != nullptr && root->data <= lowerBound->data) return false; // Failure Case 1

    // Check if `root` is not greater than or equal to the upperBound
    if(upperBound != nullptr && root->data >= upperBound->data) return false; // Failure Case 2

    // ** Recursive Cases **

    // Recurse on the left, lowerBound is still the same, and our upperBound is the root.
    bool leftSubTree = isBSTHelperV1(root->left, lowerBound, root);
    // Recurse on the right, lowerBound is the root, and our upperBound is the same.
    bool rightSubTree = isBSTHelperV1(root->right, root, upperBound);

    // Return is the Tree is a valid BST
    return leftSubTree && rightSubTree;
}


bool isBSTHelperV2(TreeNode* root, TreeNode* lowerBound, TreeNode* upperBound) {
    // ** Base Cases**
    if (root == nullptr) return true; // Success Case

    // Check that the root is not less than or equal to the lowerBound
    if (lowerBound != nullptr && root->data <= lowerBound->data) return false;
    // Check that the root is not greater than or equal to upperBound
    if (upperBound != nullptr && root->data >= upperBound->data) return false;

    // ** Recursive Cases **
    return isBSTHelperV2(root->left, lowerBound, root) &&
           isBSTHelperV2(root->right, root, upperBound);
}

bool isBSTHelperV3(TreeNode* root, int lowerBound, int upperBound) {
    // ** Base Cases **
    if (root == nullptr) return true; // Success Case

    if (root->data <= lowerBound) return false; // Failure Case 1
    if (root->data >= upperBound) return false; // Failure Case 2

    // ** Recursive Cases **

    // Recurse on the left, lowerBound is still the same, and our upperBound is the root.
    bool leftSubTree = isBSTHelperV3(root->left, lowerBound, root->data);
    // Recurse on the right, lowerBound is the root, and our upperBound is the same.
    bool rightSubTree = isBSTHelperV3(root->right, root->data, upperBound);
    return leftSubTree && rightSubTree;
}

bool isBSTHelperV4(TreeNode* root, int lowerBound, int upperBound) {
    // ** Base Cases **
    if (root == nullptr) return true; // Success Case

    if (root->data <= lowerBound) return false; // Failure Case 1
    if (root->data >= upperBound) return false; // Failure Case 2

    // ** Recursive Cases **

    // Recurse on the left, lowerBound is still the same, and our upperBound is the root.
    return isBSTHelperV4(root->left, lowerBound, root->data) &&
               isBSTHelperV4(root->right, root->data, upperBound);
}

bool isBSTHelperV5(TreeNode* root, int lowerBound, int upperBound) {
    // ** Base Cases **
    if (root == nullptr) return true; // Success Case

    // Combine Both Failure Cases into One
    if (root->data <= lowerBound && root->data >= upperBound) return false;

    // This is another way below: Feel free to uncomment line 105
    //if (upperBound <= root->data <= lowerBound) return false;

    // ** Recursive Cases **

    // Recurse on the left, lowerBound is still the same, and our upperBound is the root.
    return isBSTHelperV5(root->left, lowerBound, root->data) &&
           isBSTHelperV5(root->right, root->data, upperBound);
}


bool isBST(TreeNode* root) {
    // Call a helper function to provide us a lowerBound and upperBound for
    // the current `root` we are inspecting.
    return isBSTHelperV4(root, INT_MIN, INT_MAX);
}

PROVIDED_TEST("Simple positive tests for isBST function") {
    TreeNode *tree = nullptr;
    EXPECT(isBST(tree));

    tree = createTreeFromVector({/* Level 1*/ 5});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ EMPTY, 6});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 8, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 8, 10});
    EXPECT(isBST(tree));

    freeTree(tree);
}

PROVIDED_TEST("Simple negative tests for isBST function") {
    TreeNode *tree = createTreeFromVector({5, 6});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 3});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, 7, EMPTY, EMPTY});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 7, 1, EMPTY, EMPTY});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, EMPTY, 8, 9});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, EMPTY, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 1, 10});
    EXPECT(!isBST(tree));

    freeTree(tree);
}

