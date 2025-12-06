#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H
#include <iostream>
#include <bits/stdc++.h>
#include "binary_tree.h"
using namespace std;

class HuffmanEncoder{
    private:
    vector<BinaryTree> BTlist;
    char* CharacterList;
    void CreateLists(string str);
    void MergeBinaryTrees();
    BinaryTree* GetMinimumTree();
    public:
    HuffmanEncoder();
    
    void encode();
    //decode
    

};
#endif
//1. extract string from file
//2. 