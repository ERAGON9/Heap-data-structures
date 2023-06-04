
#include <iostream>
#include "MinHeap.h"
#include "HelpFunctions.h"

using namespace std;

#define MAX_DATA_HEAP_SIZE 100
#define FIRST_PLACE_AT_HEAP 0

MinHeap::MinHeap()
{
	maxSize = MAX_DATA_HEAP_SIZE;
	heapSize = 0;
	allocated = true;
}

MinHeap::~MinHeap()
{}

int MinHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MinHeap::Left(int node)
{
	return ((node * 2) + 1);
}

int MinHeap::Right(int node)
{
	return ((node * 2) + 2);
}

void MinHeap::FixHeap(int node) // Fixes the heap that has node as root.
{
	int min = node, left = Left(node), right = Right(node);

	if ((left < heapSize) && (data[left].priority < data[node].priority))
	{
		min = left;
	}

	if ((right < heapSize) && (data[right].priority < data[min].priority))
	{
		min = right;
	}

	if (min != node)
	{
		Swap(data, node, min);
		FixHeap(min);
	}
}

Pair MinHeap::Min()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	return data[FIRST_PLACE_AT_HEAP];
}

Pair MinHeap::DeleteMin()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	Swap(data, FIRST_PLACE_AT_HEAP, (heapSize - 1));

	Pair min = data[(heapSize - 1)];
	min.index_AT_Heap = -1;              // out of heap => index = -1.
	if (min.clonePair != nullptr)        // Update for the clone the pointer to this pair.
		min.clonePair->clonePair = &min;

	heapSize--;

	FixHeap(FIRST_PLACE_AT_HEAP);

	return min;
}

void MinHeap::Insert(Pair item)
{
	if (heapSize == maxSize)
	{
		cout << "wrong input";
		exit(1);
	}

	if (item.clonePair != nullptr)                       // Update clone pointer.
		item.clonePair->clonePair = &item;

	data[heapSize] = item;                               // Insert.
	data[heapSize].index_AT_Heap = heapSize;
	if (data[heapSize].clonePair != nullptr)             // Update for the clone the pointer to this pair.
		data[heapSize].clonePair->clonePair = &(data[heapSize]);

	int index = heapSize;

	while ((index > FIRST_PLACE_AT_HEAP) && (data[index].priority < data[Parent(index)].priority)) // Fix the heap from sown to up.
	{
		Swap(data, index, Parent(index));
		index = Parent(index);
	}

	heapSize++;

}

Pair MinHeap::Delete(int index)
{
	Pair deleted;

	if (heapSize <= index)
	{
		cout << "wrong input";
		exit(1);
	}

	if (index == 0)  // Delete the first pair.
	{
		deleted = DeleteMin();
		if (deleted.clonePair != nullptr)             // Update for the clone the pointer to this pair.
			deleted.clonePair->clonePair = &deleted;
	}
	else            // Delete middle pair.
	{

		Swap(data, index, (heapSize - 1));

		deleted = data[heapSize - 1];
		deleted.index_AT_Heap = -1;                  // Out of heap => index = -1.
		if (deleted.clonePair != nullptr)            // Update for the clone the pointer to this pair.
			deleted.clonePair->clonePair = &deleted;

		if (data[index].priority > data[Parent(index)].priority)   // Fix the heap from index down.
		{
			FixHeap(index);
		}
		else // data[index].priority < data[Parent(index)].priority
		{
			while ((index > 0) && (data[index].priority < data[Parent(index)].priority)) // Fix the heap from index to up.
			{
				Swap(data, index, Parent(index));
			}
		}
	}

	return deleted;
}