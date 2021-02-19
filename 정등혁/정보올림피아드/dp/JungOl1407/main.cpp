// 1407¹ø
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[41];
char input[41];

int main()
{
	scanf("%s", input);

	dp[0] = 1;
	dp[1] = 1;

	int prevInt = input[0] - '0';
	int lastIdx = 0;
	for (int i = 1; input[i] != '\0'; i++)
	{
		int nowInt = input[i] - '0';
		int sumInt = prevInt * 10 + nowInt;

		if (9 < sumInt && sumInt <= 34)
		{
			dp[i + 1] += dp[i - 1];
		}

		if (nowInt != 0)
		{
			dp[i + 1] += dp[i];
		}
		prevInt = nowInt;
		lastIdx = i + 1;
	}

	printf("%d\n", dp[lastIdx]);

	return 0;
}