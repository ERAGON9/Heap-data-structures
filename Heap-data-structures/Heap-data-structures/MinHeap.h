#pragma once

#include "Pair.h"


class MinHeap
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
	MinHeap(int max);
	~MinHeap();
	Pair Min();
	Pair DeleteMin();
	void Insert(Pair item);
};