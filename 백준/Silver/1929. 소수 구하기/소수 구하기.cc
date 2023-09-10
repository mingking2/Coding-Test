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
	int M, N;
	scanf("%d %d", &M,&N);

	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			printf("%d\n", i);
		}
	}
	
	
	

}