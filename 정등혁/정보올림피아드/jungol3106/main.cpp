// 정보올림파이드 3106번
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int a;
char b[255];
int c;

int main()
{
	while (1)
	{
		scanf("%d", &a);
		if (a == 0)
			return 0;

		scanf("%s %d", b, &c);

		long long tenNum = 0;
		{
			long long maxLen = 0;
			for (int i = 0; b[i] != '\0'; i++)
			{
				maxLen = i+1;
			}
			long long jalitsu = 1;
			
			for (int i = maxLen - 1; i >= 0; i--)
			{
				if ('A' <= b[i] && b[i] <= 'Z')
				{

					tenNum += (b[i] + 10 - 'A') * jalitsu;
				}
				else if ('a' <= b[i] && b[i] <= 'z')
				{
					tenNum += (b[i] - 'a') * jalitsu;
				}
				else
				{
					tenNum += (b[i] - '0') * jalitsu;
				}
				jalitsu *= a;
			}
		}

		if (tenNum == 0)
		{
			printf("%d\n", tenNum);
			continue;
		}

		char ans[256];
		{
			int revAns[256];
			int lastIdx = 0;
			for (int i = 0; tenNum > 0; i++)
			{
				revAns[i] = tenNum % c;
				tenNum = tenNum / c;
				lastIdx = i;
			}

			for (int i = lastIdx; i >= 0; i--)
			{
				int idx = lastIdx - i;
				if (revAns[i] >= 10)
				{
					ans[idx] = revAns[i] - 10 + 'A';
				}
				else
				{
					ans[idx] = revAns[i] + '0';
				}
			}
			ans[lastIdx + 1] = '\0';
		}

		printf("%s\n", ans);
	}
	return 0;
}