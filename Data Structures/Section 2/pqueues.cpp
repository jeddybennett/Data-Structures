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

#include <string>
using std::string;

#include <cstdlib>
using std::exit;
#include "input.h"

int main(int argc, char const* argv[]) {
    //define your priority queue and your map
    std::priority_queue<int> values;
    std::map<int, std::string> names;
    std::string x;

    //iterate until provided with empty input
    while(true){

        //prompt user for an operation
        cout << "What do you want to do? ";
        getline(cin,x);

        //if no operation is submitted, exit the program
        if(x.empty()){
            break;
        }

        //add operation
        else if(x == "add") {

            //prompt user for a name and priority
            std::string name;
            int priority;
            cout << "Name: ";
            getline(cin, name);
            cout << "Priority: ";
            cin >> priority;

            //add priority to your queue, and then name, int pair to your map
            values.push(priority);
            names[priority] = name;

            //ignore the empty whitespace
            cin.ignore(1);
        }
        //take operation
        else if(x == "take"){
            //check if the queue is empty
            if(values.empty()){
                cout << "There are no more people in line" << endl;
            }
            //if value is single digits, pad it with a leading zero, and display priority with the name
            else if(values.top() < 10){
                cout << std::setfill('0') << std::setw(2) << values.top() << " - " << names[values.top()] << endl;
                values.pop();

            }
            else{
                //display priority and the name associated with it
                cout << values.top() << " - " << names[values.top()] << endl;
                values.pop();
            }
        }
        //prompt user for a valid input
        else if(x != "add" && x != "take" && !x.empty()){
            cout << x << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
