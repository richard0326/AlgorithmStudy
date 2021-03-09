// 1880
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char alphabet[27];

int main()
{
	scanf("%s", alphabet);
	fflush(stdin);

	char secretCode[100];
	scanf(" %[^\n]s", secretCode);

	char correctCode[100];
	int i;
	for (i = 0; secretCode[i] != '\0'; i++)
	{
		if ('A' <= secretCode[i] && secretCode[i] <= 'Z')
		{
			correctCode[i] = alphabet[secretCode[i] - 'A'] - 32;
		}
		else if ('a' <= secretCode[i] && secretCode[i] <= 'z')
		{
			correctCode[i] = alphabet[secretCode[i] - 'a'];
		}
		else
		{
			correctCode[i] = secretCode[i];
		}
	}

	correctCode[i] = '\0';
	printf("%s\n", correctCode);

	return 0;
}