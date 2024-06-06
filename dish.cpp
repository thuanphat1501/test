#include"dish.hpp"
#include<string>

int Dish::getID() { return id; }

void Dish::setPrice(int newPrice) { price = newPrice; }
int Dish::getPrice() { return price; }
string Dish::getName() { return name; }