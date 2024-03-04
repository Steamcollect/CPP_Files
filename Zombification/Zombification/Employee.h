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
	int incubationTime;
	ZombificationState state = ZombificationState::SANE;

	bool CheckIsZombified();
	void HandleInfection();
	void SetNewZombificationState();

	Employee(int infectionTime, int incubationTime, ZombificationState zombificaionState);
};