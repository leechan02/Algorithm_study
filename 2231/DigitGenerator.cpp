#include <iostream>

int main()
{
	int N;
	int i;
	int result = 0;

	std::cin >> N;

	for (i = 1; i <= N; i++)
	{
		result = i;
		for (int tmp = i; tmp > 0; tmp /= 10)
		{
			result += tmp % 10;
		}
		if (result == N)
		{
			result = i;
			break ;
		}
	}
	if (i > N)
	{
		result = 0;
	}
	std::cout << result;
	return 0;
}