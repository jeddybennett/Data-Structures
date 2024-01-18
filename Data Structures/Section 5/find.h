#pragma once
#include <iostream>
#include <string>

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : left(nullptr), right(nullptr), value(v) {}
};

bool find(Node* root, int item) {
    //check if the root is empty
    if(!root){
        return false;
    }

    //check if the value was found
    if (root->value == item){
        return true;
    }

    //check if you should iterate through the left subtree
    else if(item < root->value){
        return find(root->left, item);
    }

    //otherwise iterate through the right subtree
    else{
        return find(root->right, item);
    }
}
