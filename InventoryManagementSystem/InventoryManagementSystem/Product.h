#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;
    string type;

public:
    Product()
    {
        id = 1;
        name = '\0';
        price = 0;
        quantity = 0;
        type = '\0';
    }
    Product(int id, string name, double price, int quantity, string type)
        : id(id), name(name), price(price), quantity(quantity), type(type)
    {
    }

    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    double getPrice() const
    {
        return price;
    }
    int getQuantity() const
    {
        return quantity;
    }
    string getType() const
    {
        return type;
    }

    void setId(int id) 
    { 
        this->id = id; 
    }
    void setName(const string& name)
    { 
        this->name = name;
    }
    void setPrice(double price)
    { 
        this->price = price; 
    }
    void setQuantity(int quantity) 
    { 
        this->quantity = quantity; 
    }
    void setType(const string& type)
    { 
        this->type = type;
    }
};
#endif