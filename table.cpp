#include "order.hpp"
#include"table.hpp"
#include <list>
#include <iostream>
using namespace std;

int Table::getID() const
{
    return id_table;
}

bool Table::getStatusTable()
{
    return status_table;
}
 
void Table::orderDish() {
    // Hiển thị danh sách món ăn
    cout << "Danh sách món ăn:" << endl;
    for (const auto& dish : menu) {
        cout << "ID: " << dish.getID() << ", Tên: " << dish.getName() << ", Giá: " << dish.getPrice() << endl;
    }

    // Nhập ID của món ăn
    int dishId;
    cout << "Nhập ID của món ăn: ";
    cin >> dishId;

    // Kiểm tra xem món ăn đã tồn tại trong danh sách menu hay không
    bool found = false;
    Dish selectedDish; // Declare a Dish object to store the selected dish
    for (const auto& dish : menu) {
        if (dish.getID() == dishId) {
            found = true;
            selectedDish = dish; // Store the selected dish
            break;
        }
    }

    if (found) {
        // Nhập số lượng món ăn
        int quantity;
        cout << "Nhập số lượng: ";
        cin >> quantity;

        // Tạo đối tượng Order và thêm vào danh sách đặt hàng
        Order order(selectedDish, quantity);
        list_order.push_back(order);

        // Cập nhật tổng tiền
        bill += order.getDish().getPrice() * quantity;

        // In ra thông tin món ăn đã đặt
        cout << "Đã đặt: " << selectedDish.getName() << " x " << quantity << " - Tổng tiền: " << order.getDish().getPrice() * quantity << endl;
    }
    else {
        cout << "Món ăn không tồn tại trong menu." << endl;
    }
}




void Table::deleteDish(Order order) {
    // Tìm kiếm món ăn trong danh sách đặt hàng
    auto it = list_order.begin();
    while (it != list_order.end()) {
        if (it->getDish().getID() == order.getDish().getID()) {
            // Xóa món ăn khỏi danh sách đặt hàng
            it = list_order.erase(it);
            break;
        }
        else {
            ++it;
        }
    }
}

list<Order> Table::getListOrder()
{
     return list_order;
}

void Table::makePayment()
{
    // Tính tổng số tiền cho các món ăn trong list_order
    int totalPayment = 0;
    for (const Order& order : list_order)
    {
        totalPayment += order.getDish().getPrice() * order.getNumberDish();
    }

    // Cập nhật giá trị của biến bill
    bill = totalPayment;

    // Xóa danh sách đặt hàng
    list_order.clear();
}
