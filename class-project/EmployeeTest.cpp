#include <iostream>
#include "Employee.hpp"

using namespace std;
using namespace Records;

int main()
{
	cout << "Testing the Employee class." << endl;
	Employee emp1;

	emp1.setFirstName("Godwin");
	emp1.setLastName("Bardiago");
	emp1.setEmployeeNumber(77);
	emp1.setSalary(100000);
	emp1.promote();
	emp1.promote(150);
	emp1.demote();
	emp1.demote(100000);
	emp1.hire();
	emp1.display();
	return 0;
}