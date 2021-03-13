// 1816
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int m, s, c;

int cows[201];
int diff[201];

int main()
{
	scanf("%d %d %d", &m, &s, &c);

	for(int i = 0; i < c; i++)
	{
		scanf("%d", &cows[i]);
	}

	sort(cows, cows + c);

	int width = cows[c - 1] - cows[0] + 1;

	for (int i = 0; i < c - 1; i++)
	{
		diff[i] = cows[i + 1] - (cows[i] + 1);
	}
	sort(diff, diff + c, greater<>());

	int gap = 0;
	for (int i = 0; i < m - 1; i++)
	{
		gap += diff[i];
	}

	printf("%d\n", width - gap);

	return 0;
}