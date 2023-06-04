#pragma once

#include <string>

using namespace std;

class Pair
{
public:
	int priority;
	string data;
	Pair* clonePair;
	int index_AT_Heap;

	Pair()
	{
		priority = 0;
		data = "";
		clonePair = nullptr;
		index_AT_Heap = -1;
	}

	Pair(int priority, string data)
	{
		this->priority = priority;
		this->data = data;
		this->clonePair = nullptr;
		index_AT_Heap = -1;
	}

	Pair(int priority, string data, Pair* clonePair)
	{
		this->priority = priority;
		this->data = data;
		this->clonePair = clonePair;
		index_AT_Heap = -1;
	}
};