// 정보올림피아드 1809
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> _stack;
int answer[500001];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int input = 0;
		scanf("%d", &input);

		while (true)
		{
			if (_stack.empty() == true)
			{
				answer[i] = 0;
				break;
			}

			pair<int, int> peekPair = _stack.top();
			int peek = peekPair.second;
			if (peek < input)
			{
				_stack.pop();
			}
			else
			{
				answer[i] = peekPair.first;
				printf("%d ", answer[i]);
				break;
			}
		}

		_stack.push(make_pair(i, input));
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", answer[i]);
	}

	return 0;
}