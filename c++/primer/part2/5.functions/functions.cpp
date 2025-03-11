#include <iostream>
#include <string>

#define IS_TRUE(a, b) if (a != b) cout << "test failed: " << endl

using std::cin; using std::cout; using std::string; using::std::endl;

int exercise1_factorial(int num){
    /*
    Basics
    change this function so it takes a number and returns factorial of that number
    */
   if (num == 0) return 1;
   int prod = 1;
   for(int i=1; i <= num; ++i){
        prod *= i;
   }
   return prod;
}

size_t excercise2_static(){
    /*
     ctr is initialized when it is called the first time and then it retains the value.
     using this function in a loop would return the number of times loop was executed
     */
    static size_t ctr = 0;
    return ++ctr;
}

void swap_using_pointers(int *a, int *b){
    /*
    write code to swap two integers using pointers
    */
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void params_by_reference(int &i){
    // changes the value of the i in the original place from where it was called
    // this is used to avoid copies especially when passing strings or vectors or large sized objects
    i = 0;
}

bool isShorter(const string &s1, const string &s2){
    // s1 and s2 are not copied
    return s1.size() < s2.size();
}


string::size_type find_char(const string &s, char c, string::size_type &occurs){
    //reference parameters can be used to return some information
    // num of occurances are returned using a reference parameter
    auto ret = s.size();
    occurs = 0;

    for(decltype(ret) i=0; i != s.size(); ++i){
        if(s[i] == c){
            if (ret == s.size())
                ret = i; // remember the first occurance of c to return
            ++occurs;
        }
    }
    return ret;
}

bool is_sentece(const string &s){
    string::size_type ctr;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

void passing_array(const int []){
    /*
    array is always passed by reference
    - const int *
    - const int[]
    - const int[10] 
    Above 3 all are same, the range is ignored in the last one as only pointer gets passed.
    Best is to use the 2nd one to show intent of using pointer as an array
    */
}

void print_array(const int *beg, const int *end){
    while(beg != end)
        cout << *beg++ << endl;
}


void function_with_variable_parasm(std::initializer_list<string> il){
    
    /*
    you can also use c-style ... but is not recommneded 
    */
    for(auto beg = il.begin(); beg!= il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main(){
    IS_TRUE(exercise1_factorial(5), 120);
    std::cout << " factorial of 5 is " << exercise1_factorial(5) << endl;
    std::cout << " factorial of 10 is " << exercise1_factorial(10) << endl;

    int ctr;
    for(int i=0; i < 5; i++){
        ctr = excercise2_static();
        cout << "value of \"ctr\" after " << i << " calls is " << ctr <<endl; 
    }

    int a=2, b=3;
    cout << "a: " << a << ", b: " << b <<endl;
    swap_using_pointers(&a, &b);
    cout << " after swapping: " <<endl;
    cout << "a: " << a << ", b: " << b <<endl;


    const int sz = 10;
    int arr[sz] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    print_array(arr, arr + sz);

    function_with_variable_parasm({"abc", "def", "ghi"});

}
