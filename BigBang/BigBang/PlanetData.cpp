#include "PlanetData.h"

void PlanetData::CreateRandomly() {
	PlanetData::SetPlanetType();

	switch (type)
	{
	case Telluric:
		PlanetData::SetPlanetData(radiusMinTelluric, radiusMaxTelluric, gravityMinTelluric, gravityMaxTelluric);
		break;
	case Gaseous:
		PlanetData::SetPlanetData(radiusMaxGaseous,radiusMaxDead,gravityMinGaseous,gravityMaxGaseous);
		break;
	case Dead:
		PlanetData::SetPlanetData(radiusMaxDead,radiusMaxDead,gravityMinDead,gravityMaxDead);
		break;
	default:
		break;
	}
}

void PlanetData::SetPlanetType() {
	int rnd = PlanetData::GetRandomBetween(0,100);

	if (rnd <= 20) type = PlanetType::Telluric;
	else if (rnd <= 40) type = PlanetType::Dead;
	else type = PlanetType::Gaseous;
}

void PlanetData::SetPlanetData(float minRadius, float maxRadius, int minGravity, int maxGravity) {
	radius = PlanetData::GetRandomBetween(minRadius, maxRadius);
	gravityForce = PlanetData::GetRandomBetween(minGravity, maxGravity);
}

int PlanetData::GetRandomBetween(int min, int max) {
	return (rand() % (max - min + 1) + min);
}