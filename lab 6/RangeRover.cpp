#include "RangeRover.h"
#include "Weather.h"
#include <string>

RangeRover::RangeRover()
{
	fuel_capacity = 104;
	fuel_consumption = 3;
	average_speed[Weather::Rain] = 50;
	average_speed[Weather::Snow] = 40;
	average_speed[Weather::Sun] = 160;
	Name_Car = "RangeRover";
};

float RangeRover::calculateTime(int weather, int length, bool& Finish)
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

const char* RangeRover::GetName()
{
	return Name_Car;
}