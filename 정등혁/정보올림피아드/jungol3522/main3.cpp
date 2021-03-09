// 3522
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long dp[100001];

int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}

	printf("%lld\n", dp[n]);

	return 0;
}