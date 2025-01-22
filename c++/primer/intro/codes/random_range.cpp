#include <random>
#include <iostream>
#include <math.h>

int main(){
    int a = 0, b=0;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;

    int start = std::min(a, b);
    int end  = std::max(a, b);

    int random_number = rand() % (end - start + 1) + start;
    std::cout << "random number between " << start << " and " << end << " is " << rand() % start + end << std::endl;

}