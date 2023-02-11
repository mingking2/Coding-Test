#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
 * Complete the 'maxEnergy' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY mat as parameter.
 */
int mat[4][4] = {
		{10,20,30,40},
		{60,50,20,80},
		{10,10,10,10},
		{60,50,60,50}
};

//bool visited[4];
//
//void dfs(int _start) {
//    visited[_start] = true;
//    printf("%d ¹æ¹®\n", _start);
//    for (int i = 0; i < 4; i++) {
//        if(mat[_start][i])
//    }
//}


int maxEnergy(int mat_rows, int mat_columns) {
	int i = 0;
	int j = 0;
	int k = 0;
	int k1 = 0;
	int index = 0;
	int min = 101;
	int sum = 0;
	int *s=(int*)malloc(sizeof(int)*mat_rows);
	for (k = 0; k < mat_columns; k++) {
		min = 101;
		if (k == mat_columns) break;
		k1 = k;
		sum = mat[0][k1];
		j = k1;
		for (i=0; i < mat_rows;i++) {
			//printf("sum : %d\n", sum);
			if (i == mat_rows - 1) break;
			if (i == 0) {
				if (k1 != 0) k1 -= 1;
				if (j != mat_columns-1) j++;
				while (k1 <= j) {
					if (min > mat[i + 1][k1]) min = mat[i + 1][k1];
					k1++;
				}
				sum += min;
				k1--;
				//printf("min : %d\n", min);
			}
			else {
				min = 101;
				j = k1;
				if (j != mat_columns-1) j++;
				if (k1 != 0) k1 -= 1;
				while (k1 <= j) {
					if (min > mat[i + 1][k1]) min = mat[i + 1][k1];
					k1++;
				}
				sum += min;
				k1--;
				//printf("-min : %d\n", min);
			}
		}
		//printf("sum %d\n", sum);
		s[index] = 100 - sum;
		index++;
	}
	
	int max = -1000;
	for (int i = 0; i < 4; i++) {
		if (max < s[i]) max = s[i];
		printf("s[%d] = %d\n", i,s[i]);
	}
	
	printf("max = %d\n", max);
	return max;
}

int main()
{
	maxEnergy(4, 4);


}

