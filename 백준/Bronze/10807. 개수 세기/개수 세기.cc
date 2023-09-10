#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, v, sum = 0;
	int arr[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &v);

	for (int j = 0; j < N; j++) {
		if (v == arr[j]) {
			sum++;
		}
	}
	printf("%d", sum);
}