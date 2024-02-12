#pragma once
#include "GlobalHeader.h"
#include "Employee.h"

class Company
{
public:
	vector<unique_ptr<Employee>> employees;

	void CreateEmployee(int employeeCount);

	int GetEmployeeZombifiedCount();
};