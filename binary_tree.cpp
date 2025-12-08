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

void BinaryTree::AddTreeNode(TreeNode* node){
    //to be continued
    AddTreeNodeII(node, root);
}
//error coming over here
void BinaryTree::AddTreeNodeII(TreeNode* node, TreeNode* CurrentNode){
    // cout << node->frequency << endl;
    if(CurrentNode==nullptr){
        CurrentNode = node;
        return;
    }
    if(node->frequency < CurrentNode->frequency){
        AddTreeNodeII(node, CurrentNode->left);
    }
    if(node->frequency >= CurrentNode->frequency){
        AddTreeNodeII(node, CurrentNode->right);
    }
}

TreeNode* BinaryTree::GetRoot(){
    return root;
}

string BinaryTree::Traversal(TreeNode* node, string s){
    if(node==nullptr){
        return s;
    }
    //
    return s;

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