#include "Company.h"

Company company;

int main()
{
	company.employees.clear();
	company.CreateEmployee(100);
	company.employees[0]->SetNewZombificationState();
	
	srand(time(NULL));
	int rand;
	int employeeZombifiedCount;

	for (size_t i = 0; i < 28; i++)
	{
		employeeZombifiedCount = company.GetEmployeeZombifiedCount();

		for (size_t i = 0; i < company.employees.size(); i++)
		{
			company.employees[i]->HandleInfection();

			rand = std::rand() % 100;

			if (rand <= employeeZombifiedCount) {
				company.employees[i]->SetNewZombificationState();
			}
		}
		cout << "There was " << company.GetEmployeeZombifiedCount() << " infected at the day " << i << endl;
	}

	string input;
	cout << endl << "Press 'R' to reload" << endl;
	cin >> input;
	if (input == "r"){
		system("cls");
		main();
	}
}