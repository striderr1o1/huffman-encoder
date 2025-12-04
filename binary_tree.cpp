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