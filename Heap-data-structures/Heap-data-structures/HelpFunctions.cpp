
#include <iostream>
#include "HelpFunctions.h"
#include "Pair.h"

using namespace std;

enum { MAX = 'a', DELETE_MAX, MIN, DELETE_MIN, CREATE_EMPTY, INSERT, MEDIAN };

#define FIRST_OPERATION 'a'
#define LAST_OPERATION 'g'

void Swap(Pair* heapArr, int index1, int index2)
{
	Pair temp = heapArr[index1];

	heapArr[index1] = heapArr[index2];
	heapArr[index1].index_AT_Heap = index1;

	heapArr[index2] = temp;
	heapArr[index2].index_AT_Heap = index2;

	if (heapArr[index1].clonePair != nullptr)
		heapArr[index1].clonePair->clonePair = &(heapArr[index1]);

	if (heapArr[index2].clonePair != nullptr)
		heapArr[index2].clonePair->clonePair = &(heapArr[index2]);

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

void notEmptySentenceValidation(char action)
{
	if (action == '\n')
	{
		cout << "wrong input";
		exit(1);
	}
}

void EndSentenceValidation()
{
	string data;

	getline(cin, data);

	if (data != "\n")
	{
		cout << "wrong input";
		exit(1);
	}
}

HeapMedian Insert_Validation(HeapMedian MHeap)
{
	string numberAsString, data;
	int priority;

	checkSpaceValidation();

	cin >> numberAsString;
	for (char ch : numberAsString)
	{
		if (ch == numberAsString[0])
		{
			if ((ch != '-') && (ch < '0' || ch > '9'))
			{
				cout << "wrong input";
				exit(1);
			}
		}
		else if (ch < '0' || ch > '9')  //ch != numberAsString[0]
		{
			cout << "wrong input";
			exit(1);
		}
	}
	priority = stoi(numberAsString);

	checkSpaceValidation();

	getline(cin, data);

	MHeap.Insert(priority, data);

	return MHeap;
}

void checkSpaceValidation()
{
	char space = getchar(); // for the  space (" ").

	if (space != ' ')
	{
		cout << "wrong input";
		exit(1);
	}
}
