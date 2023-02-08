#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool primeNum(int x) {
    printf("%d\n", x);
    if (x == 1) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    short int index = 0;
    int a[100] = { 0 };  
    int answer = 0;

    while (n > 0) {
        a[index++] = n % k;
        n /= k;
    }

    unsigned long long int num = 0;
    for (int i = index - 1; i >= 0; i--) {
        if (a[i] != 0) {
            num *= 10;
            num += a[i];
        }
        else {
            if (num == 0) continue;
            if (primeNum(num)) answer++;
            num = 0;
        }
    }

    if (num != 0 && primeNum(num)) answer++;
    return answer;
}

int main() {
    printf("%d", solution(797161, 3));
}