#ifndef TABLE_H
#define TABLE_H


#include"order.hpp"
#include<list>
#include<vector>

using namespace std;

class Table
{
private:
	int id_table;
	bool status_table;
	list<Dish> menu;
	list<Order> list_order;
	//static vector<Table> list_table;
	int bill;
public:
	Table(int id, bool status_table = false, list<Dish> menu = {}) :
		id_table(id), status_table(status_table), menu(menu) {}
	int getID() const;

	bool getStatusTable();
	void orderDish();
	void deleteDish(Order order);
	list<Order> getListOrder();
	void makePayment();
	

};

#endif // !TABLE_H
