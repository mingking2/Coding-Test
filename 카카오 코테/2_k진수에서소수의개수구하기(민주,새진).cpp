#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int n, int k) {
    int arr[13] = {};
    int i = 0;
    long value = 0;
    long count = 0;

    while (n / k > 0) {
        arr[i++] = n % k;
        n /= k;
    }
    arr[i] = n;
    k = 0;

    for (int j = 0; j <= i; j++) {
        count = 1;
        value = 0;
        while (arr[j] != 0 && j >= 0) { //num 재활용
            n = arr[j];
            value += n * count; //num 변수 재활용
            count *= 10;
            j++;
        }
        count = 0;

        if (value == 2) k++;

        if (value > 1 && value % 2 != 0) {
            for (n = 1; n <= sqrt(value); n += 2) { //홀수만 돌려줌
                if (value % n == 0) {
                    count++;
                    if (count > 1)
                        break;
                }
            }
            if (count == 1) {
                k++;
            }
        }
    }
    return k;
}

int main() {
    int jinsu = 0;
    int num = 0;

    scanf("%d", &num);
    scanf("%d", &jinsu);
    printf("%d", solution(num, jinsu));

    return 0;
}

/*
테스트 1 〉	통과 (4.34ms, 4.01MB)
테스트 2 〉	통과 (0.01ms, 4.18MB)
테스트 3 〉	통과 (0.01ms, 4.45MB)
테스트 4 〉	통과 (0.01ms, 4.42MB)
테스트 5 〉	통과 (0.01ms, 4.2MB)
테스트 6 〉	통과 (0.01ms, 4.38MB)
테스트 7 〉	통과 (0.01ms, 4.13MB)
테스트 8 〉	통과 (0.01ms, 4.44MB)
테스트 9 〉	통과 (0.01ms, 4.19MB)
테스트 10 〉통과 (0.01ms, 4.2MB)
테스트 11 〉통과 (0.01ms, 4.09MB)
테스트 12 〉통과 (0.01ms, 4.16MB)
테스트 13 〉통과 (0.01ms, 4.2MB)
테스트 14 〉통과 (0.01ms, 4.12MB)
테스트 15 〉통과 (0.01ms, 4.16MB)
테스트 16 〉통과 (0.01ms, 4.13MB)
*/



