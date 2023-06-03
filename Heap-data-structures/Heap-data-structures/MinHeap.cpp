
#include <iostream>
#include "MinHeap.h"
#include "HelpFunctions.h"

using namespace std;

#define FIRST_PLACE_AT_HEAP 0

MinHeap::MinHeap(int max)
{
	data = new Pair[max];
	maxSize = max;
	heapSize = 0;
	allocated = true;
}

MinHeap::~MinHeap()
{
	if (allocated)
	{
		delete[] data;
	}
	data = NULL;
}

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

	return data[0];
}

Pair MinHeap::DeleteMin()
{
	if (heapSize)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair min = data[FIRST_PLACE_AT_HEAP];
	heapSize--;
	data[heapSize].index_AT_Heap = FIRST_PLACE_AT_HEAP;
	data[FIRST_PLACE_AT_HEAP] = data[heapSize];
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

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].priority > item.priority))
	{
		data[Parent(i)].index_AT_Heap = i;
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	item.index_AT_Heap = i;
	data[i] = item;
}

Pair MinHeap::Delete(int index)
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
		if (data[Parent(index)].priority <= data[index].priority)
		{
			FixHeap(index);
		}
		else // data[Parent(index)].priority > data[index].priority
		{
			while ((index != 0) && (data[Parent(index)].priority > data[index].priority))
			{
				Swap(data, Parent(index), index);
			}
		}
	}
	return deleted;
}