
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

using namespace std;

#define MAX_DATA_HEAP_SIZE 100
#define MAX_MEDIAN_HEAP_SIZE 200

HeapMedian::HeapMedian():H1_Max(MAX_DATA_HEAP_SIZE), H1_Min(MAX_DATA_HEAP_SIZE), H2_Max(MAX_DATA_HEAP_SIZE), H2_Min(MAX_DATA_HEAP_SIZE)
{
	maxSize = MAX_MEDIAN_HEAP_SIZE;
	heapSize = 0;
}

HeapMedian::~HeapMedian()
{}

void HeapMedian::Max()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	cout << H2_Max.Max().priority << " " << H2_Max.Max().data;
}

void HeapMedian::DeleteMax()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair max = H2_Max.DeleteMax();
	Pair clonemax = H2_Min.Delete(max.clonePair->index_AT_Heap);

	if (H1_Max.getHeapSize() > (H2_Max.getHeapSize() + 1))
	{
		Pair maxSmallest = H1_Max.DeleteMax();
		Pair cloneMaxSmallest = H1_Min.Delete(maxSmallest.clonePair->index_AT_Heap);

		H2_Max.Insert(maxSmallest);
		H2_Min.Insert(cloneMaxSmallest);
	}

	cout << max.priority << " " << max.data;
}

void HeapMedian::Min()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	cout << H1_Min.Min().priority << " " << H1_Min.Min().data;
}

void HeapMedian::DeleteMin()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair cloneMin = H1_Min.DeleteMin();
	Pair min = H1_Max.Delete(cloneMin.clonePair->index_AT_Heap);

	if (H2_Max.getHeapSize() > H1_Max.getHeapSize())
	{
		Pair cloneMinBiggest = H2_Min.DeleteMin();
		Pair minBiggest = H2_Max.Delete(cloneMinBiggest.clonePair->index_AT_Heap);

		H1_Max.Insert(minBiggest);
		H1_Min.Insert(cloneMinBiggest);
	}

	cout << min.priority << " " << min.data;
}

void HeapMedian::Insert(int priority, string value)
{
	Pair newPair = Pair(priority, value);
	Pair clonePair = Pair(priority, value, &newPair);
	newPair.clonePair = &clonePair;

	if (heapSize == 0)
	{
		H1_Max.Insert(newPair);
		H1_Min.Insert(clonePair);
	}
	else
	{
		if (newPair.priority > H1_Max.Max().priority)
		{
			H2_Max.Insert(newPair);
			H2_Min.Insert(clonePair);

			if (H2_Max.getHeapSize() > H1_Max.getHeapSize())
			{
				Pair cloneMinBiggest = H2_Min.DeleteMin();
				Pair minBiggest = H2_Max.Delete(cloneMinBiggest.clonePair->index_AT_Heap);

				H1_Max.Insert(minBiggest);
				H1_Min.Insert(cloneMinBiggest);
			}
		}
		else  // newPair.priority <= H1_Max->Max().priority
		{
			H1_Max.Insert(newPair);
			H1_Min.Insert(clonePair);

			if (H1_Max.getHeapSize() > (H2_Max.getHeapSize() + 1))
			{
				Pair maxSmallest = H1_Max.DeleteMax();
				Pair cloneMaxSmallest = H1_Min.Delete(maxSmallest.clonePair->index_AT_Heap);

				H2_Max.Insert(maxSmallest);
				H2_Min.Insert(cloneMaxSmallest);
			}
		}
	}

	heapSize++;
}

void HeapMedian::Median()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	cout << H1_Max.Max().priority << " " << H1_Max.Max().data;
}