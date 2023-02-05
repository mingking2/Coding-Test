#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int solution(int n, int k) {
    int arr[13] = {};
    int sosu[13] = {};
    int seq = 0, answer = 0;
    int start = 0, i = 0, seq_2 = 0, check = 1;
    long long sum = 0;
    long long avg = 1;

    while (n / k > 0) {
        arr[seq++] = n % k;
        n = n / k;
    }
    arr[seq++] = n;

    for (i; i < seq; i++) {
        start = i;
        if (start == 0 && arr[i] > 0) {
            sosu[seq_2] = arr[i];
            seq_2++;
            for (int j = i + 1; j < seq; j++) {
                start = j - 1;
                if (arr[j] == 0) {
                    break;
                }
                else if (arr[j] != 0) {
                    sosu[seq_2] = arr[j];
                    seq_2++;
                }
            }
        }

        else if (arr[start] == 0) {
            for (int j = i; j < seq; j++) {
                start = j;
                for (int tt = j + 1; tt < seq; tt++) {
                    if (arr[tt] == 0) {
                        break;
                    }
                    else if (arr[tt] != 0) {
                        sosu[seq_2] = arr[tt];
                        seq_2++;
                    }
                    j = tt;
                }
                if (arr[j + 1] == 0) {
                    break;
                }
            }
        }

        for (int w = 0; w < seq_2; w++) {
            sum += sosu[w] * avg;
            avg *= 10;
        }
        if (seq_2 > 0 && sum > 1) {
            for (int sosu_checker = 2; sosu_checker <= sqrt(sum); sosu_checker++) {
                if (sum % sosu_checker == 0) {
                    check = 0;
                    break;
                }
            }
            if (check == 1) {
                answer++;
            }
        }
        seq_2 = 0, avg = 1, sum = 0, check = 1;
        i = start;
    }

    return answer;
}