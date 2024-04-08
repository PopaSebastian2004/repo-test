#include "Fiat.h"
#include "Weather.h"
#include <string>

Fiat::Fiat()
{
	fuel_capacity = 45;
	fuel_consumption = 5;
	average_speed[Weather::Rain] = 50;
	average_speed[Weather::Snow] = 30;
	average_speed[Weather::Sun] = 130;
	Name_Car = "Fiat";
};

float Fiat::calculateTime(int weather, int length, bool& Finish)
{
	int speed = average_speed[weather];

	float h = fuel_capacity / fuel_consumption;
	float distance = h * speed; // hour * km/hour

	if (distance > length)
	{
		Finish = 1;
	}
	else
	{
		Finish = 0;
	}

	float tof = length * h / distance;
	return tof;
}

const char* Fiat::GetName()
{
	return Name_Car;
}