#include <iostream>

int main(){
    unsigned u1 = 10, u2=40;
    std::cout << "u2 - u1 is : " << u2 - u1 << std::endl;
    std::cout << "u1 - u2 is : " << u1 - u2 << std::endl;

    int i1 = 10, i2 = 42;
    std:: cout << i2  - i1 << std::endl;
    std:: cout << i1  - i2 << std::endl;
    std:: cout << i1  - u1 << std::endl;
    std:: cout << u1  - i1 << std::endl;

}