// Á¤¿Ã 1092
#define _CRT_SECURE_NO_WARNINGS
#define MOD		20091024
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
			return ((temp % MOD) * (temp % MOD)) % MOD;
		else 
			return (((temp % MOD) * (temp % MOD)) % MOD) * a % MOD;
	}
}

int main()
{
	scanf("%d %d", &x, &y);

	int ans = calcPow(x, y);

	printf("%d\n", ans);

	return 0;
}