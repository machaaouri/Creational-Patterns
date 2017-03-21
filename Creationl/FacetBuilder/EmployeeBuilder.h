#pragma once
#include "Employee.h"

class EmployeeAddressBuilder;
class EmployeeJobBuilder;

class EmployeeBuilder
{
	Employee e;
protected:
	Employee & employee;

	explicit EmployeeBuilder(Employee & employee)
		: employee{employee}
	{
	}
public:
	EmployeeBuilder() : employee(e) {}

	operator Employee()
	{
		return move(employee);
	}

	EmployeeAddressBuilder lives();
	EmployeeJobBuilder works();
};
