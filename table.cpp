#include "order.hpp"
#include"table.hpp"
#include <list>

using namespace std;

int Table::getID() const
{
    return id_table;
}

bool Table::getStatusTable()
{
    return status_table;
}

void Table::orderDish(Order order)
{
    // Thêm order vào danh sách order
    list_order.push_back(order);
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

