# Basics

## Bare minimum C++ program

```c++
int main(){
    return 0;
}
```
The above is the hello world of c++. How to convert the code to a file that can be executable. You need a compiler for that. like g++.

### Installing g++
running the command below should install the g++ compiler along with some other stuff.

```bash
sudo apt install build-essential

# confirm the install with

g++ --version # should execute and show version of g++
```

### compiling a c++ program

Compiling C++ program is complicated kinda and people use package mangers for building programs but for a simple program like the one above we can use the g++ compiler directly.

Assuming we write the bare minimum code in the main.cpp file, we can compile it using the following

```bash
g++ main.cpp -o main
```

Running the above command should generate a binary with the name  main in the folder. You can execute the binary using 
```bash
./main
```

## Input/Output in C++