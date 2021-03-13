// 1411
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[100001];

int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i] + dp[i - 1]) % 20100529;
		dp[i] = (dp[i] + dp[i - 2]) % 20100529;
		dp[i] = (dp[i] + dp[i - 2]) % 20100529;
	}

	printf("%d\n", dp[n]);

	return 0;
}