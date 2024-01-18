#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <vector>
std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}
using namespace std;

int main(int argc, char const* argv[]) {
    // define your necessary user input variables
    string operation;
    int operand_1, operand_2;

    //create a vector of all possible operations for your calculator
    vector<string> li;
    li.push_back("add");
    li.push_back("subtract");
    li.push_back("multiply");
    li.push_back("divide");
    li.push_back("mod");

    //ask for input until a valid operation is given or empty operation is given
    while (true){

        //get user input with all whitespace to check for an empty input
        cout << "operation: ";
        getline(cin, operation);

        //check all possible scenarios for an invalid operation
        if (operation != li[0] && operation != li[1] && operation != li[2] && operation != li[3] && operation != li[4] && !operation.empty()){
            cout << static_cast <string> (operation) + " isn't a valid operation\n" ;
            continue;
        }
        //break and terminate program if empty input is given
        else if (operation.empty()){
            break;
        }

        //prompt user for 2 integers for the provided operation
        else
        cout << "left operand: ";
        cin >> operand_1;

        cout << "right operand: ";
        cin >> operand_2;

        //perform addition
        if (operation == li[0]){
            cout << operand_1 + operand_2 << '\n';
            cin.ignore(1);
        }
        //perform subtraction
        else if (operation == li[1]){
            cout << operand_1 - operand_2 << '\n';
            cin.ignore(1);
        }
        //perform multiplication
        else if (operation == li[2]){
            cout << operand_1 * operand_2 << '\n';
            cin.ignore(1);
        }
        //perform division
        else if (operation == li[3]){
            cout << operand_1 / operand_2 << '\n';
            cin.ignore(1);
        }
        //perform modular division
        else if (operation == li[4]){
            cout << operand_1 % operand_2 << '\n';
            cin.ignore(1);
        }
    }

    return 0;
}
