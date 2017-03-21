#include "EmployeeBuilder.h"
#include "EmployeeAddressBuilder.h"
#include "EmployeeJobBuilder.h"


EmployeeJobBuilder EmployeeBuilder::works()
{
	return EmployeeJobBuilder{ employee };
}

EmployeeAddressBuilder EmployeeBuilder::lives()
{
	return EmployeeAddressBuilder{ employee };
}
