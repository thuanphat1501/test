#include"employer.hpp"
#include"table.hpp"
#include"manager.hpp"
#include"dish.hpp"
#include <vector>
#include <string>
#include<iostream>

void Employer::updateTableList(list<Dish> menu, int number)
{
    list_table.clear(); // Xóa danh sách bàn hiện tại
    for (int i = 1; i <= number; ++i)
    {
        Table table(i, true, menu);
        list_table.push_back(table); // Thêm bàn mới vào danh sách
    }
}
// Trong lớp Employer
Table Employer::getTable(int id)
{
    for (const Table& table : list_table)
    {
        if (table.getID() == id)
        {
            cout << "Table is found\n";
            return table;
        }
    }
    cout << "Table not found\n"; 
}


void Employer::displaySelectedTable(int num)
{
    cout << "Selected table: ";
    for (int i = 1; i <= num; ++i)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Table Status: \t";
    for (int i = 1; i <= num; ++i)
    {
        cout << "O ";
    }
    cout << endl;
    cout << "X: is not available\n";
    cout << "O: is available\n";
}
void Employer::order(list<Dish> menu) {
    cout << "Menu:" << endl;
    for (const auto& dish : menu) {
        cout << "ID: " << dish.getID() << " - " << dish.getName() << " ($" << dish.getPrice() << ")" << endl;
    }

    int dishID;
    cout << "Enter the dish ID: ";
    cin >> dishID;

    // Tìm món ăn trong danh sách
    Dish orderedDish;
    for (const auto& dish : menu) {
        if (dish.getID() == dishID) {
            orderedDish = dish;
            break;
        }
    }

    if (orderedDish.getID() != 0) {
        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;

        // Tạo đơn hàng
        Order newOrder(orderedDish, quantity);

        // Thêm đơn hàng vào danh sách của bàn
        // (Bạn cần thay đổi phần này để thực hiện thêm đơn hàng vào bàn cụ thể)
        // table.orderDish(newOrder);

        // Hiển thị chi tiết đơn hàng
        cout << "Ordered: " << orderedDish.getName() << " x" << quantity << endl;
        cout << "Total cost: $" << orderedDish.getPrice() * quantity << endl;
    }
    else {
        cout << "Dish not found." << endl;
    }
}


// ...