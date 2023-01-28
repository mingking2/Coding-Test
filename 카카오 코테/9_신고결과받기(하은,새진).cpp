#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    int table[id_list_len][id_list_len];  // �Ű� ���ϸ� 1, �ƴϸ� 0�� ǥ
    int arr[id_list_len];  // �Ű� ���� �� Ƚ�� ����
    int* answer = (int*)malloc(id_list_len * sizeof(int));  // �Ű� �� ���� ���� �� ����

    // table �ʱ�ȭ
    for (int i = 0; i < id_list_len; i++) for (int j = 0; j < id_list_len; j++) table[i][j] = 0;

    // table ä���
    for (int i = 0; i < report_len; i++) {
        char* division; // report�� ���� �������� �����ϴ� ������
        int index1, index2;

        division = strtok(report[i], " "); // ���� �������� ���� �ִ� ���ڿ�
        for (int j = 0; j < id_list_len; j++) if (strcmp(id_list[j], division) == 0) index1 = j;

        division = strtok(NULL, " "); // ���� �������� �Ŀ� �ִ� ���ڿ�
        for (int j = 0; j < id_list_len; j++) if (strcmp(id_list[j], division) == 0) index2 = j;

        table[index1][index2] = 1; // �ߺ� �Ű�� �Ұ����ϱ� ������ ǥ���� 0 �Ǵ� 1 ����
    }

    // �Ű� ���� Ƚ�� ����
    for (int i = 0; i < id_list_len; i++) {
        arr[i] = 0;
        for (int j = 0; j < id_list_len; j++) if (table[j][i] > 0) arr[i]++;
    }

    // �Ű� �� k ������ �����Ͽ� ������ ���� Ƚ�� ����
    for (int i = 0; i < id_list_len; i++) {
        answer[i] = 0;
        for (int j = 0; j < id_list_len; j++) if (table[i][j] > 0 && arr[j] >= k) answer[i]++;
    }
    return answer;
}

//test