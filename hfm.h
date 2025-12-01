#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H
#include <iostream>
#include <bits/stdc++.h>
#include "binary_tree.h"
using namespace std;

class HuffmanEncoder{
    private:
    //binary tree list
    //file text
    //unique character list
    //encoded text
    //frequency calculator
    //extract string from file
    //binary tree function
    BinaryTree* BTlist;
    char* CharacterList;
    void GetFrequency(string str);
    public:
    HuffmanEncoder();
    //encode
    //decode
    //

};
#endif HUFFMANENCODER_H
//1. extract string from file
//2. 