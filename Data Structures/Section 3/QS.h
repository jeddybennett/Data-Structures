#pragma once

#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


template<class T>

int medianOfThree(std::vector<T>& array, int left, int right) {
    //find the middle value
    int middle = (left + right)/2;

    //swaps to make middle greater than left
    if(array[left]>array[middle]){
        std::swap(array[left],array[middle]);
    }
    //swaps to make right greater than left
    if(array[left]>array[right]){
        std::swap(array[left],array[right]);
    }
    //swaps to make middle less than right
    if(array[middle]>array[right]){
        std::swap(array[middle],array[right]);
    }
    //middle is not the median index
    return middle;

}


template<class T>
int partition(std::vector<T>& array, int left, int right) {
    //find the median index
    int mid = medianOfThree(array, left, right);

    //set your pivot value and then move it out of the way
    T pivot = array[mid];
    std::swap(array[left], array[mid]);

    //set and up and down value to increment
    int up = left + 1;
    int down = right;

    //while up is to the left of or equal to down
    while (up <= down) {
        //increment up until it's either greater than the right index
        // or it's greater than the pivot value
        while (up <= right && array[up] <= pivot) {
            up++;
        }
        //decrement down until it's either less than the left index
        // or it's less than or equal to the pivot value
        while (down >= left && array[down] > pivot) {
            down--;
        }
        //check if up is still left than down
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    }
    //make down the median index
    std::swap(array[left], array[down]);
    return down;
}

//build a recursive function
template<class T>
void sort_helper(std::vector<T>&array,int left, int right){
    //check if the left index is smaller than the right
    if (left<right){
        int pivot_help = partition(array, left, right);

        //get your partition index and
        // recurse to the right and left of the partition index
        sort_helper(array, left, pivot_help-1);
        sort_helper(array,pivot_help+1, right);
    }
}
template<class T>
void sort(std::vector<T>& array) {
    //start the sorting at the endpoints of the array
    sort_helper(array, 0, array.size()-1);

}


