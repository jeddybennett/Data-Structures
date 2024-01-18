#pragma once

#include <iostream>
#include <string>
#include<string>
#include<stdexcept>
template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        Node* prev;
        T value;

        Node(T v) :left(nullptr), right(nullptr), prev(nullptr), value(v) {}
    };
    //implement the constructor
    BST(): size_b(0), b_root(nullptr){
    }

    //implement the destructor
    ~BST(){
        size_b = 0;
        clear();
    }

    const Node* getRootNode() const {
        //return the root node
        return b_root;
    }

    bool insert(T item) {
        //check if the item already exists in the tree
        if (find(b_root, item)){
            return false;
        }
        //if the root is empty, insert at the root
        else if(!b_root){
            b_root = new Node(item);
            b_root->left = nullptr;
            b_root->right = nullptr;
            size_b++;
            return true;
        }
        //if not the root, find the parent and insert as the child of the parent
        else{
            Node* parent = find_parent(b_root, item);
            Node* new_node = new Node(item);
            new_node->prev = parent;
            new_node->right = nullptr;
            new_node->left = nullptr;
            size_b++;
            return true;
        }
    }

    bool remove(T item) {
        //check if the data is in the tree or not
        if (!find(b_root, item)){
            return false;
        }
        //if it is in the tree, get the target and parent
        Node* target = node_find(item);
        Node* parent = target->prev;

        //0 child case
        if(!target->left && !target->right){
            //target is the root
            if(target == b_root){
                b_root = nullptr;
            }
            else if (target == parent->left){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
            size_b--;
            delete target;
            return true;
        }
        //2 child case
        else if(target->right && target->left)
        {
            //recurse and reorganize the tree correctly
            Node* precede = previous(target);
            remove(precede->value);
            target->value = precede->value;
            size_b--;
            return true;
        }
        else{
            //one child case, check if it has a left or right child
            Node*child= (target->left)?target->left : target->right;
            if(target == b_root){
                //target is the root
                b_root = child;
            }
            else if(target == parent->left){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            //reconnect the child node to the new parent node
            if (child){
                child->prev = parent;
            }
            size_b--;

            delete target;
            return true;
        }

    }

    bool contains(T item) const {
        //check if the data is in your tree
        if (find(b_root, item)){
            return true;
        }
        else{
            return false;
        }
    }

    void clear() {
        //recurse through your tree deleting everything
        recursive_clear(b_root);

        //reset the size and the root value
        size_b = 0;
        b_root = nullptr;
    }

    int size() const {
        //return the number of nodes in the tree
        return size_b;
    }

private:
    //initialize your root node and size of tree
    Node * b_root;
    size_t size_b;

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

    Node* find_parent(Node* root, T data){
        //check if you iterate through the left subtree
        if(data < root->value){
            //if there's still children, continue to iterate
            if (root->left){
                return find_parent(root->left, data);
            }
            else{
                //otherwise, set the data as the left child of the current node
                Node* new_node = new Node(data);
                new_node->prev = root;
                root->left = new_node;
                new_node->left = nullptr;
                new_node->right = nullptr;
                return new_node;
            }
        }
        //iterate through the right subtree
        else if(data > root -> value){
            //iterate if you're not at the base of the tree
            if(root->right){
                return find_parent(root->right,data);
            }
            else{
                //initialize the data as a right child in your tree
                Node* new_node = new Node(data);
                new_node->prev = root;
                root->right = new_node;
                new_node->left = nullptr;
                new_node->right = nullptr;

            }
        }
        //return the parent node
        return root;
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


    Node* _step(Node* current, T stuff){
        //step through your tree until the correct node is found
        if (current->value == stuff){
            return current;
        }
        //step through the left subtree
        else if (stuff < current->value){
            return _step(current -> left, stuff);
        }
        //step through the right subtree
        else{
            return _step(current->right, stuff);
        }

    }

    //find the correct data using the recursive step function starting from the root
    Node* node_find(T data){
        return _step(b_root, data);
    }
};
