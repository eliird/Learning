#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

template <typename T>
void print_vector(const vector<T> &a){
    for (auto elem: a)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void exercise1(){
    //ways to intialize a vector
    vector<int> ivec; //initalize empty vector of ints
    vector<int> ivec2 = ivec; //copy elements of ivec into ivec2
    vector<int> vec_cpy(ivec2); //same as above
    //vector<string> svec(ivec2); //error as int and string mismatch

    //list initialization
    vector<string> articles = {"a", "an", "the"};
    vector<string> articles2 {"a", "an", "the"}; // list initialization
    // vector<string> articles("a", "an", "the"); // error

    vector<int> ivec3(10, -1); //initializes vector with 10 elements intialized to -1
    vector<string> svec2(10, "hi!"); 
    // if we only specify the num of elements and not default value defailt value is automatically used

    vector<int> ivec4(10); //initialize all ints to 0

}

void excersice2(){
    //initialization a vector using loop.
    vector<int> v1;
    for (int i=0; i < 100; i++)
        v1.push_back(i);
    print_vector(v1);
}

void excercise3(){
    // initialize vector of word from input steream

    string word;
    vector<string> text;
    while (std::cin >> word){
        text.push_back(word);
    }
    print_vector(text);
}

void excercise4(){
    /*
    cluster the grades from 0 to 100 in ranges of 10
    42 65 95 100 39 67 95 76 88 76 83 92 76 93 -> 0 0 0 1 1 0 2 3 2 4 1
    */

    int val = 0;
    vector<int> clusters(11, 0);
    while(std::cin >> val)
        if (val <= 100)
            ++clusters[val/10];
    print_vector(clusters);
}

void excercise5(){
    /*
    iterattors
    vector<int> v;
    auto start = v.begin(), end=v.end()

    some key functions related to iterators
    - *iter returns reference to element denoted by iterator
    - iter->mem dereferences iters and fetches the memeber named mem from underlying element. equal to (*iter.mem)
    - ++iter increment iter to move to next value
    - --iter decrement iter to go to previous value
    - iter1 == iter2 compares two iters for equality. equal if they denote the same element
    - use vec.cbegin() or cend() iterators to explicitly get constant types, default is constant if object is constant
    */

    string s("some string s");
    if (s.begin() != s.end()){ // this checks if the string is not empty
        auto it = s.begin();
        *it = toupper(*it); // turn first char to upper
    }
    std::cout << s << std::endl;

    // looping using iterators
    for(auto it=s.begin(); it != s.end() && !isspace(*it); it++)
        *it = toupper(*it);
    
    std::cout << s << std::endl;
    
}


void excercise6(){
    /*
    binary search using iterators
    */
   string text = "abcdefghi"; // sorted text
   char sought = 'c';

   auto beg = text.begin(), end = text.end();
   
   // You always need to offset iterator by subtracting the range instead of adding and dividing by 2
   auto mid = beg + (end - beg) / 2; 

   while(mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        
        mid = beg + (end - beg) /2;
   }

   std::cout << *mid << std::endl;

}
int main(){
    /*
    Some usefule vector operations
    v.empty() returns true if v is empty
    v.size() return the number of elements in v
    v.push_back() adds element at end of v
    v[n] returns nth element
    v1 = v2 replaces elements in v1 with copy of elements in v2
    v1 = {a, b, c} replaces the elements in v1 with provided list
    v1 == v2 returns true if v1.size == v2.size() and each element is equal
    
    Do not use subscripting to add elements
    vector<int> ivec; // empty vector
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec[ix] = ix; // disaster: ivec has no elements
    */
    vector<string> v7{10, "hi"};
    print_vector(v7);

    vector<int> v8{10, 42};
    print_vector(v8);

    // excersice2();
    excercise6();
}