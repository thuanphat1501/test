#ifndef DISH_H
#define DISH_H

#include <string>
using namespace std;
class Dish
{
private:
    int id;
    string name;
    int price;

public:
    Dish(string name, int price) : name(name), price(price)
    {
        static int ID = 24001;
        id = ID;
        ID++;
    }

    int getID();
    void setPrice(int newPrice);
    int getPrice();
    string getName();
};

#endif // DISH_H
