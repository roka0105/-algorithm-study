#include <iostream>
#include <vector>
#define MAX 12
#define COMMAX 6
using namespace std;
int lotto[MAX];
int combi[COMMAX];
int k = -1;
void GetCombi(int _index, int _depth)
{
	if (_depth == COMMAX)
	{
		for (int i = 0; i < COMMAX; i++)
		{
			printf("%d ", combi[i]);
		}
		printf("\n");
		return;
	}

	for (int i = _index; i < k; i++)
	{
		combi[_depth] = lotto[i];
		GetCombi(i+1, _depth + 1);
	}
}
int main()
{


	while (k != 0)
	{
		cin >> k;
		if (k <= 6 || k >= 13)
			continue;

		for (int i = 0; i < k; i++)
		{
			do
			{
				cin >> lotto[i];
			} while (lotto[i] <= 0 && lotto[i] > 49);
		}
		GetCombi(0, 0);
		printf("\n");
	}
	
}