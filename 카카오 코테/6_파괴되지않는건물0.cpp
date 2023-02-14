#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int board[4][5] = { {5,5,5,5,5},
					{5,5,5,5,5},
					{5,5,5,5,5},
					{5,5,5,5,5} };

int skill[4][6] = { {1,0,0,3,4,4},
					{1,2,0,2,3,2},
					{2,1,0,3,1,2},
					{1,0,1,3,3,1} };

int solution(int (*board)[5], int (*skill)[6]) {
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (skill[i][0] == 1) {
			for (int j = skill[i][1]; j <= skill[i][3]; j++) {
				for (int k = skill[i][2]; k <= skill[i][4]; k++) {
					board[j][k] -= skill[i][5];
				}
			}
		}
		else {
			for (int j = skill[i][1]; j <= skill[i][3]; j++) {
				for (int k = skill[i][2]; k <= skill[i][4]; k++) {
					board[j][k] += skill[i][5];
				}
			}
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
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("===============\n\n");
}

int main() {
	print_board();
	printf("\nanswer : %d\n",solution(board, skill));
	print_board();
}

