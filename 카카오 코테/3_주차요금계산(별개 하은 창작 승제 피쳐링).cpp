#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    char copy[20];
    short Time[10000];
    for (int i = 0; i < 10000; i++) Time[i] = 0;
    char* record, * state;
    int time, number, count = 0;

    for (int i = records_len - 1; i >= 0; i--) {
        strcpy(copy, records[i]);
        time = atoi(strtok(copy, ":")) * 60 + atoi(strtok(NULL, " "));
        number = atoi(strtok(NULL, " "));
        state = strtok(NULL, " ");

        if (strcmp(state, "OUT") == 0) Time[number] += time;
        else {
            if (Time[number] == 0) Time[number] += 1439;
            Time[number] -= time;
            count++;
        }
    }

    int* answer = (int*)malloc(sizeof(int) * count);

    for (int i = 0, j = 0; i < 10000; i++) {
        if (Time[i] != 0) {
            if (Time[i] <= fees[0]) answer[j++] = fees[1];
            else {
                Time[i] -= fees[0];
                if (Time[i] % fees[2] == 0) Time[i] /= fees[2];
                else Time[i] = (Time[i] + (fees[2] - Time[i] % fees[2])) / fees[2];
                answer[j++] = fees[1] + Time[i] * fees[3];
            }
        }
    }
    return answer;
}
