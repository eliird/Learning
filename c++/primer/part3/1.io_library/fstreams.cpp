// #include "../../part2/6.classes/sales_data.cpp"
#include <fstream>
#include <string>
#include <iostream>


using std::string;

void excercise1(const string &file1, const string &file2){
    /*
    code to copy contents of a file from another file
    reads the text from file and writes to file2 (paths)
    */
   
    std::ifstream input(file1, std::ios::in);
    if(!input)
        std::cerr << "unable to open the readfile, make sure it exists" << std::endl;
    
    std::ofstream output(file2, std::ios::out);
    if(!output)
        std::cerr << "unable to open the write file, make sure it exists" << std::endl;

    string s;
    while(std::getline(input,s))
        output << s << std::endl;

    input.close();
    output.close()
}


int main(int argn, char *argv[]){

    string file1 =  argv[1];
    string file2 = argv[2];

    excercise1(file1, file2);
}