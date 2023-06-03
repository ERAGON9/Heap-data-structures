
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

	Pair max = data[FIRST_PLACE_AT_HEAP];
	heapSize--;
	data[heapSize].index_AT_Heap = FIRST_PLACE_AT_HEAP;
	data[FIRST_PLACE_AT_HEAP] = data[heapSize];
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

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].priority < item.priority))
	{
		data[Parent(i)].index_AT_Heap = i;
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	item.index_AT_Heap = i;
	data[i] = item;
}

Pair MaxHeap::Delete(int index)
{
	if (heapSize <= index)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair deleted = data[index];
	heapSize--;
	data[heapSize].index_AT_Heap = index;
	data[index] = data[heapSize];

	if (index == 0)
	{
		FixHeap(FIRST_PLACE_AT_HEAP);
	}
	else
	{
		if (data[Parent(index)].priority >= data[index].priority)
		{
			FixHeap(index);
		}
		else // data[Parent(index)].priority < data[index].priority
		{
			while ((index != 0) && (data[Parent(index)].priority < data[index].priority))
			{
				Swap(data, Parent(index), index);
			}
		}
	}
	return deleted;
}