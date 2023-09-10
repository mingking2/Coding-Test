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
	int n,i=0,k=0;
	int num = 0;
	int N[246912];

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		N[i] = n;
		i++;
	}
	
	for (int k = 0; k < i; k++) {
		for (int j = N[k] + 1; j <= 2 * N[k]; j++) {
			if (isPrime(j)) {
				num++;
			}
		}
		printf("%d\n", num);
		num = 0;
	}
	
	
}