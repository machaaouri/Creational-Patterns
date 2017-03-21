#pragma once
#include "EmployeeBuilder.h"


class EmployeeJobBuilder : public EmployeeBuilder
{

	typedef EmployeeJobBuilder Self;
public:
	explicit EmployeeJobBuilder(Employee & employee)
		: EmployeeBuilder {employee}
	{}

	Self& in(string department)
	{
		employee.department = department;
		return *this;
	}

	Self& as_a(string position)
	{
		employee.position = position;
		return *this;
	}

	Self& earnings(int annual_income)
	{
		employee.annual_income = annual_income;
		return *this;
	}
};