#include "Seat.h"
#include "Weather.h"
#include <string>

Seat::Seat()
{
	fuel_capacity = 40;
	fuel_consumption = 7;
	average_speed[Weather::Rain] = 40;
	average_speed[Weather::Snow] = 25;
	average_speed[Weather::Sun] = 100;
	Name_Car = "Seat";
};

float Seat::calculateTime(int weather, int length, bool& Finish)
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

const char* Seat::GetName()
{
	return Name_Car;
}