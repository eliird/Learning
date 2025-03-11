#include<string>
#include<iostream>

using std::string;

struct Data{
    int ival;
    string s;
};

/*
Literal Class
- A class whose all data members have literal type
- Atleast one constexpr constructor
*/

class Debug {
    private:
        bool hw, io, other;
    public:
        constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    
        constexpr bool any() const {  // Make it constexpr
            return hw || io || other;
        }
    
        void set_io(bool b) { io = b; }
        void set_hw(bool b) { hw = b; }
        void set_other(bool b) { other = b; }
};

/*
Static Class Memeber
- members associated with class instead of object

Key practices:
 - we should not initialize the static members using class constructors
 - we should define static members outside class body
    in case below use initRate() to initialize it in main instead of it being defined directly in class or by constructor
 - notice interest rate is 
    */
class Account{
public:
    void calculate(){amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double);
private:
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::rate(double newRate){
    interestRate = newRate;
}

double Account::interestRate = Account::initRate();


int main(){
    // we can initailize above class using intiializer list
    Data val = {0, "Anna"};

    //code below would yield error as initializer list order should be same as the declaration order
    // Data val2 = {"Anna", 0};

    //using literal class
    constexpr Debug io_sub(false, true, false);
    if(io_sub.any()){
        std::cout << "somehting" << std::endl;
    }

    // using class static members
    
    // can be accessed using scope operators
    double r;
    r = Account::rate();

    // we can also access static members using objects
    Account ac1;
    Account *ac2 =&ac1;
    r= ac1.rate();
    r = ac2->rate();

}