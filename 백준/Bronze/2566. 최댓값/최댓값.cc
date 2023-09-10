#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[9][9];
	int max = -100;
	int row, col;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
				row = i;
				col = j;
			}
		}
	}

	row++;
	col++;
	printf("%d\n%d %d", max,row,col);

}