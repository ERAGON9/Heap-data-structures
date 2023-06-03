#pragma once

#include "Pair.h"

class MaxHeap
{
private:
	Pair* data;    // Points to data array.
	int maxSize;   // Max size of heap.
	int heapSize;  // Current size of heap.
	bool allocated; // if heap allocated memory

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	MaxHeap(int max);
	~MaxHeap();
	Pair Max();
	Pair DeleteMax();
	void Insert(Pair item);

	Pair Delete(int index);
	int getHeapSize() { return heapSize; }
};