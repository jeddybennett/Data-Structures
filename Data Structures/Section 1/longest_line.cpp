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

int main(int argc, char const* argv[]) {
    // read in the infile and check if it can be read
    ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        exit(1);
    }
    //define words and line variables to be used when reading the file
    std::string line;
    std::string words;
    int val = 0;
    //get each line of the file
    while(getline(infile, line))
    {
        std::stringstream line_stream(line);
        std::string one_word;
        int num = 0;
        //read through each line and count the words
        while(line_stream >> one_word)
        {
            num += 1;
        }
        //check if that line had the largest value
        if (num > val)
        {
            val = num;
            words = line;
        }

    };
    if (!words.empty() && words.back() == '\r')
    {
        words.pop_back();
    }
    //return the longest line
    cout << words << endl;
    return 0;
}
