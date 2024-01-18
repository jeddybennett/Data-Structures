

#pragma once
#include <iostream>
#include <string>
#include<string>
#include<stdexcept>
#include <algorithm>

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        Node* prev;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), prev(nullptr), value(v), height(1) {}
    };

    AVL(): size_a(0), a_root(nullptr) {

    }

    ~AVL() {
        size_a = 0;
        clear();
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return a_root;
    }

    bool insert(T item) {
        if(insertHelper(a_root, item)){
            size_a++;
            return true;
        }
        return false;

    }

    bool remove(T item) {
        if(helperRemove(a_root,item)){
            size_a--;
            return true;
        }
        return false;
    }

    bool contains(T item) const {
        //check if the data is in your tree
        if (find(a_root, item)){
            return true;
        }
        else{
            return false;
        }
    }

    void clear() {
        //recurse through your tree deleting everything
        recursive_clear(a_root);

        //reset the size and the root value
        size_a = 0;
        a_root = nullptr;
    }

    int size() const {
        //return the number of nodes in the tree
        return size_a;
    }
private:
    //initialize your root node and size of tree
    Node * a_root;
    size_t size_a;

    bool find(Node* root, T item) const{
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
    bool helperRemove(Node*& root, T item){
        //check if the node exists
        if(!root){
            return false;
        }

        //check if you should iterate down the left subtree
        else if(item < root->value)
        {
            bool v = helperRemove(root->left, item);
            update_height(root);
            rebalance(root);
            return v;
        }
        //check if you should iterate down the right subtree
        else if(item > root->value)
        {
            bool v = helperRemove(root->right, item);
            update_height(root);
            rebalance(root);
            return v;
        }
        //check for no child case
        if(!root->left&!root->right){
            delete root;
            root = nullptr;
            return true;
        }
        //one child case
        else if(!root->left&&root->right){
            Node* temp = root->right;
            delete root;
            root = temp;
            return true;
        }
        else if(!root->right&&root->left){
            Node* temp = root->left;
            delete root;
            root = temp;
            return true;
        }
        //2 child case
        else{
            //get the in order predecessor
            Node* iop = root->left;
            while(iop->right){
                iop = iop->right;
            }
            //initialize a temp node and remove the target
            T new_data = iop->value;
            root->value = new_data;
            helperRemove(root->left, iop->value);
            update_height(root);
            rebalance(root);
            return true;
        }

    }
    bool insertHelper(Node*& n, int val){
        if(!n){
            //insert the node at the root
            n = new Node(val);
            return true;
        }
        //check if the node already exists in the tree
        if (val == n->value){
            return false;
        }
        //check if you should insert on the right subtree
        else if(val > n->value){
            bool ret = insertHelper(n->right, val);
            update_height(n);
            rebalance(n);
            return ret;
        }
        //check if you should insert on the left subtree
        else{
            bool ret = insertHelper(n->left, val);
            update_height(n);
            rebalance(n);
            return ret;
        }

    }
    Node* previous(Node* root){
        if (!root){
            //if the tree is empty, return a nullptr
            return nullptr;
        }
        //iterate until find the previous node
        Node* current = root->left;
        while(current->right){
            current = current->right;
        }
        return current;
    }


    void recursive_clear(Node* root) {
        //starting from the root, iterate through deleting the left and right subtrees
        if (root) {
            recursive_clear(root->left);
            recursive_clear(root->right);
            delete root;
        }
    }

    //find the correct data using the recursive step function starting from the root
    Node* node_find(T data){
        return _step(a_root, data);
    }
    //update the height of the tree at each step
    int update_height(Node*& root) {
        if (!root) {
            return 0;
        } else {
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
        update_height(root->left);
        update_height(root->right);
        update_height(root);
    }
};

//remove function for an AVL Tree