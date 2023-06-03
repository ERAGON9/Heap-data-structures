#pragma once

#include "Pair.h"

#define MAX_DATA_HEAP_SIZE 100

class MinHeap
{
private:
	Pair data[MAX_DATA_HEAP_SIZE];    // Points to data array.
	int maxSize;   // Max size of heap.
	int heapSize;  // Current size of heap.
	bool allocated; // if heap allocated memory

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);

public:
	MinHeap();
	~MinHeap();
	Pair Min();
	Pair DeleteMin();
	void Insert(Pair item);

	Pair Delete(int index);
};