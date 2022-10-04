#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> number;
queue<char> op;
int main()
{
	string str;
	cin >> str;
	int strsize = str.size();
	int start = 0;
	for (int i = 0; i <= strsize; i++)
	{
		switch (str[i])
		{
		case '-':
		case '+':
			op.push(str[i]);
		case '\0':
			number.push_back(stoi(str.substr(start, i)));
			start = i+1;
			break;
		}
	}
	int sum = number[0];
	char temp_op = ' ';
	bool flag = false;
	for (int i = 1; i < number.size(); i++)
	{
		temp_op = op.front();
		op.pop();
		if (temp_op == '-') flag = true;
		if (flag)
		{
			sum -= number[i];
		}
		else
		{
			sum += number[i];
		}
	}
	cout << sum << '\n';
}