#pragma once

#include <climits>
#include "vector.h"

#define EMPTY INT_MAX

struct ListNode {
    int data;
    ListNode *next;
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    // default constructor does not initialize
    TreeNode() {}   

    // 3-arg constructor sets fields from arguments
    TreeNode(int d, TreeNode* l, TreeNode* r) {  
        data = d;
        left = l;
        right = r;
    }
};


struct TernaryTreeNode {
    char ch;
    TernaryTreeNode *left;
    TernaryTreeNode *middle;
    TernaryTreeNode *right;

    TernaryTreeNode() {}

    TernaryTreeNode(char c) {
        ch = c;
        left = middle = right = nullptr;
    }

    TernaryTreeNode(char c, TernaryTreeNode* l, TernaryTreeNode* m, TernaryTreeNode* r) {
        ch = c;
        left = l;
        middle = m;
        right = r;
    }

    bool isLeaf() {
        return left == nullptr && middle == nullptr && right == nullptr;
    }
};

TreeNode* createTreeFromVector(Vector<int> nums);
void freeTree(TreeNode* root);
bool treeEqual(TreeNode* a, TreeNode *b);
void printTree(TreeNode *root);

ListNode* createListFromVector(Vector<int> nums);
void freeList(ListNode* list);
bool listEqual(ListNode* a, ListNode *b);
void printList(ListNode *list);
