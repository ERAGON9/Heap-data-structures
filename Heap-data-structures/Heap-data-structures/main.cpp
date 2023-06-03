
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Functions.h"

using namespace std;

enum { MAX='a', DELETE_MAX, MIN, DELET_EMIN, CREATE_EMPTY, INSERT, MEDIAN };

#define FIRST_OPERATION 'a'
#define LAST_OPERATION 'g'

int main()
{
	MaxHeap* H1_Max, *H2_Max; // H1 = the smallest half , H2 = the biggest half.
	MinHeap* H1_Min, *H2_Min;

	int n;
	char func;
	bool is_Memory_Allocated = false;

	cin >> n;

	if (n <= 0)
	{
		cout << "wrong input";
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> func;

		if (i == 0 && func == CREATE_EMPTY)
		{
			is_Memory_Allocated = true;
		}
		else if ( (i != 0 && func == CREATE_EMPTY) || (i == 0 && func != CREATE_EMPTY)) // CREATE_EMPTY check
		{
			cout << "wrong input";
			exit(1);
		}
		if (func < FIRST_OPERATION || func > LAST_OPERATION)
		{
			cout << "wrong input";
			exit(1);
		}

		switch (func)
		{
			case MAX:
				break;
			case DELETE_MAX:
				break;
			case MIN:
				break;
			case DELET_EMIN:
				break;
			case CREATE_EMPTY:
				break;
			case INSERT:
				break;
			case MEDIAN:
				break;
		}
	}

	if (is_Memory_Allocated)
	{
		delete H1_Max;
		delete H1_Min;
		delete H2_Max;
		delete H2_Min;
	}

}





