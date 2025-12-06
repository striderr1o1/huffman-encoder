#include "hfm.h"

HuffmanEncoder::HuffmanEncoder(){
    CharacterList = nullptr;
    BTlist = {};
}

void HuffmanEncoder::CreateLists(string str){
    map<char, int> mp;//declaring map
    for(int i = 0; i < str.length(); i++){
            mp[str[i]] = mp[str[i]] + 1;//looping over the map to generate frequency against the string
    }
    int size = mp.size();//getting map size and initializing a binary tree array
    
    CharacterList = new char[size];

    map<char, int>::iterator it = mp.begin();//assigning an iterator to the beginning of the map

    int i = 0;//loop i counter

    for(it = mp.begin(); it!=mp.end(); it++){// will run while map doesnt end
        CharacterList[i] = it->first;
        BinaryTree newTree;
        newTree.CreateNode(it->first, it->second);
        BTlist.push_back(newTree);
        // cout << BTlist[i].returnFrequency() << endl;
        //create node for each BTlist binary tree
        i++;//increment i
    }
}

BinaryTree* HuffmanEncoder::GetMinimumTree(){
    int min = BTlist[0].returnFrequency();
    int index = 0;

    for(int i = 0; i < BTlist.size(); i++){
        int curr = BTlist[i].returnFrequency();
        for(int j = 0; j < BTlist.size(); j++){
            if(BTlist[j].returnFrequency() < min){
                min = BTlist[j].returnFrequency();
                index = j;
            }
        }
    }

    vector<BinaryTree>::iterator it = BTlist.begin();
    BinaryTree* returningTree = &BTlist[index];
    cout << "Removing " << returningTree->returnFrequency() << " " << endl;
    BTlist.erase(it + index);
    return returningTree;
}

void HuffmanEncoder::MergeBinaryTrees(){
    int size = BTlist.size();
    for(int i = 0; i < BTlist.size(); i++){
            cout << BTlist[i].returnFrequency() << " ";
        }
    while(size!=1){
        BinaryTree* MinTree1 = GetMinimumTree();
        BinaryTree* MinTree2 = GetMinimumTree();
        BinaryTree newTree;
        int Tree1Freq = MinTree1->returnFrequency();
        int Tree2Freq = MinTree2->returnFrequency();
        int addedFreq = Tree1Freq + Tree2Freq;
        newTree.CreateNode('-', addedFreq);
        //add trees to new tree as nodes
        
        newTree.AddTreeNode(MinTree1->GetRoot());
        
        newTree.AddTreeNode(MinTree2->GetRoot());
        //this is giving 10 when it should be 1+1 = 2
        cout << " adding " << newTree.returnFrequency() << endl;
        BTlist.push_back(newTree);
        for(int i = 0; i < BTlist.size(); i++){
            cout << BTlist[i].returnFrequency() << " ";
        }
        size = BTlist.size();
    }
    cout << BTlist[0].returnFrequency() << endl;
    
}

void HuffmanEncoder::encode(){
    CreateLists("aaaa bbb cc dddd e f ggggg h");
    MergeBinaryTrees();
}

//1. use vectors