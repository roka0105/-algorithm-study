#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
#define MAX 8

int arr[MAX];
vector<int> temp;
int N = 0, M = 0;
void NxM(int num, int depth)
{
	if (depth == 0||depth>MAX)
	{
		for (int number : temp)
		{
			cout << number << ' ';
		}
		cout << '\n';
		return;
	}
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		for (int item : temp)
		{
			if (arr[i] == item)
				flag = true;
		}
		if (flag == true)
		{
			flag = false;
			continue;
		}
		temp.push_back(arr[i]);

		NxM(arr[i], depth - 1);
		if (temp.empty() == false)
			temp.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}
	
	NxM(0, M);
}