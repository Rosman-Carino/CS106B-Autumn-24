/*
 * Author: Rosman R Cariño
 * CS106B Section Handout Test Harness: Section 8
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
#include "utility.h"
#include "error.h"
#include "stack.h"
using namespace std;

/*
 * Decode Sequence (Code Writing)
 * --------------------------------------------------------
 * Write a function that accepts a ternary tree and string representing
 * a sequence of directions and returns the decoded string.
 */

/**
 * @brief decodeSequenceV1: Iterative solution to this.
 * @param tree
 * @param sequence
 * @return
 */
string decodeSequenceV1(TernaryTreeNode* tree, string sequence) {
    string message = "";
    for (char dir : sequence) {
        if (dir == 'L') tree = tree->left;
        if (dir == 'M') tree = tree->middle;
        if (dir == 'R') tree = tree->right;
        if (tree == nullptr) break;
        message += tree->ch;
    }
    return message;
}


/**
 * @brief decodeSequenceV2: Recursive Solution to This problem
 * @param tree
 * @param sequence
 * @return
 */
string decodeSequenceV2(TernaryTreeNode* tree, string sequence) {
    // Base Case:
    if (sequence.empty()) return "";
    char currDir = sequence[0];
    if (currDir == 'L') tree = tree->left;
    if (currDir == 'M') tree = tree->middle;
    if (currDir == 'R') tree = tree->right;
    // Recursive Cases:
    if (tree != nullptr) {
        return tree->ch + decodeSequenceV2(tree, sequence.substr(1));
    } else {
        return "";
    }
}

string decodeSequence(TernaryTreeNode *tree, string sequence) {
    return decodeSequenceV1(tree, sequence);
}



/*
 * Print All Paths (Code Writing)
 * --------------------------------------------------------
 * Write a function that accepts a ternary tree prints all the valid
 * paths that lead to a leaf in the ternary tree.
 */
void printAllPaths(TernaryTreeNode* tree) {

}




PROVIDED_TEST("Simple set of test cases for decodeSequence") {
    TernaryTreeNode* node1L = new TernaryTreeNode('D');
    TernaryTreeNode* node1M = new TernaryTreeNode('E');
    TernaryTreeNode* node1R = new TernaryTreeNode('F');

    TernaryTreeNode* node2L = new TernaryTreeNode('G');
    TernaryTreeNode* node2M = new TernaryTreeNode('H');
    TernaryTreeNode* node2R = new TernaryTreeNode('I');

    TernaryTreeNode* node1 = new TernaryTreeNode('A', node1L, node1M, node1R);
    TernaryTreeNode* node2 = new TernaryTreeNode('B', node2L, node2M, node2R);
    TernaryTreeNode* node3 = new TernaryTreeNode('C');

    node3->middle = new TernaryTreeNode('J');

    TernaryTreeNode* root = new TernaryTreeNode('-', node1, node2, node3);

    EXPECT_EQUAL(decodeSequence(root, "LR"), "AF");
    EXPECT_EQUAL(decodeSequence(root, "RMR"), "CJ");
}
