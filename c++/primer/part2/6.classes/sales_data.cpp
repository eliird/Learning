#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string; using::std::endl;

class Sales_data{
/*
friend memebers which have access to private vairables of classes
*/
friend std::istream &read(std::istream &, Sales_data&);
friend std::ostream &print(std:: ostream &os, const Sales_data& item);

private:
    string isbn = "";
    unsigned units_sold = 0;
    double revenue;
        

public:
    // constructors
    Sales_data()=default;
    Sales_data(const std::string &s): isbn(s){ } // part after : is constructor initializer list
    Sales_data(const std::string &s, unsigned n, double p): 
        isbn(s), units_sold(n), revenue(p * n)
    { }
    Sales_data(std::istream &);

    /*
    defualt copy constructor works by assigning all members 
    e.g total = trans; would equate to
    total.isbn = trans.isbn;
    total.units_sold = trans.units_sold;
    total.revenue = trans.revenue;
    We can define copy constructo as follows
    */
   Sales_data(const Sales_data& data){
    /*
    this will work same as original constructor but you can change anything
    */
    this->isbn = data.isbn;
    this->units_sold = data.units_sold;
    this->revenue = data.revenue;
   }

    //destructors
    ~Sales_data(){}

    string get_isbn() const { return this->isbn;}
    void set_isbn(const string& isbn){ this->isbn = isbn; }

    unsigned get_units_sold() const { return this->units_sold;}
    void set_units_sold(int units, double price){
        this->units_sold = units;
        this->revenue = units * price;
    }

    int get_revenue() const { return this-> revenue;}
    double avg_price() const;

    Sales_data& combine(const Sales_data&data2);

    Sales_data add(const Sales_data& d1, const Sales_data& d2){
        Sales_data sum = d1;
        sum.combine(d2);
        return sum;
    } 

};

double Sales_data::avg_price() const{
    if(this->units_sold)
        return this->revenue/this->units_sold;
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data&data2){
    this->units_sold += data2.units_sold;
    this->revenue += data2.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item){
    // Becuase we decalered it as a friend function we can access private members without need of calling functions
    double price = 0;
    // string isbn;
    // int units_sold;
    is >> item.isbn >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    // item.set_isbn(isbn);
    // item.set_units_sold(units_sold, price);
    return is;
}

std::ostream &print(std:: ostream &os, const Sales_data& item){
    // os << item.get_isbn() << " " << item.get_units_sold() << " " 
    // << item.get_revenue() << " " << item.avg_price();

    // Becuase we decalered it as a friend function we can access private members without need of calling functions
    os << item.isbn << " " << item.units_sold << " " 
    << item.revenue << " " << item.avg_price();
    return os;
}

//constructor outside of class
Sales_data::Sales_data(std::istream &is){
    read(is, *this);
}

int main(){


    Sales_data total;

    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans))
            if(total.get_isbn() == trans.get_isbn())    
                total.combine(trans);
            else{
                print(cout, total) << endl;
                total = trans;
            }
    }else{
        std::cerr << "No Data?!" << endl;
    }

}