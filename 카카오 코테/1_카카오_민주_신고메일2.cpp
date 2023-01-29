#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

const char* id_list[] = { "muzi", "frodo", "apeach", "neo" };
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };

char* L, * R, * value[1];

int find_dex(char* value, const char * id_list[], int end) {
    for (int i = 0; i < end; i++) {
        if (strcmp(value, id_list[i]) == 0)
            return i;
    }
}

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    int* answer = (int*)calloc(id_list_len, sizeof(int)); //아이디 수 만큼 동적할당
    int* key = (int*)calloc(id_list_len, sizeof(int));

    int dex = 0;
    for (int i = 0; i < id_list_len; i++) {
        for (int j = 0; j < report_len; j++) {
            value[0] = _strdup(report[j]);
             L = strtok(*value, " ");
             R = strtok(NULL, " ");
            if (strcmp(L, id_list[i]) == 0) {
                dex = find_dex(R, id_list, id_list_len);
                if (answer[dex] == 0) {
                    answer[dex]++;
                    key[dex]++;
                }
                else {
                    report[j] = _strdup("fail fail");
                }
            }
        }
        printf("\n%s\n",id_list[i]);
        for (int i = 0; i < id_list_len; i++)
            printf("%d ", answer[i]);
        printf("\n");
        for (int i = 0; i < id_list_len; i++)
            printf("%d ", key[i]);
        for (int i = 0; i < id_list_len; i++) answer[i] = 0;
    }

    for (int i = 0; i < id_list_len; i++) {
        if (key[i] >= k) {
            for (int j = 0; j < report_len; j++) {
                value[0] = _strdup(report[j]);
                L = strtok(*value, " ");
                R = strtok(NULL, " ");
                if (strcmp(R, id_list[i]) == 0) {
                    answer[find_dex(L, id_list, id_list_len)]++;
                }
            }
        }
    }

    printf("\n\nanswer\n");
    for (int i = 0; i < id_list_len; i++)
        printf("%d ", answer[i]);

    return answer;
    free(answer);
    free(key);
}

int main() {

    solution(id_list, 4, report, 5, 2);
    return 0;
}

