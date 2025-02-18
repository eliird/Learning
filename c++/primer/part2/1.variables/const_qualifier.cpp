#include <iostream>

void exercise1(){
    int i2 = 0;
    int *const p2 = &i2;
    std::cout << *p2 << std::endl;
    *p2 = 2;
    std::cout << *p2 << std::endl;

    int i3 = 1;

    const int *p3 = &i3;

    // *p3 = 5; // error because cannot modify the value that is being pointed to 


    // p2 = &i3; // errosrs out because the pointer must point to same memory address
}


int main(){
    const int buffer = 512;

    exercise1();

    // buffer = 100;  // error
    // okay to initialize constants at runtime
    //const int buffer = get_size()

    // by default const objects are local to a file
}