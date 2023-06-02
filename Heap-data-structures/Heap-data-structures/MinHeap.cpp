
#include <iostream>
#include "MinHeap.h"

using namespace std;

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

void Swap(Pair* arr, int index1, int index2)
{
	Pair temp = arr[index1];

	arr[index1] = arr[index2];
	arr[index2] = arr[index1];
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

Pair MinHeap::DeleteMin()
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
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = item;
}
