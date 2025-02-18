#include <iostream>

std::string global_str;
int global_int;

template<typename T>
void print(const std::string name, const T& var){
    std::cout << name  << ": " << var << std::endl;

}

int main()
{
    int local_int;
    std::string local_str;
    print("global str", global_str);
    print("local_str", local_str);

    print("global_int", global_int);
    print("local_int", local_int);


    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
    
}