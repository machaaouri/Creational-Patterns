#include "Employee.h"
#include "EmployeeBuilder.h"

EmployeeBuilder Employee::create()
{
	return EmployeeBuilder();
}