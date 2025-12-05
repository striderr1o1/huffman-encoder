#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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
    int returnFrequency();
};

#endif