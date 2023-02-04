#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool PrimeNumber(int a) {
    if (a == 1) return false;
    for (int j = 2; j < a; j++) {
        if (a % j == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    int remain;
    int index = 0;
    int result[512] = {};
    int i;
    int j = 0;


    while (n > 0) {
        remain = n % k;
        result[index++] = remain;
        n /= k;
    }

    short int digit = 0;
    for (i = index - 1; i >= 0; i--) {
        if (result[i] != 0) {
            digit *= 10;
            digit += result[i];

        }
        else {
            if (digit == 0) continue;
            if (PrimeNumber(digit)) {
                printf("digit : %d\n", digit);
                answer++;
                digit = 0;
            }

        }

        if (i == 0) {
            if (PrimeNumber(digit)) {
                printf("digit 4 : %d\n", digit);
                answer++;
                digit = 0;
                return answer;
            }
        }
    }



    //printf("answer : %d\n", answer);
    //for (i = index-1; i >= 0; i--)
    //    printf("%d", result[i]);
    //printf("\n");
    return answer;
}


int main() {
    solution(437674, 3);
    // solution(110011, 10);
}