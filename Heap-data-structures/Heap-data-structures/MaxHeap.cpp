
#include <iostream>
#include "MaxHeap.h"

using namespace std;

MaxHeap::MaxHeap(int max)
{
	data = new Pair[max];
	maxSize = max;
	heapSize = 0;
	allocated = true;
}

MaxHeap::~MaxHeap()
{
	if (allocated)
	{
		delete[] data;
	}
	data = NULL;
}

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

void Swap(Pair* arr, int index1, int index2)
{
	Pair temp = arr[index1];

	arr[index1] = arr[index2];
	arr[index2] = arr[index1];
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

Pair MaxHeap::DeleteMax()
{
	if (heapSize)
	{
		cout << "wrong input";
		exit(1);
	}

	Pair max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);

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
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = item;
}
