# Huffman Encoder Using Binary Trees

## The Concept:

Huffman Encoding is a technique to compress text files by replacing the bits of the most frequent occuring characters with lower bit count. For example, in the string "aaaa bb c ddddd", d occurs five times. So if we replace its bits with lower bit count, it should help reducing the size of the file.

## Our Implementation:

This project contains two headers files and two source files:
- hfm.h
- hfm.cpp
- binary_tree.h
- binary_tree.cpp

## binary_tree.h and binary_tree.cpp

The binary_tree.h header file contains the following:

### TreeNode Structure:
a struct for representing node in a binary tree. It contains int frequency, char character, and TreeNode* left and TreeNode* right pointers.

### BinaryTree Class:
A binary tree implementation. Contains these private data members and functions:
- TreeNode* root
- map<char, string> Traversal(TreeNode* &root, map<char, string> mp string s): this function is called inside of GetCodeByTraversal function. It basically calculates the 0s and 1s taken in reaching a character. It then stores 0s and 1s in the form of a bit string against the character using a map. It does this for all the characters, basically traversing using recursion till each leafnode is reached and character's bit string calculated. Then it returns the final map.

Contains these public functions:
- BinaryTree(): The constructor for binary tree
- void CreateNode(char character, int frequency): creates root node of binary tree (only implemented for root node initialization)
- int returnFrequency(): returns frequency stored in the root node
- TreeNode* GetRoot(): returns the pointer to the root node of the tree
- map<char, string> GetCodeByTraversal(): 


