#include"manager.hpp"
#include"table.hpp"
#include"dish.hpp"
#include<iostream>
void Manager::setTable(int number) { number_table = number; };
void Manager::newDish(Dish dish)
{ 
	menu.push_back(dish); 
}
void Manager::updatePrice(Dish dish)
{
    for (Dish& existingDish : menu)
    {
        if (existingDish.getID() == dish.getID())
        {
            // Tìm thấy món ăn, cập nhật giá
            existingDish.setPrice(dish.getPrice());
            return; // Kết thúc hàm sau khi cập nhật
        }
    }
    // Không tìm thấy món ăn, có thể xử lý thông báo lỗi nếu cần
    cout << "Dish not found." << endl;
}

void Manager::deleteDish(Dish dish)
{
    for (auto it = menu.begin(); it != menu.end(); ++it)
    {
        if (it->getID() == dish.getID())
        {
            // Tìm thấy món ăn, xóa khỏi danh sách
            menu.erase(it);
            return; // Kết thúc hàm sau khi xóa
        }
    }
    // Không tìm thấy món ăn, có thể xử lý thông báo lỗi nếu cần
}
