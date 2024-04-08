#pragma once
#include <random>

enum PlanetType
{
	Telluric,
	Gaseous,
	Dead
};

class PlanetData
{
public:
	float radius;
	float gravityForce;
	PlanetType type;

	int radiusMinTelluric = 2500, radiusMaxTelluric = 8000, radiusMinDead = 2000, radiusMaxDead = 5000, radiusMinGaseous = 50000, radiusMaxGaseous = 90000;
	int gravityMinTelluric = 3, gravityMaxTelluric = 10, gravityMinDead = 9, gravityMaxDead = 24, gravityMinGaseous = 3, gravityMaxGaseous = 12;

	void CreateRandomly();
	void SetPlanetType();
	void SetPlanetData(float minRadius, float maxRadius, int minGravity, int maxGravity);

	int GetRandomBetween(int min, int max);
};