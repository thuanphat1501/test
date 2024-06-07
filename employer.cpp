#include"employer.hpp"
#include"table.hpp"
#include"manager.hpp"
#include <vector>
#include <string>
#include<iostream>
Table Employer::getTable(int id) {
    for (const Table& table : list_table) {
        if (table.getID() == id) {
            return table;
        }
    }
    
}
void Employer::displaySelectedTable(int num)
{
    cout << "Selected table: ";
    for (int i = 1; i <= num; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}

// ...