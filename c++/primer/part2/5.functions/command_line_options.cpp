#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string; using::std::endl;

void exercise1(){

}

int main(int argc, char *argv[]){
    for (int i=0; i < argc; ++i)
        cout << argv[i] << endl;
}