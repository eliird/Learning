## IOSTREAM

C++ includes a standard library(STL) for input output. Most common io item in the STL us iostream. They are two types of stream
- istream : input stream
- ostream : output stream

A stream is a sequence of characters read or written to an IO device sequentially overtime.

### Standard IO objects

STL has 4 IO objects.
- cin of type istream (standard input)
- cout of type ostream (standard output)
- cerr of type ostream(standard error)
- clog of type ostream (standard log)

## A basic program with IO library

```c++
#include <iostream>
int main(){
    std::cout <<"Enter two numbers" << std::endl;
    int v1=0, v2=0;

    std::cin >> v1 >> v2;
    std::cout << "The sum is " << v1 + v2 << std::endl;
    return 0;
}
```
The above program is the example of a simple code that writes to the screen using standard output then reads text from the terminal and performs operation on it and writes it to terminal again.

Compiling the code using the commands below should yield the following output

```bash
# compile the program
g++ main.cpp -o main

# execute the program
./main

# output
Enter two numbers
1
2
The sum of 1 and 2 is 3
```
