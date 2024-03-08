#include "Student.h"
#include "Globals.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	MyClass student1;

	student1.SetGradeM(9.7);
	printf("Nota la mate este :%.2f\n", student1.GetGradeM());

	student1.SetGradeE(5.6);
	printf("Nota la engleza este :%.2f\n", student1.GetGradeE());

	student1.SetGradeH(5.6);
	printf("Nota la istorie este :%.2f\n", student1.GetGradeH());

	printf("Media notelor este : %.2f\n", student1.GetAvg());

	student1.SetName("Marcel");
	printf("Numele este : %s",student1.GetName ());

	 
	printf("\n");\
	printf("\n");
	MyClass student2;

	student2.SetGradeM(9.6);
	printf("Nota la mate este : %.2f\n", student2.GetGradeM());

	student2.SetGradeE(5.6);
	printf("Nota la engleza este :%.2f\n", student2.GetGradeE());

	student2.SetGradeH(5.6);
	printf("Nota la istorie este : %.2f\n", student2.GetGradeH());

	printf("Media notelor este : %.2f\n", student2.GetAvg());

	student2.SetName("Cosmin");
	printf("Numele este : %s", student2.GetName());

	printf("\n");
	printf("\n");
	printf("Valoarea comparatiei dintre notele la mate este : %d\n", MyCompareMath(&student1, &student2));
	printf("Valoarea comparatiei dintre notele la engleza este : %d\n", MyCompareEnglish(&student1, &student2));
	printf("Valoarea comparatiei dintre notele la istorie este : %d\n", MyCompareHistory(&student1, &student2));
	printf("Valoarea comparatiei dintre mediile noteleor este : %d\n", MyCompareAVG(&student1, &student2));
	printf("Valoarea comparatiei dintre numele studentilor este  : %d\n", MyCompareName(&student1, &student2));
	system("pause");
	return 0;
}