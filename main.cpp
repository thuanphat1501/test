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
                        int number;
                        cin >> number;
                        manager1.setTable(number);
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
        case 2:
            //int targetID;
            //cout << "Enter student ID to delete: ";
            //cin >> targetID;
            ////deleteStudent(studentDatabase, targetID);
            //break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
	
}