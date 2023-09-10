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
	int N;
	int ch=0,num=0;
	scanf("%d", &N);

	
	for (int i = 0; i < N; i++) {
		scanf("%d", &ch);
		if (isPrime(ch)) num++;
	}
	
	printf("%d", num);
}