#include "Employee.h"

bool Employee::CheckIsZombified() {
	return state == ZombificationState::ZOMBIFIED;
}

void Employee::HandleInfection() {
	if (state == ZombificationState::INCUBATING) {
		infectionTime += 1;

		if (infectionTime == incubationTime) {
			SetNewZombificationState();
		}
	}
}

void Employee::SetNewZombificationState() {
	switch (state)
	{
	case SANE:
		state = ZombificationState::INCUBATING;
		break;
	case INCUBATING:
		state = ZombificationState::ZOMBIFIED;
		break;
	case ZOMBIFIED:
		state = ZombificationState::ZOMBIFIED;
		break;
	}
}

Employee::Employee(int infTime, int incTime, ZombificationState zombificationState) {
	infectionTime = infTime;
	incubationTime = incTime;
	state = zombificationState;
}