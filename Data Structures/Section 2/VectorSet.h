#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <set>

#include <algorithm>

#include <vector>

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;


template<class T>
class VectorSet {
private:
    std::vector<T>hello;

public:
    bool contains(T item) const {
        //check if the item is in the list
        return std::find(hello.begin(), hello.end(), item) != hello.end();
    }

    bool insert(T item) {
        //if the vector already contains the item, return false
        if (contains(item)){
            return false;
        }
        else{
            //otherwise insert the item into the vector
            hello.push_back(item);
            return true;
        }
    }

    bool remove(T item) {
        //check if the item is in the list, and then remove it
        if (contains(item)){
            auto index = std::find(hello.begin(), hello.end(), item);
            hello.erase(index);
            return true;
        }
        //if the item is not in the list, return false
        else{
            return false;
        }
    }

    int size() const {
        // return the number of items in the set
        return hello.size();

    }

    bool empty() const {
        // return true if the set is empty and return false otherwise
        return hello.empty();

    }

    void clear() {
        // remove all items from the set
        hello.clear();
    }
};
