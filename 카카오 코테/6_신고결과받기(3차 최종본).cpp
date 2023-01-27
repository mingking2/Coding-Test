#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char* id_list[] = { "muzi", "frodo", "apeach", "neo" };
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };

size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
size_t report_len = sizeof(report) / sizeof(report[0]);


int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {

	int** ch;
	int i, j;
	ch = (int**)malloc(sizeof(int*) * id_list_len);
	for (int i = 0; i < id_list_len; i++) {
		if (ch != NULL) {
			ch[i] = (int*)malloc(sizeof(int) * id_list_len);
		}
	}

	for (i = 0; i < report_len; i++) {
		char* report_strtok;
		char report_copy[20];
		strcpy(report_copy, report[i]);

		report_strtok = strtok(report_copy, " ");
		int index1 = 0;
		for (j = 0; j < id_list_len; j++) {
			if (strcmp(id_list[j], report_strtok) == 0) {
				index1 = j;
				break;
			}
		}

		report_strtok = strtok(NULL, " ");
		int index2 = 0;
		for (j = 0; j < id_list_len; j++) {
			if (strcmp(id_list[j], report_strtok) == 0) {
				index2 = j;
				break;
			}
		}

		ch[index1][index2] = 1;
	}

	int* result = (int*)calloc(id_list_len, sizeof(int));
	int* answer = (int*)calloc(id_list_len, sizeof(int));
	for (j = 0; j < id_list_len; j++) {
		for (i = 0; i < id_list_len; i++) {
			if (ch[i][j] == 1) result[j] += 1;
		}
		if (result[j] >= k) {
			for (i = 0; i < id_list_len; i++) {
				if (ch[i][j] == 1) answer[i] += 1;
			}
		}
	}

	for (i = 0; i < id_list_len; i++) {
		free(ch[i]);
	}
	free(ch);
	free(result);
	return answer;
}

int main() {
	int* get_mail = solution(id_list, id_list_len, report, report_len, 2);

	printf("\n*   id_list[]   *\n");
	printf(" [");
	for (int i = 0; i < id_list_len; i++) {
		printf(" %s ", id_list[i]);
	}
	printf("]");
	printf("\n");



	printf("\n*   report[]   *\n");
	printf(" [");
	for (int j = 0; j < report_len; j++) {
		printf(" %s, ", report[j]);
	}
	printf("]");
	printf("\n");

	printf("\n*   answer[]   *\n");
	printf(" [");
	for (int j = 0; j < id_list_len; j++) {
		printf(" %d ", get_mail[j]);
	}
	printf("]");

}