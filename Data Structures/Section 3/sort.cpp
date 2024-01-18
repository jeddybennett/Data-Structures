#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <iomanip>

#include <map>

#include <queue>
using std::priority_queue;

#include <set>

#include <vector>

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <stdio.h>
#include <string.h>

#include <cstdlib>
using std::exit;

#include <vector>

void insertionSort (string arr[], int n)
{
    int i;
    //loop through each element of your array
    for (i = 1; i < n; i++){
        //set the key as your second element
        string key1 = arr[i];
        int j = i;

        //while your first element is, sort until you find an element greater than the first
        while(j>=0 && arr[j - 1] > key1)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        //reset your array and iterate
        arr[j] = key1;
        j--;
    }

};
int main(int argc, char const* argv[]) {
    std::string line;
    std::vector<string> words;
    if (argc == 2) {
        //check if you can open the file
        ifstream input(argv[1]);

        if (!input.is_open()) {
            std::cerr << "Unable to open file for reading: " << argv[1] << endl;
            exit(1);

        }
        else {
            //if you can open the file, add each line to a vector
            while (getline(input, line)) {
                words.push_back(line);
            }

            string array[words.size()];
            //set an array that is equivalent to your vector of strings
            for (int i = 0; i<words.size();i++){
                array[i] = words[i];
            }

            //sort your array
            insertionSort(array, words.size());

            //output the sorted array
            for (int i = 0; i<words.size();i++){
                cout << array[i] << endl;
            }
        }
    }
    else{
        std::string info;

        //get input from standard input
        while (std::getline(cin, info)) {
            words.push_back(info);
        }

        //create a new array of the size of your vector of strings
        string array[words.size()];
        for (int i = 0; i<words.size();i++){
            array[i] = words[i];
        }

        //sort your array of strings and output the sorted list
        insertionSort(array, words.size());
        for (int i = 0; i<words.size();i++){
            cout << array[i] << endl;
        }

    }

    return 0;
}