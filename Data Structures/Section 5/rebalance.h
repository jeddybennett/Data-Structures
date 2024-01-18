#pragma once
#include <iostream>
#include <string>
#include<string>
#include<stdexcept>
#include <algorithm>

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

//update the height of the tree at each step
int update_height(Node*& root){
    if (!root){
        //if the node does not exist, the height is 0
        return 0;
    }
    else{
        //otherwise the height of the tree is updated
        root->height = 1 + std::max(update_height(root->right), update_height(root->left));
        return root->height;
    }
}
void promote_left(Node*& root) {
    //define a new node as the left child of current node and then rotate
    Node* newNode = root->left;
    root->left = newNode->right;
    newNode->right = root;

    //update the height of the current node and new node accordingly
    root->height = 1 + std::max(update_height(root->right), update_height(root->left));
    newNode->height = 1 + std::max(update_height(newNode->right), update_height(newNode->left));
    root = newNode;
}

void promote_right(Node*& root) {
    //define a new node as the right child of current node and then rotate
    Node* newNode = root->right;
    root->right = newNode->left;
    newNode->left = root;

    //update the height of the current node and new node accordingly
    root->height = 1 + std::max(update_height(root->right), update_height(root->left));
    newNode->height = 1 + std::max(update_height(newNode->right), update_height(newNode->left));
    root = newNode;
}

void rebalance(Node*& root) {
    //check the balance factor (height of left subtree - height of right subtree)
    int balance_factor = update_height(root->left) - update_height(root->right);

    //check if there is a left subtree imbalance
    if (balance_factor > 1){

        //perform a left-left rotation
        if(update_height(root->left->left) >= update_height(root->left->right)) {
            promote_left(root);
        }
        else{
            //perform a left-right rotation
            promote_right(root->left);
            promote_left(root);
        }
    }
    //check if there is a right subtree imbalance
    if (balance_factor < -1) {

        //perform a right-right rotation
        if (update_height(root->right->right) >= update_height(root->right->left)) {
            promote_right(root);
        } else {
            //perform a right-left rotation
            promote_left(root->right);
            promote_right(root);
        }
    }
}
