#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    int table[id_list_len][id_list_len];  // 신고 당하면 1, 아니면 0인 표
    int arr[id_list_len];  // 신고 당한 총 횟수 저장
    int* answer = (int*)malloc(id_list_len * sizeof(int));  // 신고 후 받은 메일 수 저장

    // table 초기화
    for (int i = 0; i < id_list_len; i++) for (int j = 0; j < id_list_len; j++) table[i][j] = 0;

    // table 채우기
    for (int i = 0; i < report_len; i++) {
        char* division; // report를 공백 기준으로 구분하는 포인터
        int index1, index2;

        division = strtok(report[i], " "); // 공백 기준으로 전에 있는 문자열
        for (int j = 0; j < id_list_len; j++) if (strcmp(id_list[j], division) == 0) index1 = j;

        division = strtok(NULL, " "); // 공백 기준으로 후에 있는 문자열
        for (int j = 0; j < id_list_len; j++) if (strcmp(id_list[j], division) == 0) index2 = j;

        table[index1][index2] = 1; // 중복 신고는 불가능하기 때문에 표에는 0 또는 1 뿐임
    }

    // 신고 당한 횟수 저장
    for (int i = 0; i < id_list_len; i++) {
        arr[i] = 0;
        for (int j = 0; j < id_list_len; j++) if (table[j][i] > 0) arr[i]++;
    }

    // 신고 후 k 조건을 만족하여 메일을 받은 횟수 저장
    for (int i = 0; i < id_list_len; i++) {
        answer[i] = 0;
        for (int j = 0; j < id_list_len; j++) if (table[i][j] > 0 && arr[j] >= k) answer[i]++;
    }
    return answer;
}

//test