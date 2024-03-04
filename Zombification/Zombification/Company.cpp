#include "Company.h"

void Company::CreateEmployee(int employeeCount) {
	for (size_t i = 0; i < employeeCount; i++)
	{
		employees.emplace_back(make_unique<Employee>(0, 2 + (rand() % 4), ZombificationState::SANE));
	}
}

int Company::GetEmployeeZombifiedCount() {
	int employeeZombifiedCount = 0;

	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->CheckIsZombified()) {
			employeeZombifiedCount += 1;
		}
	}

	return employeeZombifiedCount;
}