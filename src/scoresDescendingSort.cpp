/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
int partition(struct student *stud, int l, int h)
{
	int x = stud[h].score;
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (stud[j].score >= x)
		{
			i++;
			struct student temp = stud[j];
			stud[j] = stud[i];
			stud[i] = temp;
		}
	}
	struct student temp = stud[i + 1];
	stud[i + 1] = stud[h];
	stud[h] = temp;
	return (i + 1);
}


void quickSort(struct student *stud, int l, int h)
{
	if (l < h)
	{
		int p = partition(stud, l, h);
		quickSort(stud, l, p - 1);
		quickSort(stud, p + 1, h);
	}
}


void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 1)
		return NULL;
	quickSort(students, 0, len - 1);

}