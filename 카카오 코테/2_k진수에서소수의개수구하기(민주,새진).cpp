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
        while (arr[j] != 0 && j >= 0) { //num ��Ȱ��
            n = arr[j];
            value += n * count; //num ���� ��Ȱ��
            count *= 10;
            j++;
        }
        count = 0;

        if (value == 2) k++;

        if (value > 1 && value % 2 != 0) {
            for (n = 1; n <= sqrt(value); n += 2) { //Ȧ���� ������
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
�׽�Ʈ 1 ��	��� (4.34ms, 4.01MB)
�׽�Ʈ 2 ��	��� (0.01ms, 4.18MB)
�׽�Ʈ 3 ��	��� (0.01ms, 4.45MB)
�׽�Ʈ 4 ��	��� (0.01ms, 4.42MB)
�׽�Ʈ 5 ��	��� (0.01ms, 4.2MB)
�׽�Ʈ 6 ��	��� (0.01ms, 4.38MB)
�׽�Ʈ 7 ��	��� (0.01ms, 4.13MB)
�׽�Ʈ 8 ��	��� (0.01ms, 4.44MB)
�׽�Ʈ 9 ��	��� (0.01ms, 4.19MB)
�׽�Ʈ 10 ����� (0.01ms, 4.2MB)
�׽�Ʈ 11 ����� (0.01ms, 4.09MB)
�׽�Ʈ 12 ����� (0.01ms, 4.16MB)
�׽�Ʈ 13 ����� (0.01ms, 4.2MB)
�׽�Ʈ 14 ����� (0.01ms, 4.12MB)
�׽�Ʈ 15 ����� (0.01ms, 4.16MB)
�׽�Ʈ 16 ����� (0.01ms, 4.13MB)
*/



