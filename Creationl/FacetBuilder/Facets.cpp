#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "Employee.h"
#include "EmployeeBuilder.h"
#include "EmployeeAddressBuilder.h"
#include "EmployeeJobBuilder.h"


int main()
{

	Employee e = Employee::create()
		.lives().at("2 allee de la lisiere").with_postcode("78260").in("Achers")
		.works().in("R&D").as_a("Software Engineer").earnings(100);

	cout << e << endl;

	getchar();
	return 0;
}