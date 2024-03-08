#pragma once
#include <string>

class MyClass
{
		struct note
		{
			float h, m, e;
		};
		note grades;
		char * name;

public:
	MyClass();
	~MyClass();
	void SetGradeM(float x);
	float GetGradeM();
	void SetGradeE(float x);
	float GetGradeE();
	void SetGradeH(float x);
	float GetGradeH();
	float GetAvg();
	void SetName(const char * my_name);
	const char* GetName();
};