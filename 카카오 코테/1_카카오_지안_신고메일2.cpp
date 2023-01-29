#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* id_list[] = { "muzi", "frodo", "apeach", "neo" };
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };

int find_index(char* name, const char* id_list[], int end) {
	for (int i = 0; i < end; i++) {
		if (strcmp(id_list[i], name) == 0) {
			return i;
		}
	}
	return -1; //없으면 음수 출력
}

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
	char* copy,
		* L = (char*)malloc(sizeof(char) * 10),
		* R = (char*)malloc(sizeof(char) * 10);
	int* report_status = (int*)calloc(id_list_len, sizeof(int));
	int* answer = (int*)calloc(id_list_len, sizeof(int));

	for (int i = 0; i < report_len; i++) {
		//중복 제거
		if (strcmp(report[i], "fail fail") != 0) {
			for (int j = i + 1; j < report_len;j++) {
				if (strcmp(report[i], report[j]) == 0) {
					report[j] = _strdup("fail fail");
				}
			}
		}
		
		//k값, 신고 횟수 비교 위한 report_status
		copy = _strdup(report[i]);
		L = strtok(copy, " ");
		R = strtok(NULL, " ");
		report_status[find_index(R, id_list, id_list_len)]++;
	}

	printf("report_status\n");
	for (int i = 0; i < id_list_len; i++)
		printf("%d ", report_status[i]);

	for (int i = 0; i < id_list_len; i++) {
		if (report_status[i] >= k) {
			for (int j = 0; j < report_len; j++) {
				copy = _strdup(report[j]);
				L = strtok(copy, " ");
				R = strtok(NULL, " ");
				if (strcmp(R, id_list[i]) == 0) {
					answer[find_index(L, id_list, id_list_len)]++;
				}
			}
		}
	}

	printf("\nanswer\n");
	for (int i = 0; i < id_list_len; i++)
		printf("%d ", answer[i]);

	return answer;
}

int main() {
	solution(id_list, 4, report, 5, 2);
}

//test