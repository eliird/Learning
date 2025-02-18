#include <iostream>
#include "sales_data.h"


int main(){
    double price;
    Sales_data data1, data2;

    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    std::cout << "Data 1:\nunits_sold: "<< data1.units_sold << "\nrevenue: " << data1.revenue << std::endl;
    std::cout << "Data 2:\nunits_sold: "<< data2.units_sold << "\nrevenue: " << data2.revenue << std::endl;

    if (data1.bookNo == data2.bookNo){
        unsigned totalCount = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " "; 
        
        if (totalCount != 0)
            std::cout << totalRevenue/totalCount << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}