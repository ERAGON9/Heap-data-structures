
#include <iostream>
#include <string>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
#include "HelpFunctions.h"

using namespace std;

enum { MAX='a', DELETE_MAX, MIN, DELETE_MIN, CREATE_EMPTY, INSERT, MEDIAN };

int main()
{
	HeapMedian MHeap;
	int n;
	char action;

	cin >> n;
	nValidation(n);

	for (int i = 0; i < n; i++)
	{
		cin >> action;
		actionValidation(action);

		eValidation(i, action);

		switch (action)
		{
			case MAX:
				MHeap.Max();
				break;

			case DELETE_MAX:
				MHeap.DeleteMax();
				break;

			case MIN:
				MHeap.Min();
				break;

			case DELETE_MIN:
				MHeap.DeleteMin();
				break;

			case CREATE_EMPTY:
				MHeap = HeapMedian();
				break;

			case INSERT:
				MHeap = Insert_Validation(MHeap);
				break;

			case MEDIAN:
				MHeap.Median();
				break;
		}
	}

}

