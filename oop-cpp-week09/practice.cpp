#include <iostream>
#include <string>
using namespace std;

struct nhaHang {
    string name;
    string address;
    string phone;
    Food foods[100];
    int foodCount = 0;
    Order orders[100];
    int orderCount = 0;

};

struct Food {
    string id;
    string name;
    double price;
    int quality;
};

struct Order {
    string id;
    string customerName;
    string address;
    int foods[100];
    int foodCount = 0;
    int quality;
    string status;
};
int main()
{

}