#include <iostream>
#include "Database.hpp"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

void sampleEmployees(Database& db);

int main()
{
    Database employeeDB;
    sampleEmployees(employeeDB);
    bool done = false;
    int selection;

    while (!done) {
        selection = displayMenu();
        switch (selection)
        {
        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            doDemote(employeeDB);
            break;
        case 5:
            employeeDB.displayAll();
            break;
        case 6:
            employeeDB.displayCurrent();
            break;
        case 7:
            employeeDB.displayFormer();
            break;
        default:
            cout << "Invalid input try again" << endl;
            break;
        }
    }
}

void sampleEmployees(Database& db)
{
    Employee& emp1 = db.addEmployee("John", "Doe");
    emp1.promote(777);

    Employee& emp2 = db.addEmployee("Master", "Tuturu");
    emp2.fire();
    
    Employee& emp3 = db.addEmployee("Matchuchu", "Pelo");
    Employee& emp4 = db.addEmployee("Allanoob", "Natalo");
    Employee& emp5 = db.addEmployee("Jojo", "Sepsep");
}

int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an Employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) Demote an employee" << endl;
    cout << "5) List all employees" << endl;
    cout << "6) List all current employees" << endl;
    cout << "7) List all former employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database& db)
{
    string firstName, lastName;

    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    db.addEmployee(firstName, lastName);
}

void doFire(Database& db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    Employee& emp = db.getEmployee(employeeNumber);
    emp.fire();
}

void doPromote(Database& db)
{
    int raiseAmount, employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    cout << "How much of raise? ";
    cin >> raiseAmount;

    Employee& emp1 = db.getEmployee(employeeNumber);
    emp1.promote(raiseAmount);
}

void doDemote(Database& db)
{
    int decreaseAmount, employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    cout << "How much of decrease? ";
    cin >> decreaseAmount;

    Employee& emp1 = db.getEmployee(employeeNumber);
    emp1.promote(decreaseAmount);
}