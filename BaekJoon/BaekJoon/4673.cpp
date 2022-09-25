#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000
vector<int> nonself;
void d(int num, int& sum)
{
	if (num == 0)
		return;
	sum += num % 10;
	d(num / 10, sum);
}
int main()
{
	bool check[MAX + 1] = { false, };
	int sum = 0;
	for (int i = 1; i <= MAX; i++)
	{
		sum = i;
		d(i, sum);
		if (sum < MAX + 1)
		{
			check[sum] = true;
		}
		//nonself.push_back(sum);
	}
	for (int i = 1; i <= MAX; i++)
	{
		if (check[i] == false)
		{
			cout << i << endl;
		}
		/*bool flag = false;
		for (int non : nonself)
		{
			if (non == i)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << i << endl;
		}*/
	}
}