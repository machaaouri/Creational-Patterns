#pragma once
#include <string>
#include "Employee.h"
#include "EmployeeBuilder.h"

using namespace std;

class EmployeeAddressBuilder : public EmployeeBuilder
{
	typedef EmployeeAddressBuilder Self;
public:
	explicit EmployeeAddressBuilder(Employee & employee)
		: EmployeeBuilder {employee}
	{
	}

	Self& at(string street_address)
	{
		employee.street_address = street_address;
		return *this;
	}

	Self& with_postcode(string post_code)
	{
		employee.post_code = post_code;
		return *this;
	}

	Self& in(string city)
	{
		employee.city = city;
		return *this;
	}
};