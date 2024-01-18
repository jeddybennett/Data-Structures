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
    // First input is the input file, second command line argument is the output file
    ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        exit(1);
    }

    ofstream outfile(argv[2]);
    if (!infile.is_open())
    {
        cerr << "Unable to open file for writing: " << argv[2] << endl;
        exit(2);
    }
    //read through each line of the file
    std::string line;
    while (getline(infile, line))
    {
        std::stringstream line_stream(line);
        std::string word;
        std::vector<string> names;
        std::vector<double> numbers;
        double val = 1;
        bool my_bool;
        //iterate through each word of the selected line
        while(line_stream >> word)
        {
            try
            {
                //check if you can convert that string to a double
                std::stod(word);
                my_bool = true;
            }
            catch (...)
            {
                my_bool = false;
            }
            //if you can convert the string to a double, multiply by it by val
            if (my_bool)
            {
                double num = stod(word);
                val *= num;
            }
            //otherwise add it to the vector names
            else {
                names.push_back(word);
            }
        }
        //output the reformatted line
        outfile << names[1] << ", " << names[0] << ": " << val << endl;
    }
    //close the file
    infile.close();
    outfile.close();
    //return 0;
}
