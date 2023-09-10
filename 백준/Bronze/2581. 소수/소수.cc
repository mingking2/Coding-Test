#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 범위 축약

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}


int main() {
	int M,N;
	int min = 10001, sum = 0;
	scanf("%d",&M);
	scanf("%d", &N);

	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			if (min > i) min = i;
			sum += i;
		}
	}
	if (sum == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}
	
}