#pragma once

#include "MaxHeap.h"
#include "MinHeap.h"

class HeapMedian
{
private:
	MaxHeap H1_Max, H2_Max; // H1 = the smallest half , H2 = the biggest half.
	MinHeap H1_Min, H2_Min;
	int maxSize;            // Max size of heap.
	int heapSize;           // Current size of heap.

public:
	HeapMedian();
	~HeapMedian();

	void Max();
	void DeleteMax();
	void Min();
	void DeleteMin();
	void Insert(int priority, string value);
	void Median();
};