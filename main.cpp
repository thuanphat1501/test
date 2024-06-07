#include<iostream>
#include<list>
#include <fstream>
#include"dish.hpp"
#include"employer.hpp"
#include"manager.hpp"
using namespace std;

void printMenu(const list<Dish>& menu);
int main()
{
	list<Dish> Menu;
	int number_table = 0;
	Manager manager1(Menu, number_table);
	Employer employee1(Menu, number_table);
    int reload;
    int choice;
    do {
        cout <<"Restaurant manager\n"
            << "1. Manager\n"
            << "2. Staff\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int m_option;
            do {
                
                cout << "Manager\n"
                    << "1. Setup Number Table\n"
                    << "2. Add Dish\n"
                    << "3. Update Dish\n"
                    << "4. Delete Dish\n"
                    << "5. List of Dish\n"
                    << "0. Exit\n"
                    << "Enter your choice: ";
                cin >> m_option;
                switch (m_option)
                {
                case 1:
                    
                    do
                    {
                        cout << "----Setup Number Table----\n"
                            << "Enter number of table:";
                       
                        cin >> number_table;
                        manager1.setTable(number_table);
                        cout << "Setup table successfully! \n"
                            << "1. Return.\n"
                            << "0. Exit.\n"
                            << "Enter your choice:";
                        
                        cin >> reload;
                        switch (reload)
                        {
                        case 1:
                            continue; // Quay lại màn hình chính
                        case 0:
                            break; // Thoát khỏi chương trình
                        }
                        break;
                    } while (reload != 0);
                    break;
                case 2:
                    do
                    {
                        cout << "----Add Dish To Menu----\n";
                        manager1.newDish();
                        cout << "1. Return.\n"
                            << "0. Exit.\n"
                            << "Enter your choice:";

                        cin >> reload;
                        switch (reload)
                        {
                        case 1:
                            continue; // Quay lại màn hình chính
                        case 0:
                            break; // Thoát khỏi chương trình
                        }
                        break;
                    } while (reload != 0);
                    break;
                case 3:
                    do
                    {
                        cout << "----Update Price For Dish----\n";
                        manager1.listDish();
                        manager1.updatePrice();
                        cout << "1. Return.\n"
                            << "0. Exit.\n"
                            << "Enter your choice:";

                        cin >> reload;
                        switch (reload)
                        {
                        case 1:
                            continue; // Quay lại màn hình chính
                        case 0:
                            break; // Thoát khỏi chương trình
                        }
                        break;
                    } while (reload != 0);
                    
                    break;
                case 4:
                    do
                    {
                        cout << "----Delete Dish To Menu----\n";
                        cout << "Enter ID want to delete:";
                        int deleteDish;
                        cin >> deleteDish;
                        manager1.deleteDish(deleteDish);
                        cout << "1. Return.\n"
                            << "0. Exit.\n"
                            << "Enter your choice:";

                        cin >> reload;
                        switch (reload)
                        {
                        case 1:
                            continue; // Quay lại màn hình chính
                        case 0:
                            break; // Thoát khỏi chương trình
                        }
                        break;
                    } while (reload != 0);
                    break;
                case 5:
                    cout << "List of Dish:";
                    manager1.listDish();
                    break;
                default:
                    break;
                }
            } while (m_option != 0);
            break;
        case 2:
            employee1.displaySelectedTable(number_table);
            int staffOption;
            cout << "Staff\n"
                << "1. Get Table\n"
                << "0. Exit\n"
                << "Enter your choice: ";
            
            cin >> staffOption;
            switch (staffOption)
            {
            case 1:
            {
                int numTable;
                cout << "Choose Table: ";
                cin >> numTable;
                Table chosenTable = employee1.getTable(numTable);
                if (chosenTable.getStatusTable())
                {
                    cout << "Table " << numTable << " is available." << endl;
                }
                else
                {
                    cout << "Table " << numTable << " is not available." << endl;
                }
                break;
            }

            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            break; // Thêm dòng này để thoát khỏi vòng lặp chính
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
	
}