#include <iostream>
using namespace std;
#define NMAX 100

int main()
{
	int max = 0;
	int arr[NMAX];
	int N = 0, M = 0;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int n1 = 0, n2 = 0, n3 = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		n1 = arr[i];
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			n2 = arr[j];
			for (int k = 0; k < N; k++)
			{
				if (j == k || i == k)
					continue;
				n3 = arr[k];
				sum = n1 + n2 + n3;
				if (M >= sum && max < sum)
					max = sum;
			}
		}
	}
	cout << max << endl;
}