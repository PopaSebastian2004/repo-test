#include "Student.h"
#include <stdio.h>
#include <cstring>

void MyClass::SetGradeM(float x)
{
	if(x >= 1.0 && x <= 10.0)
	    this->grades.m = x;
}
float MyClass::GetGradeM()
{
	return this->grades.m;
}
void MyClass::SetGradeE(float x)
{
	if (x >= 1.0 && x <= 10.0)
		this->grades.e = x;
}
float MyClass::GetGradeE()
{
	return this->grades.e;
}
void MyClass::SetGradeH(float x)
{
	if (x >= 1.0 && x <= 10.0)
		this->grades.h = x;
}
float MyClass::GetGradeH()
{
	return this->grades.h;
}
float MyClass::GetAvg()
{
	return (this->grades.h +this->grades.e + this->grades.m)/3.0;
}

void MyClass::SetName(const char* my_name)
{
	int length = std::strlen(my_name);
	name= new char[length+1]; 
	name[length] = 0;
	for (int i = 0; i < length; i++)
		name[i] = my_name[i];
}
const char* MyClass::GetName()
{
	return name;
}
MyClass::MyClass() {
	
	
}

MyClass::~MyClass() {
	
}
