#include "BMW.h"
#include "Weather.h"
#include <string>

BMW::BMW()
{
	fuel_capacity = 59;
	fuel_consumption = 2;
	average_speed[Weather::Rain] = 60;
	average_speed[Weather::Snow] = 40;
	average_speed[Weather::Sun] = 140;
	Name_Car = "BMW";
};

float BMW::calculateTime(int weather, int length, bool& Finish)
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

	float tof = length * h / distance; // time of finish
	return tof;
}

const char* BMW::GetName()
{
	return Name_Car;
}
