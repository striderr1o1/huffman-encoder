#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H
#include <iostream>
#include <bits/stdc++.h>
#include "binary_tree.h"
#include <fstream>
using namespace std;

//private:
// binary trees list, characters list (didnt use this tho)
// string text (extracted into this variable from file)
// createLists function for creating binary trees list, calculating frequency of characters
// merge binary trees function to keep on merging trees till only one tree is left
//GetminimumTree function (used in merge binary tree function)
//sortlist(function written for sorting binary trees list)
//readFile (file reading function, stores text as string in Text data variable)

class HuffmanEncoder{
    private:
    vector<BinaryTree> BTlist;
    char* CharacterList;
    map<char, string> BinaryCodes;
    string Text;//text extracted from file
    string BitStream;//stream of bits
    string DecodedText;
    //encoding functions
    void CreateLists(string str);
    void MergeBinaryTrees();
    BinaryTree GetMinimumTree();
    void SortList();
    void readFile(const string &filename);
    void WriteAsBitStream();
    void WriteBytesToFile();
    //decoding functions
    
    public:
    HuffmanEncoder();
    void encode(string filename);
    void decode();
    long long getFileSize(const string &filename);
    //decode
    

};
#endif
//1. extract string from file
//2. 