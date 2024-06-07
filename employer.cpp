#include"employer.hpp"
#include"table.hpp"
#include"manager.hpp"
#include <vector>
#include <string>
#include<iostream>
Table Employer::getTable(int id)
{
    // Tìm và trả về bàn với ID tương ứng
    for (const Table& table : list_table)
    {
        if (table.getID() == id)
        {
            return table;
        }
    }
    // Nếu không tìm thấy, có thể xử lý thông báo lỗi hoặc trả về bàn mặc định
    // (ví dụ: Table(0, false, menu))
    // ...
}
void Employer::displaySelectedTable()
{
    cout << "Selected table: " << selectedTable << endl;
}
// ...