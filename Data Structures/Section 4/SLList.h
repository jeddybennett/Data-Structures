#pragma once
#include <cstddef>
#include <iostream>

template <class T>
class SLList {
public:
    struct Node {
        //define your next as a Node and the value as type T
        Node* next;
        T value;

        //Define a node with the next being a pointer to none and a value
        Node(T v) : next(nullptr), value(v) {}
    };
private:
    //define the head node
    Node *head;

public:
    //define your singly linked lists
    SLList() {}

    ~SLList() {}

    const Node* get_head() const {
        //return your defined head
        return head;
    }

    void push_back(T item) {
        //create a new node in memory with the item
        Node* newNode = new Node(item);
        if (!head){
            //check if the head is empty
            head = newNode;
            return;
        }
        //if the head is empty, iterate until there is a nullptr and set that as the new node
        Node* current = head;
        while(current->next){
            current = current -> next;
        }
        current->next = newNode;
    }

    void pop_back() {
        //if the list is empty return
        if (!head) return;

        //if the head is the only value in the list, delete it
        if (!head -> next) {
            delete head;
            head = nullptr;
            return;
        }
        //find the last node in the list and delete it
        Node* current = head;
        while (current->next->next){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    const T& front() const {
        //get the value of the head
        return head->value;

    }

    int size() const {
        //define a counter
        int count = 0;
        Node* current = head;

        //start from the head and iterate until you find the empty pointer
        while(current){
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while(head){
            //set the head as the next value and then delete the original head
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }

    }
};
