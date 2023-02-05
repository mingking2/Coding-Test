#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int if_prime(unsigned long long n) {
    if (n == 1 || n == 0) return 0;
    for (unsigned long long i = 2; i * i <= n; i++)   //소수 판단
        if (n % i == 0) return 0;
    return 1;
}
int solution(int n, int k) {
    int result, answer = 0;
    unsigned long long dec = 0, cnt = 1;

    while (n != 0) {
        result = n % k;
        if (result != 0) {
            dec += result * cnt;
            cnt *= 10;
        }
        if (result == 0 || n / k == 0) {
            if (if_prime(dec) == 1) answer++;
            dec = 0, cnt = 1;
        }
        n /= k;
    }
    return answer;
}