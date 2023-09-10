#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int X, N, a, b = 0;
	int sum = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		sum += a * b;
	}

	if (sum == X) printf("Yes");
	else printf("No");
}