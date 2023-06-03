
#include <iostream>
#include "HelpFunctions.h"
#include "Pair.h"

using namespace std;

enum { MAX = 'a', DELETE_MAX, MIN, DELETE_MIN, CREATE_EMPTY, INSERT, MEDIAN };

#define FIRST_OPERATION 'a'
#define LAST_OPERATION 'g'

void Swap(Pair* arr, int index1, int index2)
{
	Pair temp = arr[index1];

	arr[index1] = arr[index2];
	arr[index1].index_AT_Heap = index1;

	arr[index2] = temp;
	arr[index2].index_AT_Heap = index2;

	if (arr[index1].clonePair != nullptr)
		arr[index1].clonePair->clonePair = &arr[index1];

	if (arr[index2].clonePair != nullptr)
		arr[index2].clonePair->clonePair = &arr[index2];

}

void nValidation(int n)
{
	if (n <= 0)
	{
		cout << "wrong input";
		exit(1);
	}
}

void eValidation(int i, char action)
{
	if ((i == 0 && action != CREATE_EMPTY) || (i != 0 && action == CREATE_EMPTY)) // CREATE_EMPTY check
	{
		cout << "wrong input";
		exit(1);
	}
}

void actionValidation(char action)
{
	if (action < FIRST_OPERATION || action > LAST_OPERATION)
	{
		cout << "wrong input";
		exit(1);
	}
}

HeapMedian Insert_Validation(HeapMedian MHeap)
{
	string number, data;
	int priority;

	cin >> number;
	for (char ch : number)
	{
		if (ch < '0' || ch > '9')
		{
			cout << "wrong input";
			exit(1);
		}
	}
	priority = stoi(number);

	getchar();

	getline(cin, data);

	MHeap.Insert(priority, data);

	return MHeap;
}
