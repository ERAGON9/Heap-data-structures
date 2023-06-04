
#include <iostream>
#include "MaxHeap.h"
#include "HelpFunctions.h"

using namespace std;

#define MAX_DATA_HEAP_SIZE 100
#define FIRST_PLACE_AT_HEAP 0

MaxHeap::MaxHeap()
{
	maxSize = MAX_DATA_HEAP_SIZE;
	heapSize = 0;
	allocated = true;
}

MaxHeap::~MaxHeap()
{}

int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MaxHeap::Left(int node)
{
	return ((node * 2) + 1);
}

int MaxHeap::Right(int node)
{
	return ((node * 2) + 2);
}

void MaxHeap::FixHeap(int node) // Fixes the heap that has node as root.
{
	int max = node, left = Left(node), right = Right(node);

	if ((left < heapSize) && (data[left].priority > data[node].priority))
	{ 
		max = left;
	}

	if ((right < heapSize) && (data[right].priority > data[max].priority))
	{
		max = right;
	}

	if (max != node)
	{
		Swap(data, node, max);
		FixHeap(max);
	}
}

Pair MaxHeap::Max()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	return data[FIRST_PLACE_AT_HEAP];
}

Pair MaxHeap::DeleteMax()
{
	if (heapSize == 0)
	{
		cout << "wrong input";
		exit(1);
	}

	Swap(data, FIRST_PLACE_AT_HEAP, (heapSize - 1));

	Pair max = data[(heapSize - 1)];
	max.index_AT_Heap = -1;             // Out of heap => index = -1.
	if (max.clonePair != nullptr)       // Update for the clone the pointer to this pair.
		max.clonePair->clonePair = &max;

	heapSize--;

	FixHeap(FIRST_PLACE_AT_HEAP);

	return max;
}

void MaxHeap::Insert(Pair item)
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
	if (data[heapSize].clonePair != nullptr)            // Update for the clone the pointer to this pair.
		data[heapSize].clonePair->clonePair = &(data[heapSize]);

	int index = heapSize;
	
	while ((index > FIRST_PLACE_AT_HEAP) && (data[index].priority > data[Parent(index)].priority)) // Fix the heap from sown to up.
	{
		Swap(data, index, Parent(index));
		index = Parent(index);
	}

	heapSize++;

}

Pair MaxHeap::Delete(int index)
{
	Pair deleted;

	if (heapSize <= index)
	{
		cout << "wrong input";
		exit(1);
	}

	if (index == 0)  // Delete the first pair.
	{
		deleted = DeleteMax();
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

		heapSize--;

		if (data[index].priority < data[Parent(index)].priority)   // Fix the heap from index down.
		{
			FixHeap(index);
		}
		else // data[index].priority > data[Parent(index)].priority
		{
			while ((index > 0) && (data[index].priority > data[Parent(index)].priority)) // Fix the heap from index to up.
			{
				Swap(data, index, Parent(index));
			}
		}
	}

	return deleted;
}