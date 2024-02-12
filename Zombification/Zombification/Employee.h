#pragma once

#include "GlobalHeader.h"

enum ZombificationState
{
	SANE,
	INCUBATING,
	ZOMBIFIED
};

class Employee
{
public:
	int infectionTime;
	ZombificationState state = ZombificationState::SANE;

	bool CheckIsZombified();
	void HandleInfection();
	void SetNewZombificationState();

	Employee(int infectionTime, ZombificationState state);
};