#include <iostream>

void HanoiGame(int number, int start, int to, int bypass)
{
	if (number == 1)
	{
		printf("%d %d\n", start, to);
	}
	else
	{
		HanoiGame(number - 1, start,bypass,to);
		printf("%d %d\n", start, to);
		HanoiGame(number - 1, bypass, to, start);
	}
}
int main()
{
	int block_count = 0;
	std::cin >> block_count;
	std::cout << (1 << block_count) - 1 << std::endl;
	HanoiGame(block_count, 1, 3, 2);
}