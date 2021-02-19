// Á¤¿Ã 1092
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int x, y;

long calcPow(long a, long n) {
	if (n == 0) {
		return 1;
	}
	else {
		long temp = calcPow(a, n / 2);
		if (n % 2 == 0) 
			return temp * temp % 20091024;
		else 
			return ((temp * temp) % 20091024) * a % 20091024;
	}
}

int main()
{
	scanf("%d %d", &x, &y);

	int ans = calcPow(x, y);

	printf("%d\n", ans);

	return 0;
}