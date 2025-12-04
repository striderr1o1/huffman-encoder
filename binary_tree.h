#ifndef BINARY_TREE.H
#define BINARY_TREE.H

#include <iostream>
using namespace std;

struct TreeNode
{
    /* data */
    int frequency;
    char character;
    TreeNode* left;
    TreeNode* right;
};


class BinaryTree{
    private:
    TreeNode* root;
    public:
    BinaryTree();
    void CreateNode(char character, int frequency);
};

#endif BINARY_TREE.H