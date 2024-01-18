#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <set>

#include <vector>

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

int main(int argc, char const* argv[]) {
    // define your string, vector and set
    std::string line;
    std::vector<string> unique;
    std::set<string> words;
    //check if you have a filename
    if (argc == 2){
        //check if you can open the file
        ifstream input(argv[1]);
        if (!input.is_open())
        {
            std::cerr << "Unable to open file for reading: " << argv[1] << endl;
            exit(1);
        }
        //if the file can be opened
        else{
            //check for uniqueness in your vector to preserve insertion order
            while(getline(input, line)){
                if(words.find(line) == words.end()){
                    unique.push_back(line);
                    words.insert(line);
                }


            }
            //output each unique line of the input text in order
            for(std::string x: unique){
                cout << x << endl;
            }
        }
    }

    else{
        //define your string, vector and set
        std::string info;
        std::vector<string>done;
        std::set<string>stuff;

        //take from standard input and check for uniqueness
        while(std::getline(cin, info)){
            if(stuff.find(info) == stuff.end()){
                done.push_back(info);
                stuff.insert(info);
            }
        }
        //output the unique lines from stdin
        for(std::string y: done){
            cout << y << endl;
        }
    }


    return 0;
}
