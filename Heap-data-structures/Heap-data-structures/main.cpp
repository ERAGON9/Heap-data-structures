#include <iostream>

using namespace std;

#define MAX_HEAP_SIZE 100
enum { MAX='a', DELETE_MAX, MIN, DELET_EMIN, CREATE_EMPTY, INSERT, MEDIAN };

int main()
{
	int n;
	char func;

	cin >> n;

	if (n <= 0)
	{
		cout << "wrong input";
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> func;
		if (func > 'g' || func < 'a')
		{
			cout << "wrong input";
			exit(1);
		}
		switch (func)
		{
			case MAX:
				break;
			case DELETE_MAX:
				break;
			case MIN:
				break;
			case DELET_EMIN:
				break;
			case CREATE_EMPTY:
				break;
			case INSERT:
				break;
			case MEDIAN:
				break;
		}
	}
}





