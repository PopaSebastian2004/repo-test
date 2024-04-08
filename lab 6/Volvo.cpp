#include "Volvo.h"
#include "Weather.h"
#include <string>

Volvo::Volvo()
{
	fuel_capacity = 60;
	fuel_consumption = 3;
	average_speed[Weather::Rain] = 30;
	average_speed[Weather::Snow] = 20;
	average_speed[Weather::Sun] = 110;
	Name_Car = "Volvo";
}

float Volvo::calculateTime(int weather, int length, bool& Finish)
{
	int speed = average_speed[weather];

	float h = fuel_capacity / fuel_consumption;
	float distance = h * speed;

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

const char* Volvo::GetName()
{
	return Name_Car;
}