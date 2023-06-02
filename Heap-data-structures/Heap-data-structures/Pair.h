#pragma once

#include <string>
using namespace std;


class Pair
{
public:
	int priority;
	string data;

	Pair()
	{}

	Pair(int priority, string data)
	{
		this->priority = priority;
		this->data = data;
	}
};