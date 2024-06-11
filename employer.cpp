#include"employer.hpp"
#include"table.hpp"
#include"manager.hpp"
#include"dish.hpp"
#include <vector>
#include <string>
#include<iostream>
// Trong lớp Employer
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
    cout << "Table not found\n"; // In ra thông báo khi không tìm thấy bàn
    // Hoặc bạn có thể ném một ngoại lệ để xử lý tùy ý
    // throw std::runtime_error("Bàn không tồn tại!");
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
void Employer::order(Table& table, const list<Dish>& menu) {
    cout << "Menu:" << endl;
    for (const auto& dish : menu) {
        cout << "ID: " << dish.getID() << " - " << dish.getName() << " ($" << dish.getPrice() << ")" << endl;
    }

    int dishID;
    cout << "Enter the dish ID: ";
    cin >> dishID;

    // Find the dish in the menu
    Dish orderedDish;
    for (const auto& dish : menu) {
        if (dish.getID() == dishID) {
            orderedDish = dish;
            break;
        }
    }

    if (orderedDish.getID() != -1) {
        int quantity;
        cout << "Enter the quantity: ";
        cin >> quantity;

        // Create an order
        Order newOrder(orderedDish, quantity);

        // Add the order to the table's list
        table.orderDish(newOrder);

        cout << "Order placed successfully!" << endl;
    }
    else {
        cout << "Dish not found." << endl;
    }
}




// ...