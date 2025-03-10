#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using::std::endl;

void exercise1(){
    /*
    Guess the output of each of the line below.
    */
    std::vector<int> vec{5, 4, 3, 2, 1, 0};
    cout << *vec.begin() << endl;

    cout << *vec.begin() + 1 << endl;

    cout << *(vec.begin() + 1) << endl;

    cout << (*vec.begin()) + 1 << endl;
}

void excercise2(){
    int i = 0;
    cout << i << " " << ++i << endl; // undefined because << gives no gurantees whether ++i will be executed before or after.

}
int main(){
    exercise1();

    unsigned char bits = 0233;
    cout << (int)bits << endl;

    bits = bits << 1;
    cout << (int)bits << endl;

}