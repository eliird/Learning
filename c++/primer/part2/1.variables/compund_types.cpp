#include <iostream>

void exercise1(){
    /*
    write a code to change the value of a pointer. write code to change the value to which pointer points 
    */
   int i =0, j=1;
   int *ip, *jp;
   ip = &i;
   *ip = 2;
}

void exercise2(){
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    /*
    what does the above program do?
    Answer: calculates square of 42
    */ 
   std::cout << *p1 << std::endl;

}

void exercise3(){
    int i = 0;
    // double* dp = &i;
    // int *ip = i; 
    // int *p = &i;

    //select the legal statement of the 3 above
    int *p = &i;
}

int main(){

    int i = 0, &r1 = i; double d = 0, &r2 = d;
    r2 = 3.1415;
    r1 = r2;
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    i = 1;
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;

    int ir, &ri = ir;
    ir = 5; ri = 10;
    std::cout << ir << " " << ri << std::endl;

    exercise2();
}
