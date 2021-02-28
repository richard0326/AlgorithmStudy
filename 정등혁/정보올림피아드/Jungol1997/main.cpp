// 정보올림피아드 1997
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dp[31];

int main()
{
	int d, k;
	scanf("%d %d", &d, &k);

	for (int a = 1; a <= k; a++)
	{
		for (int b = a; b <= k; b++)
		{
			int prevDay = a;
			int nowDay = b;

			for (int i = 3; i <= d; i++)
			{
				int g = prevDay + nowDay;
				if (i == d && g == k)
				{
					printf("%d\n%d\n", a, b);
					return 0;
				}

				if (g >= k)
				{
					break;
				}

				prevDay = nowDay;
				nowDay = g;
			}
		}
	}

	return 0;
}