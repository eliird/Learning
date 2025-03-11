// #include "../../part2/6.classes/sales_data.cpp"
#include <fstream>
#include <string>
#include <iostream>


using std::string;

void excercise1(const string &file1, const string &file2){
    /*
    code to copy contents of a file from another file
    */
   
    std::ifstream input(file1, std::ios::in);
    std::ofstream output(file2, std::ios::out);

    string s;
    while(std::getline(input,s))
        output << s << std::endl;

}


int main(int argn, char *argv[]){

    string file1 =  argv[1];
    string file2 = argv[2];

    excercise1(file1, file2);
}