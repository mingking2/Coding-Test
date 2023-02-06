#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool primeNum(unsigned long long x) {
	if (x < 2) return false;
	for (unsigned long long i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int solution(int n, int k) {
	unsigned long long num = 0;
	unsigned long long remain = 0;
	unsigned long long mul = 1;
	int answer = 0;


	while (n > 0 || num > 0) {
		remain = n % k;
		.printf("remain : %d\n", remain);
		if (remain == 0) {
			if (primeNum(num)) answer++;
			num = 0;
			mul = 1;
		}
		else {

			printf("num : %d\n", num);
			num += remain * mul;
			mul *= 10;

		}
		n /= k;
	}


	if (primeNum(num)) answer++;
	printf("\nanswer : %d", answer);
	return answer;
}

int main() {
	solution(437674, 3);
	// solution(110011, 10);
}