#include <iostream>
#include <vector>
#include "PlanetData.h"
#include <string>;

using namespace std;

int planetCount = 100;
vector<PlanetData> planets;

void CreatePlanet() {
	for (size_t i = 0; i < planetCount; i++)
	{
		unique_ptr<PlanetData> current = make_unique<PlanetData>();
		current->CreateRandomly();
		planets.push_back(*current);
	}
}

void PrintPlanetsInfos() {
	for (size_t i = 0; i < planets.size(); i++)
	{
		string planetType;
		switch (planets[i].type)
		{
		case PlanetType::Telluric:
			planetType = "Telluric";
			break;

		case PlanetType::Gaseous:
			planetType = "Gaseous";
			break;
			
			case PlanetType::Dead:
			planetType = "Dead";
			break;
		default:
			break;
		}

		cout << "Planet " << i + 1 << " is " << planetType << ", at a distance of " << planets[i].radius << "km from Earth, and with a gravity of " << planets[i].gravityForce << "m/s2\n\r";
	}
}

int main()
{
	CreatePlanet();
	PrintPlanetsInfos();
}
