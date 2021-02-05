// 정보올림피아드 1662

#define _CRT_SECURE_NO_WARNINGS
// 출처: https://mygumi.tistory.com/289 [마이구미의 HelloWorld]


#include <iostream>
using namespace std;

int n;
bool g_maps[10][10];
bool g_colors[10][10];		// 색이 없으면 짝수에 대해서 애매해짐.
bool g_visited[10][10];

int dx[] = { -1, -1, 1, 1 };
int dy[] = { -1, 1, 1, -1 };

int dfs(int index, int cnt, bool color);
bool check(int column, int row);

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int check = 0;
			scanf("%d", &check);

			if (check == 1)
			{
				g_maps[i][j] = true;
			}

			if (i % 2 == 0)
			{
				if (j % 2 == 0) {
					g_colors[i][j] = 1;
				}
			}
			else
			{
				if (j % 2 != 0) {
					g_colors[i][j] = 1;
				}
			}
		}
	}

	printf("%d\n", dfs(-1, 0, true) + dfs(-1, 0, false));

	return 0;
}

int dfs(int index, int cnt, bool color)
{
	int ret = cnt;

	// 인덱스 형식으로 가야지만 체스판 형식을 모두 둘러 볼수 있음
	for (int i = index + 1; i < n * n; i++)
	{
		int column = i / n;
		int row = i % n;

		if (g_colors[column][row] != color)
			continue;

		if (g_maps[column][row] == 1)
		{
			if (check(column, row))
			{
				g_visited[column][row] = true;
				int retVal = dfs(i, cnt + 1, color);
				if (retVal > ret)
				{
					ret = retVal;
				}
			}
		}
	}

	return ret;
}

bool check(int column, int row)
{
	for (int i = 0; i < 4; i++)
	{
		int fx = dx[i] + row;
		int fy = dy[i] + column;

		for (int j = 1; j < n; j++)
		{
			if (0 <= fx && fx < n && 0 <= fy && fy < n)
			{
				if (g_visited[fy][fx] == true)
					return false;
			}
			else
				break;

			fx += dx[i];
			fy += dy[i];
		}
	}

	return true;
}