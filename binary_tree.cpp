#include "binary_tree.h"

BinaryTree::BinaryTree(){
    root = nullptr;
    
}

void BinaryTree::CreateNode(char c, int f){
    if(root == nullptr){
        TreeNode* newNode = new TreeNode;
        newNode->character = c;
        newNode->frequency = f;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
        return;
    }
    //
}

int BinaryTree::returnFrequency(){
    if(root!=nullptr){
        return root->frequency;
    }
    else return 0;
}



TreeNode* BinaryTree::GetRoot(){
    return root;
}



map<char, string> BinaryTree::Traversal(TreeNode* &node, map<char, string> mp, string s){
    if(node == nullptr){
        return mp;
    }
    // cout << node->frequency << endl;
    if(node->character != '-'){
        mp.insert({node->character, s});
        return mp;
    }
    //
    
    
    map<char, string> m1 = Traversal(node->left, mp, s+"0");
    map<char, string> m2 = Traversal(node->right, m1, s+"1");
    return m2;

}

map<char, string> BinaryTree::GetCodeByTraversal(){
    map<char, string> mp;
    string s = "";
    map<char, string> mpReturned = Traversal(root, mp, s);
    return mpReturned;
}

string BinaryTree::decodeII(string s, TreeNode* &node, string &bitstream, int &counter){
    cout << bitstream << endl;
    while(counter != bitstream.length()){
        if(node == nullptr){
            break;
        }
        if(node->character != '-'){
            s+=node->character;
            counter++;
            node = root;
        }   
        if(bitstream[counter] == '0'){
            node = node->left;
            
        }
        if(bitstream[counter] == '1'){
            node = node->right;
        }
        counter++;
        
    }
     
    return s;
    
}

string BinaryTree::GetStringDecoded(string &bitstream){
    string s; int counter = 0;
    return decodeII(s, root, bitstream, counter);
}