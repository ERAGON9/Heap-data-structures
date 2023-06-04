
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

using namespace std;


#define MAX_MEDIAN_HEAP_SIZE 200

HeapMedian::HeapMedian()
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

	cout << H2_Max.Max().priority << " " << H2_Max.Max().data << endl;
}

void HeapMedian::DeleteMax()
{
	Pair max, clonemax;

	if (heapSize == 0) // Heap is empty.
	{
		cout << "wrong input";
		exit(1);
	}

	if (H2_Max.getHeapSize() > 0) // max heap not empty. (will be empty just if there is 0 or 1 pairs in the median heap!)
	{
		max = H2_Max.DeleteMax();
		if (max.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			max.clonePair->clonePair = &max;

		clonemax = H2_Min.Delete(max.clonePair->index_AT_Heap);
		if (clonemax.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			clonemax.clonePair->clonePair = &clonemax;

		if (H1_Max.getHeapSize() > (H2_Max.getHeapSize() + 1))
		{
			Pair maxSmallest = H1_Max.DeleteMax();
			if (maxSmallest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
				maxSmallest.clonePair->clonePair = &maxSmallest;

			Pair cloneMaxSmallest = H1_Min.Delete(maxSmallest.clonePair->index_AT_Heap);
			if (cloneMaxSmallest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
				cloneMaxSmallest.clonePair->clonePair = &cloneMaxSmallest;

			H2_Max.Insert(maxSmallest);
			H2_Min.Insert(cloneMaxSmallest);
		}
	}
	else // H1_Max.getHeapSize() == 1 
	{
		clonemax = H1_Min.DeleteMin();
		if (clonemax.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			clonemax.clonePair->clonePair = &clonemax;

		max = H1_Max.Delete(max.clonePair->index_AT_Heap);
		if (max.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			max.clonePair->clonePair = &max;
	}

	heapSize--;
	cout << max.priority << " " << max.data << endl;
}

void HeapMedian::Min()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	cout << H1_Min.Min().priority << " " << H1_Min.Min().data << endl;
}

void HeapMedian::DeleteMin()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair cloneMin = H1_Min.DeleteMin();
	if (cloneMin.clonePair != nullptr)            // Update for the clone the pointer to this pair.
		cloneMin.clonePair->clonePair = &cloneMin;

	Pair min = H1_Max.Delete(cloneMin.clonePair->index_AT_Heap);
	if (min.clonePair != nullptr)            // Update for the clone the pointer to this pair.
		min.clonePair->clonePair = &min;

	if (H2_Max.getHeapSize() > H1_Max.getHeapSize())
	{
		Pair cloneMinBiggest = H2_Min.DeleteMin();
		if (cloneMinBiggest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			cloneMinBiggest.clonePair->clonePair = &cloneMinBiggest;

		Pair minBiggest = H2_Max.Delete(cloneMinBiggest.clonePair->index_AT_Heap);
		if (minBiggest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			minBiggest.clonePair->clonePair = &minBiggest;

		H1_Max.Insert(minBiggest);
		H1_Min.Insert(cloneMinBiggest);
	}

	heapSize--;
	cout << min.priority << " " << min.data << endl;
}

void HeapMedian::Insert(int priority, string value)
{
	Pair newPair = Pair(priority, value);
	Pair clonePair = Pair(priority, value, &newPair);
	newPair.clonePair = &clonePair;

	if (heapSize == 0)    // Insert pair to Empty heap.
	{
		H1_Max.Insert(newPair);
		H1_Min.Insert(clonePair);
	}
	else                  // Insert pair to Heap with data(pairs).
	{
		if (newPair.priority > H1_Max.Max().priority)  // newPair.priority > median priority.
		{
			H2_Max.Insert(newPair);
			H2_Min.Insert(clonePair);

			if (H2_Max.getHeapSize() > H1_Max.getHeapSize())
			{
				Pair cloneMinBiggest = H2_Min.DeleteMin();
				if (cloneMinBiggest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
					cloneMinBiggest.clonePair->clonePair = &cloneMinBiggest;

				Pair minBiggest = H2_Max.Delete(cloneMinBiggest.clonePair->index_AT_Heap);
				if (minBiggest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
					minBiggest.clonePair->clonePair = &minBiggest;

				H1_Max.Insert(minBiggest);
				H1_Min.Insert(cloneMinBiggest);
			}
		}
		else  // newPair.priority <= H1_Max->Max().priority (<= median priority)
		{
			H1_Max.Insert(newPair);
			H1_Min.Insert(clonePair);

			if (H1_Max.getHeapSize() > (H2_Max.getHeapSize() + 1))
			{
				Pair maxSmallest = H1_Max.DeleteMax();
				if (maxSmallest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
					maxSmallest.clonePair->clonePair = &maxSmallest;

				Pair cloneMaxSmallest = H1_Min.Delete(maxSmallest.clonePair->index_AT_Heap);
				if (maxSmallest.clonePair != nullptr)            // Update for the clone the pointer to this pair.
					maxSmallest.clonePair->clonePair = &maxSmallest;

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

	cout << H1_Max.Max().priority << " " << H1_Max.Max().data << endl;
}