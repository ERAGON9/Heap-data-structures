
#include <iostream>
#include "Functions.h"
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;

#define MAX_HEAP_SIZE 100

void Max(MaxHeap* H2_Max)
{
	cout << H2_Max->Max().priority << " " << H2_Max->Max().data;
}

void DeleteMax()
{

}

void Min(MinHeap* H1_Min)
{
	cout << H1_Min->Min().priority << " " << H1_Min->Min().data;
}

void DeleteMin()
{

}

void CreateEmpty(MaxHeap* H1_Max, MinHeap* H1_Min, MaxHeap* H2_Max, MinHeap* H2_Min)
{
	H1_Max = new MaxHeap(MAX_HEAP_SIZE);
	H1_Min = new MinHeap(MAX_HEAP_SIZE);
	H2_Max = new MaxHeap(MAX_HEAP_SIZE);
	H2_Min = new MinHeap(MAX_HEAP_SIZE);
}

void Insert(int priority, string value, MaxHeap* H1_Max, MinHeap* H1_Min, MaxHeap* H2_Max, MinHeap* H2_Min)
{
	Pair newPair = Pair(priority, value);
	Pair clonePair = Pair(priority, value, &newPair);
	newPair.clonePair = &clonePair;

	if (priority > H1_Max->Max().priority)
	{
		H2_Max->Insert(newPair);
		H2_Min->Insert(clonePair);

		if (H2_Max->getHeapSize() > H1_Max->getHeapSize())
		{
			Pair cloneMinBiggest = H2_Min->DeleteMin();
			Pair minBiggest = H2_Max->Delete(cloneMinBiggest.clonePair->index_AT_Heap);

			H1_Max->Insert(minBiggest);
			H1_Min->Insert(cloneMinBiggest);
		}
	}
	else
	{
		H1_Max->Insert(newPair);
		H1_Min->Insert(clonePair);

		if (H1_Max->getHeapSize() > (H2_Max->getHeapSize() + 1))
		{
			Pair maxSmallest = H1_Max->DeleteMax();
			Pair cloneMaxSmallest = H1_Min->Delete(maxSmallest.clonePair->index_AT_Heap);

			H2_Max->Insert(maxSmallest);
			H2_Min->Insert(cloneMaxSmallest);
		}
	}
}

void Median(MaxHeap* H1_Max)
{
	cout << H1_Max->Max().priority << " " << H1_Max->Max().data;
}


void Swap(Pair* arr, int index1, int index2)
{
	Pair temp = arr[index1];

	arr[index2].index_AT_Heap = index1;
	arr[index1] = arr[index2];

	arr[index1].index_AT_Heap = index2;
	arr[index2] = arr[index1];
}

