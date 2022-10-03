#include <iostream>
#include <vector>
using namespace std;
#define MAX 21
vector<int> person[MAX];
int N = 0;
int main()
{
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			person[i].push_back(num);
		}
	}


}