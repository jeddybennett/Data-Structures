#include <iostream>
using std::cout, std::cerr, std::endl;

#include <string>
using std::ifstream, std::ofstream;

#include <fstream>
using std::string, std::getline;

#include <sstream>
using std::stringstream;

#include <vector>
using namespace std;


void sort(std::string& a, std::string& b, std::string& c) {
    //define your vector and push your strings to the vector
    std::vector<std::string> strings;
    std::string temp;
    strings.push_back(a);
    strings.push_back(b);
    strings.push_back(c);
    //iterate through each element of the vector
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            //check if the previous string is greater than the following and reorder accordingly
            if(strings[i] > strings[j]){
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
    //define your new strings
    a = strings[0];
    b= strings[1];
    c = strings[2];

}

int main(int argc, char const* argv[]) {
    //check if you have only 3 command line arguments
    if (argc != 4) {
        std::cerr << "3 command line arguments needed" << std::endl;
        exit(1);
    }
    //set a string for each command line argument
    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    //call your void function to sort the 3 strings in ascending order
    sort(a, b, c);

    //output the 3 strings
    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
