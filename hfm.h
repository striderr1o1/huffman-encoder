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
    string Text;
    void CreateLists(string str);
    void MergeBinaryTrees();
    BinaryTree GetMinimumTree();
    void SortList();
    void readFile(const string &filename);
    public:
    HuffmanEncoder();
    
    void encode(string filename);
    //decode
    

};
#endif
//1. extract string from file
//2. 