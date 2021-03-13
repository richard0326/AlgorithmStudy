// 1082
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int height, width;
char map[51][51];
bool check[51][51];

int fx[] = { -1, 1, 0, 0 };
int fy[] = { 0, 0, -1, 1 };

int bfs(queue<pair<int, int>>* idxQueue, queue<pair<int, int>>* fireQueue, int time)
{
	queue<pair<int, int>> nextQueue;
	queue<pair<int, int>> nextFireQueue;

	while (!fireQueue->empty())
	{
		pair<int, int> popVal = fireQueue->front();
		fireQueue->pop();

		int x = popVal.first;
		int y = popVal.second;

		for (int i = 0; i < 4; i++)
		{
			int tx = x + fx[i];
			int ty = y + fy[i];

			if (0 <= tx && tx < width && 0 <= ty && ty < height)
			{
				if (map[ty][tx] != 'X' && map[ty][tx] != 'D' && map[ty][tx] != '*')
				{
					map[ty][tx] = '*';
					nextFireQueue.push(make_pair(tx, ty));
				}
			}
		}
	}

	while (!idxQueue->empty())
	{
		pair<int, int> popVal = idxQueue->front();
		idxQueue->pop();

		int x = popVal.first;
		int y = popVal.second;

		check[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int tx = x + fx[i];
			int ty = y + fy[i];

			if (0 <= tx && tx < width && 0 <= ty && ty < height && check[ty][tx] == false)
			{
				if (map[ty][tx] != 'X' && map[ty][tx] != '*')
				{
					if (map[ty][tx] == 'D')
					{
						return time + 1;
					}

					check[ty][tx] = true;
					nextQueue.push(make_pair(tx, ty));
				}
			}
		}
	}

	int retVal = -1;
	if (!nextQueue.empty())
	{
		int bfsRet = bfs(&nextQueue, &nextFireQueue, time + 1);
		if (bfsRet != -1)
			retVal = bfsRet;
	}

	return retVal;
}

int main()
{
	int pX, pY;
	scanf("%d %d", &height, &width);

	queue<pair<int, int>> fireQueue;
	for (int i = 0; i < height; i++)
	{
		scanf("%s", map[i]);
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 'S')
			{
				pX = j;
				pY = i;
			}
			else if (map[i][j] == '*')
			{
				fireQueue.push(make_pair(j, i));
			}
		}
	}

	queue<pair<int, int>> initQueue;
	initQueue.push(make_pair(pX, pY));
	int ans = bfs(&initQueue, &fireQueue, 0);

	if (ans != -1)
		printf("%d\n", ans);
	else
		printf("impossible\n");

	return 0;
}