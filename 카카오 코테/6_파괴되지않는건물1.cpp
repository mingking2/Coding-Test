#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int board[3][3] = { {1,2,3},
					{4,5,6},
					{7,8,9} };

int skill[3][6] = { {1,1,1,2,2,4},
					{1,0,0,1,1,2},
					{2,2,0,2,0,100} };

int m = 3;
int n = 3;

int solution(int(*board)[3], int(*skill)[6]) {
	int answer = 0;
	int test[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	for (int i = 0; i < 3; i++) {
		if (skill[i][0] == 1) {
			if (skill[i][1] + 2 <= 3) {
				test[skill[i][1]][skill[i][2]] -= skill[i][5];
				test[skill[i][1] + 2][skill[i][2] + 2] -= skill[i][5];

				test[skill[i][1]][skill[i][2] + 2] += skill[i][5];
				test[skill[i][1] + 2][skill[i][2]] += skill[i][5];
			}
			else {
				test[skill[i][1]][skill[i][2]] -= skill[i][5];
				test[skill[i][1] + 1][skill[i][2] + 1] -= skill[i][5];

				test[skill[i][1]][skill[i][2] + 1] += skill[i][5];
				test[skill[i][1] + 1][skill[i][2]] += skill[i][5];
			}

		}
		else {
			if (skill[i][1] + 2 <= 3) {
				test[skill[i][1]][skill[i][2]] += skill[i][5];
				test[skill[i][1] + 2][skill[i][2] + 2] += skill[i][5];

				test[skill[i][1]][skill[i][2] + 2] -= skill[i][5];
				test[skill[i][1] + 2][skill[i][2]] -= skill[i][5];
			}
			else {
				test[skill[i][1]][skill[i][2]] += skill[i][5];
				test[skill[i][1] + 1][skill[i][2] + 1] += skill[i][5];

				test[skill[i][1]][skill[i][2] + 1] -= skill[i][5];
				test[skill[i][1] + 1][skill[i][2]] -= skill[i][5];
			}

		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			test[i + 1][j] += test[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			test[j][i + 1] += test[j][i];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] += test[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] > 0)
				answer++;
		}
	}

	return answer;
}

void print_board() {
	printf("\n=====board=====\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("===============\n\n");
}

int main() {
	print_board();
	printf("\nanswer : %d\n", solution(board, skill));
	print_board();
}