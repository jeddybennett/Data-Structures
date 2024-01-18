#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
    //set your command line arguments as integer inputs
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    //check if your starting value is less than your end value
    if (start < end){

        //from start, increment up to end and print all numbers that are divisible by divisor
        for (int i = start; i<= end; i++){
            if (i % divisor == 0){
                std::cout << i << '\n';
            }
        }
    }
    //check if your starting value is greater than your end value
    else if (start >= end){

        //from start, increment down to end and print all numbers that are divisible by divisor
        for (int i = start; i>=end; i--){
            if (i % divisor == 0){
                std::cout << i << '\n';
            }
        }
    }

    return 0;
}
