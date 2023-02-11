#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define CAPACITY 1000

typedef struct Car {
    int number;
    int time;
}C;

C list[CAPACITY];
int n = 0;

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    char copy[20];
    char* record, * state;
    int time, number, i, j;

    for (int i = records_len - 1; i >= 0; i--) {
        strcpy(copy, records[i]);
        time = atoi(strtok(copy, ":")) * 60 + atoi(strtok(NULL, " "));
        number = atoi(strtok(NULL, " "));
        state = strtok(NULL, " ");

        if (n == 0) list[n++].number = number;

        for (j = 0; j < n; j++) {
            if (list[j].number == number) break;
            else if (list[j].number != number && j == n - 1) list[n++].number = number;
        }

        if (strcmp(state, "OUT") == 0) list[j].time += time;
        else {
            if (list[j].time == 0) list[j].time += 1439;
            list[j].time -= time;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (list[i].number > list[j].number) {
                list[n] = list[i];
                list[i] = list[j];
                list[j] = list[n];
            }
        }
    }

    int* answer = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        if (list[i].time <= fees[0]) answer[i] = fees[1];
        else {
            if ((list[i].time - fees[0]) % fees[2] != 0)
                list[i].time += (fees[2] - (list[i].time - fees[0]) % fees[2]);
            answer[i] = fees[1] + (list[i].time - fees[0]) / fees[2] * fees[3];
        }
    }

    return answer;
}
