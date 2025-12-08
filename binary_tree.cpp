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

string BinaryTree::GetCodeByTraversal(){
    string s = "";
    string str = Traversal(root, s);
    return str;
}