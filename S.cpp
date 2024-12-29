

// A class should have only one reason to change called single responsibility principle


// Without SRP:
// In this approach, both calculating salary and saving employee details are handled by the same class.

#include <bits/stdc++.h>
using namespace std;

// class Employee {
// public:
//     string name;
//     double hourlyRate;
//     int hoursWorked;
//     Employee(const string& n, double rate, int hours) {
//     name = n;
//     hourlyRate = rate;
//     hoursWorked = hours;
// }


//     double calculateSalary() {
//         return hourlyRate * hoursWorked;
//     }

//     void saveToDatabase() const {
//         cout << "Saving " << name << " to the database.\n";
//     }
// };

// int main() {
//     Employee emp("John", 20.0, 40);
//     cout << "Salary: " << emp.calculateSalary() << "\n";
//     emp.saveToDatabase();  // This class is doing too much!
//     return 0;
// }


//Problem: The Employee class is doing two things:

// Calculating the salary.
// Saving employee details to the database.
// With SRP:
// Now we separate the responsibilities into different classes.



class Employee {
public:
    string name;
    double hourlyRate;
    int hoursWorked;

    Employee(const string& n, double rate, int hours) {
       name = n;
       hourlyRate = rate;
       hoursWorked = hours;
   }

    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }
};

class Database {
public:
    void saveToDatabase(const Employee& emp) const {
        cout << "Saving " << emp.name << " to the database.\n";
    }
};

int main() {
    Employee emp("John", 20.0, 40);
    Database db;

    cout << "Salary: " << emp.calculateSalary() << "\n";
    db.saveToDatabase(emp);  // Now Database is doing the saving!

    return 0;
}