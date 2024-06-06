#include<iostream>
#include<list>
#include <fstream>
#include"dish.hpp"
#include"employer.hpp"
#include"manager.hpp"
using namespace std;
//void updateCSV(const list<Student>& database) {
//    ofstream outputFile("student.csv");
//    if (outputFile.is_open()) {
//        for (const auto& student : database) {
//            outputFile << student.getID() << ","
//                << student.getName() << ","
//                << student.getGender() << ","
//                << student.getAge() << ","
//                << student.getMathScore() << ","
//                << student.getPhysicsScore() << ","
//                << student.getChemistryScore() << endl;
//        }
//        outputFile.close();
//        cout << "CSV file updated successfully." << endl;
//    }
//    else {
//        cout << "Error opening student.csv for writing." << endl;
//    }
//}
//istream& operator>>(istream& in, Gender& gender) {
//    int value;
//    in >> value;
//    gender = static_cast<Gender>(value);
//    return in;
//}

void printMenu(const list<Dish>& menu);
int main()
{
	list<Dish> Menu;
	int number_table = 0;
	Manager manager1(Menu, number_table);
	Employer employee1(Menu, number_table);
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
            do {
                cout << "Manager\n"
                    << "1. Setup Number Table\n"
                    << "2. Add Dish\n"
                    << "3. Update Dish\n"
                    << "2. Delete Dish\n"
                    << "2. List of Dish\n"
                    << "0. Exit\n"
                    << "Enter your choice: ";
                // addStudent(studentDatabase);
            } while
            break;
        case 2:
            int targetID;
            cout << "Enter student ID to delete: ";
            cin >> targetID;
            //deleteStudent(studentDatabase, targetID);
            break;
        case 3:
            int updateID;
            cout << "Enter student ID to update: ";
            cin >> updateID;
            //updateStudent(studentDatabase, updateID);
            break;
        case 4:

            //searchStudent(studentDatabase);
            break;
        case 5:
            int sortingOption;
            cout << "Choose sorting option:" << endl;
            cout << "1. Sort by name" << endl;
            cout << "2. Sort by math score" << endl;
            cout << "3. Sort by physics score" << endl;
            cout << "4. Sort by chemistry score" << endl;
            cout << "5. Sort by average score" << endl;
            cout << "Enter your choice (1-5): ";
            cin >> sortingOption;

            //sortStudent(studentDatabase, sortingOption);
            break;
        case 6:
            //printStudents(studentDatabase);
            break;
        case 7:
            //updateCSV(studentDatabase);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
	
}