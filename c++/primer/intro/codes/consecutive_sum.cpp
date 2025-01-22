#include <iostream>


int main(){
    int start = 50;
    int end = 100;
    int sum = 0;
    int count = start;

    while (count <= end){
        sum += count;
        count++;    
    }

    std::cout << "The sum of numbers from " << start << " to " << end << " is " << sum << std::endl;
}