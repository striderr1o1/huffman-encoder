#ifndef BINARY_TREE.H
#define BINARY_TREE.H

#include <iostream>
using namespace std;

struct TreeNode
{
    /* data */
    int value;
    char character;
    TreeNode* left;
    TreeNode* right;
};


class BinaryTree{
    private:
    TreeNode* root;
    public:
    BinaryTree();
    void CreateNode(char character, int value);
};

#endif BINARY_TREE.H