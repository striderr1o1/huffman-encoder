# Huffman Encoder Using Binary Trees

## The Concept:

Huffman Encoding is a technique to compress text files by replacing the bits of the most frequent occuring characters with lower bit count. For example, in the string "aaaa bb c ddddd", d occurs five times. So if we replace its bits with lower bit count, it should help reducing the size of the file.

## Our Implementation:

This project contains two headers files and two source files:
- hfm.h
- hfm.cpp
- binary_tree.h
- binary_tree.cpp

### binary_tree.h and binary_tree.cpp

The binary_tree.h header file contains the following:

- *TreeNode Structure*: a struct for representing node in a binary tree. It contains int frequency, char character, and TreeNode* left and TreeNode* right pointers.

- *BinaryTree Class*:

This 