#pragma once

#include <iostream>
#include <string>
#include<string>
#include<stdexcept>

template<class T>
class DLList {
public:
    struct Node {
        //define your prev, next in memory, and your value
        Node* prev;
        Node* next;
        T value;

        //constructor of a node
        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    //doubly linked list constructor
    DLList(): size_m(0), m_head(nullptr), m_tail(nullptr){}

    ~DLList() {}

    const Node* get_head() const {
        //return the head
        return m_head;
    }

    void push_front(T item) {
        //define a node in memory
        Node * ptr = new Node(item);

        //check if the head is none
        if (!m_head){
            m_head = m_tail = ptr;
        }
        //otherwise insert the node at the beginning of list
        else{
            ptr->next = m_head;
            m_head->prev = ptr;
            m_head = ptr;
        }
        size_m++;
    }
    void push_back(T item) {
        //create a new node in memory
        Node* newNode = new Node(item);

        //check if the list is empty
        if (!m_head){
            m_head = m_tail = newNode;
        }

        //if not, insert the item at the tail position
        else{
            m_tail->next= newNode;
            newNode->prev = m_tail;
            m_tail = newNode;
        }
        size_m++;
    }

    void insert(T item, int position) {
        //check if the position provided is valid
        if (position < 0 || position > size_m ){
            throw std::out_of_range("The index is out of range");
        }

        //if it is, create a new node in memory
        Node* newNode = new Node(item);

        //check if node is to be inserted as the head
        if (position == 0){
            newNode->next = m_head;
            newNode->prev = nullptr;
            if(m_head){
                m_head->prev = newNode;
            }
            m_head = newNode;
            if(!m_tail){
                m_tail = newNode;
            }
        }

        //check if node should be inserted at the tail
        else if (position == size_m){
            newNode->next = nullptr;
            newNode->prev = m_tail;
            if (m_tail){
                m_tail->next = newNode;
            }
            m_tail = newNode;
        }

        //iterate through list to find the correct position
        else{
            Node * currentNode = m_head;
            for (int i = 0; i < position; i++){
                currentNode = currentNode ->next;
            }

            //allocate memory for the node in the list to avoid memory leaks
            newNode->next = currentNode;
            newNode->prev = currentNode->prev;
            currentNode->prev->next = newNode;
            currentNode->prev = newNode;
        }
        //update the size of the list
        size_m++;

    }

    void pop_front() {
        //check if the list is empty
        if (size_m == 0){
            throw std::length_error("List is Empty");
        }
        //if not, check if there's more than one element in the list
        else if (size_m == 1){
            delete m_head;
            m_head = m_tail = nullptr;
        }
        //if so, delete the head
        else{
            Node* newHead = m_head->next;
            delete m_head;
            m_head = newHead;
            m_head->prev = nullptr;
        }
        size_m--;
    }
    void pop_back() {
        //check if the list is empty
        if (size_m == 0){
            throw std::length_error("List is Empty");
        }

        //check if there's only one element in the list to remove
        if (size_m == 1){
            delete m_head;
            m_head = m_tail = nullptr;
        }

        //remove the tail from the existing list
        else{
            Node* prevTail = m_tail ->prev;
            delete m_tail;
            m_tail = prevTail;
            m_tail->next = nullptr;
        }
        size_m--;
    }

    void remove(int position) {
        //check if the position provided is valid
        if (position < 0 || position >= size_m){
            throw std::out_of_range("The index is out of range");
        }
        //check if the head is to be removed
        if (position == 0){
            pop_front();
        }

        //check if the tail is to be removed
        else if (position == size_m - 1){
            pop_back();
        }
        else{
            //iterate through your list until you find the correct node
            Node * currentNode = m_head;
            for (int i = 0; i < position; i++){
                currentNode = currentNode ->next;
            }
            //remove the allocation of memory for the selected node in the list and delete it
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            delete currentNode;

            //update the size of the list
            size_m--;
        }
    }

    const T& front() const {
        //check if the list is empty
        if (!m_head){
            throw std::length_error("List is Empty");
        }
        //return the head
        return m_head->value;
    }
    const T& back() const {
        //check if the list is empty
        if (!m_tail){
            throw std::length_error("List is Empty");
        }

        //return the tail
        return m_tail->value;
    }
    const T& at(int index) const {
        //check if the index provided is valid
        if (index < 0 || index >= size_m){
            throw std::out_of_range("The index is out of range");
        }
        //start at the head and iterate up to the index node
        Node* currentNode = m_head;
        for(int i = 0; i < index; i++){
            currentNode = currentNode->next;
        }
        //return the value of that node
        return currentNode->value;
    }

    bool contains(const T& item) const {
        //start at the head and iterate until the item is found
        Node * currentNode = m_head;
        while(currentNode){
            if(currentNode -> value == item){
                return true;
            }

            //update the current node from its position in the list
            currentNode = currentNode ->next;
        }
        //if the item is not found, return false
        return false;
    }

    int size() const {
        //return the size of the list
        return size_m;
    }

    void clear() {
        //iterate until m_head is nullptr
        while(m_head){

            //set the head as the next value and then delete the original head
            Node* toDelete = m_head;
            m_head = m_head->next;
            delete toDelete;
        }

        //set the size of the list to 0
        size_m = 0;
    }

private:
    //initialize your head, tail and list size
    Node * m_head;
    Node * m_tail;
    size_t size_m;


};
