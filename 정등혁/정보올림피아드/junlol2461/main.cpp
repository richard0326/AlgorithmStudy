// 정보올림피아드 2461
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
std::pair<int, int> flower[111111];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		scanf("%d %d %d %d", &sm, &sd, &em, &ed);
		flower[i].first = sm * 100 + sd;
		flower[i].second = em * 100 + ed;
	}
	sort(flower + 1, flower + n + 1);

    int tmpEnd = 0;
    int idx = 0;
    int num = 0;
    bool flg;
    bool resFlg = true;
    int end = 301;
    while (end < 1131 && idx <= n)
    {
        flg = false;
        idx++;
        for (int i = idx; i <= n; ++i)
        {
            if (flower[i].first > end)
                break;
            if (tmpEnd < flower[i].second)
            {
                flg = true;
                tmpEnd = flower[i].second;
                idx = i;
            }
        }
        if (flg)
        {
            end = tmpEnd;
            num++;
        }
        else
        {
            resFlg = false;
            break;
        }
    }
    if (!resFlg)    
        printf("0");
    else 
        printf("%d", num);

    return 0;
}