#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int T = 0;


int main()
{
	cin >> T;
	int n = 0, m = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;
		int s = 0, e = 0;


		for (int j = 0; j < m; j++)
		{
			cin >> s >> e;
		}
        cout << n - 1 << '\n';
	}
}