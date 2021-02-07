// 정보올림피아 문제 2000

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n;
int coin[10];
int jandon;

int dp[64001];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
		dp[coin[i]] = 1;
	}

	scanf("%d", &jandon);


	for (int i = 1; i <= jandon; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int prevIdx = i - coin[j];
			if (prevIdx <= 0)
			{
				continue;
			}

			if (dp[prevIdx] != 0 && (dp[i] == 0 || dp[prevIdx] + 1 < dp[i]))
			{				
				dp[i] = dp[prevIdx] + 1;
			}
		}
	}

	if (dp[jandon] != 0)
		printf("%d\n", dp[jandon]);
	else
		printf("impossible\n");
	
	return 0;
}