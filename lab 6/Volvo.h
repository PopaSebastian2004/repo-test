#pragma once

#include "Car.h"

class Volvo : public Car
{
public:
    Volvo();
    float calculateTime(int, int, bool&) override; // calculateTime(int, int, bool&) is Virtual in "Car.h" 
    const char* GetName() override;
};
