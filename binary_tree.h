#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int frequency;
    char character;
    TreeNode* left;
    TreeNode* right;
};


class BinaryTree{
    private:

    TreeNode* root;
    void AddTreeNodeII(TreeNode* node, TreeNode* startingNode);
    string Traversal(TreeNode* root, string s);
    map<char, string> Traversal(TreeNode* &root, map<char, string> mp, string s);
    

    public:

    BinaryTree();
    void CreateNode(char character, int frequency);
    int returnFrequency();
    void AddTreeNode(TreeNode* node);
    TreeNode* GetRoot();
    map<char, string> GetCodeByTraversal();
    
    
};

#endif