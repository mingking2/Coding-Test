#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	int max = a;
	if (a == b && b == c) {
		printf("%d", 10000 + a * 1000);
	}
	else if (a != b && a != c && b != c) {
		if (max < b) max = b;
		if (max < c) max = c;
		printf("%d", max * 100);
	}
	else {
		if (a == b) printf("%d", 1000 + a * 100);
		if (a == c) printf("%d", 1000 + a * 100);
		if (b == c) printf("%d", 1000 + b * 100);

	}
}