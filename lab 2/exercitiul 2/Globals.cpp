#include "Globals.h"
#include <stdio.h>
#include <cstring>
//daca avem *, folosim ->
//daca avem normal, folosim .

int MyCompareMath(MyClass* obiectul1, MyClass* obiectul2) {
	if (obiectul1->GetGradeM() < obiectul2->GetGradeM())
		return -1;
	if (obiectul1->GetGradeM() == obiectul2->GetGradeM())
		return 0;
	if (obiectul1->GetGradeM() > obiectul2->GetGradeM())
		return 1;
}

int MyCompareEnglish(MyClass* obiectul1, MyClass* obiectul2) {
	if (obiectul1->GetGradeE() < obiectul2->GetGradeE())
		return -1;
	if (obiectul1->GetGradeE() == obiectul2->GetGradeE())
		return 0;
	if (obiectul1->GetGradeE() > obiectul2->GetGradeE())
		return 1;
}

int MyCompareHistory(MyClass* obiectul1, MyClass* obiectul2) {
	if (obiectul1->GetGradeH() < obiectul2->GetGradeH())
		return -1;
	if (obiectul1->GetGradeH() == obiectul2->GetGradeH())
		return 0;
	if (obiectul1->GetGradeH() > obiectul2->GetGradeH())
		return 1;
}

int MyCompareAVG(MyClass* obiectul1, MyClass* obiectul2) {
	if (obiectul1->GetAvg() < obiectul2->GetAvg())
		return -1;
	if (obiectul1->GetAvg() == obiectul2->GetAvg())
		return 0;
	if (obiectul1->GetAvg() > obiectul2->GetAvg())
		return 1;
}
int MyCompareName(MyClass* obiectul1, MyClass* obiectul2) {
	const char* name1; 
	const char* name2;
	name1 = obiectul1->GetName();
	name2 = obiectul2->GetName();
	int i;
	int length = strlen(name1);
	for (i = 0; name1[i] - 'A' == name2[i] - 'A' && i < length; i++);
	if (name1[i] - 'A' > name2[i] - 'A')
		return 1;
	else if (name1[i] - 'A' < name2[i] - 'A')
		return -1;
	else
		return 0;
}