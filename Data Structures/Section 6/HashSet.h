#pragma once
#include <unordered_set>
template<class T>
class HashSet {
private:
    std::unordered_set<T> set;

public:
    HashSet() {}

    ~HashSet() {}

    bool insert(T item) {
        // Returns a pair of an iterator pointing to the inserted element and bool stating if the item was inserted
        auto result = set.insert(item);

        return result.second;
    }

    bool remove(T item) {
        //returns if the element was removed or not
        return set.erase(item) > 0;
    }

    bool contains(T item) const {
        //checks if the item is contained in the set
        return set.find(item) != set.end();
    }

    void clear() {
        //Removes all elements from the set.
        set.clear();
    }

    int size() const {
        // Returns the number of elements in the set.
        return set.size();
    }
};