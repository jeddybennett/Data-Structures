#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>

template<class T>
class Vector {
public:
    class Iterator {
    private:
        //declare an index to track the value in your array
        T* current;
    public:

        //declare the iterator variable item as current
        Iterator(T* item) : current(item) {}
        T& operator*() {

            //get value of current
            return *current;
        }

        Iterator& operator++() {
            //iterate current up one
            current++;

            //return the current value of current
            return *this;
        }

        bool operator==(const Iterator& other) const {
            //check if the iterator is equivalent to the passed in iterator object
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            //check if the iterator is not equivalent to the passed in iterator object
            return current != other.current;
        }
    };
    Iterator begin() {
        //get the iterator object of the first element of the array
        return Iterator(arr);
    }

    Iterator end() {
        //get the iterator object of the last element of the array
        return Iterator(arr + size_m);
    }

private:
    int capacity;
    T* arr;
    size_t size_m;

public:
    //define the parameters of the vector
    Vector() {
        arr = new T[1];
        capacity = 1;
        size_m = 0;
    }

    //define how to remove parameters from the vector
    ~Vector() {
        delete [] arr;
    }

    //insert at the end of the vector
    void push_back(T item) {
        if(size_m == capacity){
            resize();
        }

        arr[size_m] = item;
        size_m++;

    }

    //insert at a specified position and shift accordingly
    void insert(T item, int position) {

        //check if the position provided is valid
        if (position < 0 || position > size_m ){
            throw std::out_of_range("The index is out of range");
        }

        //resize if needed
        if(size_m == capacity){
            resize();
        }

        //shift everything to the right in the vector
        for(int i = size_m; i > position; i--){
            arr[i] = arr[i-1];
        }

        //add the new item to the vector
        arr[position] = item;


        //update the size of the vector
        size_m++;

    }

    void remove(int position) {
        //check if the position provided is valid
        if (position < 0 || position >= size_m ){
            throw std::out_of_range("The index is out of range");
        }

        //shift everything to the left
        for(int i = position; i < size_m - 1; i++)
        {
            arr[i] = arr[i+1];
        }
        //update the size of the vector
        size_m --;
    }

    T& operator[](int index) {
        //check if the index provided is out of range
        if (index < 0 || index >= size_m ){
            throw std::out_of_range("The index is out of range");
        }

        //return the array at the provided index
        return arr[index];
    }


    int size() const {
        //return the amount of elements in the vector
        return size_m;
    }

    void clear() {
        //delete the vector
        delete[] arr;

        //reset the capacity and size of the array
        capacity = 1;
        size_m = 0;
        arr = new T[capacity];
    }

private:
    void resize(){
        int new_capacity = (size_m == 0) ? 1 : capacity * 2;
        T* newArr = new T[new_capacity];

        for(int i = 0; i < size_m; i++){
            newArr[i] =  arr[i];
        }
        delete [] arr;
        arr = newArr;
        capacity = new_capacity;
    }
    // paste in your data members from the vector assignment
};
