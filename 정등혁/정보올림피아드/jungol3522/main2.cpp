// 3521
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int targetWeight = 0;
int weightCount[6];

int main()
{
	int weight = 16;
	scanf("%d %d %d %d %d %d",
		&weightCount[1],
		&weightCount[2],
		&weightCount[3],
		&weightCount[4],
		&weightCount[5],
		&targetWeight);
	
	int ans = 0;
	for (int i = 5; i > 0; i--)
	{
		while (weightCount[i] > 0)
		{
			if (targetWeight - weight < 0)
			{
				break;
			}

			targetWeight -= weight;
			ans++;

			if (targetWeight == 0)
			{
				printf("%d\n", ans);
				return 0;
			}
			weightCount[i]--;
		}

		weight /= 2;
	}

	printf("impossible\n");

	return 0;
}