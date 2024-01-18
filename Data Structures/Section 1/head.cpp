#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;


int main(int argc, char const* argv[]) {
    //Check if there are 3 command line arguments
    if (argc == 3)
    {
        //check if the file is open
        std::string line;
        ifstream input(argv[2]);

        //check if you can open the file
        if (input.is_open()){
            int num = abs(std::stoi(argv[1]));
            //Print out the entire file our as many lines as specified
            for(int i = 0; i < num && getline(input, line); i++){
                std::cout << line << std::endl;
            }
        }
        //Raise an error that the file cannot be opened
        else{
            std::cerr << "ERROR: can't open " << argv[2] << std::endl;
            exit(1);
        }

    }

    //check if there is only one command line argument
    else if (argc == 2){

        //check if you can convert the argument to an integer
        int val = 0;
        bool valid_conversion;

        try {
            valid_conversion = true;
            val = abs(std::stoi(argv[1]));
        }

        catch(const std::invalid_argument&)
        {
            valid_conversion = false;
        }
        //if you can convert, print out standard input the amount of times specified
        if(valid_conversion)
        {
            std::string word;
            for(int i = 0; i < val && std::cin >> word; i++) {
                std::cout << word << endl;
            }

            }
        //if you can't convert, open the file, and print out up to 10 lines
        else{
            ifstream infile(argv[1]);
            if (infile.is_open()) {
                std::string lines;
                int i = 0;
                while (getline(infile, lines) && i < 10) {
                    std::cout << lines << endl;
                    i++;
                }
            }
            //if the file can't be opened, throw an error
            else {
                std::cerr << "ERROR: can't open " << argv[1] << endl;
                exit(2);
            }
        }
    }
    //if no command line argument is provided, print out 10 lines of standard input
    else if (argc == 1){
        std::string words;
        for(int i = 0; i < 10 && std::cin >> words; i++) {
            std::cout << words << endl;
        }
    }

    return 0;
    }


