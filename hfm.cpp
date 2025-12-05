#include "hfm.h"

HuffmanEncoder::HuffmanEncoder(){
    CharacterList = nullptr;
    BTlist = nullptr;
}

void HuffmanEncoder::CreateLists(string str){
    map<char, int> mp;//declaring map
    for(int i = 0; i < str.length(); i++){
            mp[str[i]] = mp[str[i]] + 1;//looping over the map to generate frequency against the string
    }
    int size = mp.size();//getting map size and initializing a binary tree array
    BTlist = new BinaryTree[size];
    CharacterList = new char[size];
    map<char, int>::iterator it = mp.begin();//assigning an iterator to the beginning of the map
    int i = 0;//loop i counter
    for(it = mp.begin(); it!=mp.end(); it++){// will run while map doesnt end
        CharacterList[i] = it->first;
        BTlist[i].CreateNode(it->first, it->second);//create node for each BTlist binary tree
        // cout << BTlist[i].returnFrequency() << endl;
        i++;//increment i
    }
}
void HuffmanEncoder::MergeBinaryTrees(){
    int size = sizeof(BTlist)/sizeof(BTlist[0]);
    
}

void HuffmanEncoder::encode(){
    CreateLists("I am Ranger boy");
}