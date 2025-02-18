#include <iostream>

template<typename T>
void print(const T& var) {
    std::cout << "Value: " << var << ", Type: " << typeid(var).name() << std::endl;
}

int main(){
    auto x = 'a';
    print(x);

    auto y = L'a';
    print(y);

    auto a = "a";
    print(a);

    auto b = L"a";
    print(b);

    auto c = 10;
    print(c);

    auto d= 10u;
    print(d);
    
    auto e = 10L;
    print(e);

    auto f=10uL;
    print(f);

    auto g = 012;
    print(g);

    auto h = 0xC;
    print(h);

    auto j = "Who goes with F\145rgus?\012";
    print(j);

}