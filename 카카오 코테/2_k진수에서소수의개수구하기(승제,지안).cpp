#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int if_prime(unsigned long long n) {
    if (n == 1 || n == 0) return 0;
    for (unsigned long long i = 3; i * i <= n; i++)   //�Ҽ� �Ǵ�
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
        else {
            if (dec == 2 || dec % 2 != 0)
                if (if_prime(dec) == 1) answer++;
            dec = 0, cnt = 1;
        }
        n /= k;
    }
    if (if_prime(dec) == 1) answer++;
    return answer;
}

int main() {
    int k, n;
    while (1) {
        printf("n, d\n:");
        scanf("%d %d", &n, &k);
        printf("solution: %d\n", solution(n, k));
    }
}