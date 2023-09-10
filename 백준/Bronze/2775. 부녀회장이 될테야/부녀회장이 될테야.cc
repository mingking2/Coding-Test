#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




int main() {
	int a[15][15] = { 0, };
	int T, k, n = 0;

	for (int i = 0; i < 15; i++) {
		a[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", a[k][n]);


	}
}