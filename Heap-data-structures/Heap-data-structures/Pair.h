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
	{}

	Pair(int priority, string data)
	{
		this->priority = priority;
		this->data = data;
	}

	Pair(int priority, string data, Pair* clonePair)
	{
		this->priority = priority;
		this->data = data;
		this->clonePair = clonePair;
	}
};