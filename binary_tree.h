#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <map>
using namespace std;

struct TreeNode
{
    int frequency;
    char character;
    TreeNode* left;
    TreeNode* right;
};

//binary tree class used in Huffman encoder class
// functions under private are those that are not given to user, but are used inside their wrappers
//CreateNode function for creating node (adds node as root element basically)
//return frequency (returns frequency of the root node/element)
// get code by traversal (generates code using recursion till reaches characters at the bottom of tree)

class BinaryTree{
    private:

    TreeNode* root;
    
    map<char, string> Traversal(TreeNode* &root, map<char, string> mp, string s);
    string decodeII(string s, TreeNode* &node, string &bitstream, int &counter);
    public:

    BinaryTree();
    void CreateNode(char character, int frequency);
    int returnFrequency();
    TreeNode* GetRoot();
    map<char, string> GetCodeByTraversal();
    string GetStringDecoded(string &bitstream);
    
    
};

#endif