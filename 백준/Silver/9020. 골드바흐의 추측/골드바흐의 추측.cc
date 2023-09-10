#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int T;
	int N[10001];
	int dif = 10000, first=0;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N[i]);
	}

	for (int k = 0; k < T; k++) {
		for (int j = 2; j <= N[k]; j++) {
			if (isPrime(j) && isPrime(N[k] - j) && j <= N[k] - j) {
				if (dif > N[k] - 2 * j) {
					dif = N[k] - 2 * j;
					first = j;
				}
			}
		}
		printf("%d %d\n", first, first + dif);
		dif = 10000;
	}

}