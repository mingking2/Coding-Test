#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[1000][1000] = { {5, 5, 5, 5, 5} ,{5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5} };
int skill[250000][6] = { {1, 0, 0, 3, 4, 4},{1, 2, 0, 2, 3, 2},{2, 1, 0, 3, 1, 2},{1, 0, 1, 3, 3, 1} };
int board_x =4;
int board_y = 5;
int skill_len = 4;
int count = 0;
void check() {
	for (int i = 0; i < board_x; i++) {
		for (int j = 0; j < board_y; j++) if (board[i][j] > 0) count++;
	}
	printf("정답은 : %d", count);
}

void status() {
	printf("  [현재 건물의 체력 상태] \n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("   %d ", board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	status();
	int i = 0;
	int x,y;
	while (i < 4) {
		x = skill[i][1];
		y = skill[i][2];
		for (int j = 0; j <= skill[i][3] - skill[i][1]; j++) {
			for (int k = 0; k <= skill[i][4] - skill[i][2]; k++) {
				if (skill[i][0] == 1) board[x][y] -= skill[i][5];
				else board[x][y] += skill[i][5];
				y++;
			}
			y = skill[i][2];
			x++;
		}
		status();
		i++;
	}

	check();
}