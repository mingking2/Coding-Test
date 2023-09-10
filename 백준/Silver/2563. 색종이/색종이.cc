#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int board[100][100] = { 0 };
	int N, x, y;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				board[j][k]=1;
			}
		}
	}


	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1) sum++;
		}
	}

	printf("%d", sum);

}