#pragma once

#include <string>
using namespace std;

class EmployeeBuilder;

class Employee
{

	// address 
	string street_address, post_code, city;

	// employement
	string position, department;
	int annual_income;

	// prohibit the process of makin a new instance of person
	// you can only build the Employee through the builder
	Employee(){} 

public:
	static EmployeeBuilder create();

	Employee(Employee&& e)
		:street_address{ move(e.street_address) },
		post_code{ move(e.post_code) },
		city{ move(e.city) },
		position{ move(e.position) },
		annual_income{ e.annual_income }
	{

	}


	Employee& operator=(Employee && e)
	{
		if (this == &e)
			return *this;
		street_address = move(e.street_address);
		post_code = move(e.post_code);
		city = move(e.city);
		position = move(e.position);
		annual_income = e.annual_income;

	}


	friend ostream& operator<<(ostream& os, const Employee& obj)
	{
		return os
			<< " street_address: " << obj.street_address
			<< "post_code: " << obj.post_code
			<< "city: " << obj.city
			<< "position: " << obj.position
			<< "annual_income: " << obj.annual_income;
	}

	friend class EmployeeBuilder;
	friend class EmployeeAddressBuilder;
	friend class EmployeeJobBuilder;

};
