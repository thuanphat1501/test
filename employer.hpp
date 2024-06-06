#ifndef EMPLOYER_H
#define EMPLOYER_H

#include"table.hpp"
#include<vector>
#include<string>
#include<list>

using namespace std;

class Employer
{
private:
	vector<Table> list_table;
public:
	Employer(list<Dish> menu, int number_table, string password = "EMPLOYER")
	{
		for (int i = 1; i <= number_table; ++i)
		{
			Table table(i, false, menu);
			list_table.push_back(table);
		}
	};

	Table getTable(int id);

};

#endif // !EMPLOYER_H
