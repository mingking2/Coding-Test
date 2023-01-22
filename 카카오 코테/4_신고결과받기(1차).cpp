#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


const char* id_list[] = { "muzi","frodo","apeach","neo" };
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
int k = 0;

size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
size_t report_len = sizeof(report) / sizeof(report[0]);

int* number_k = (int*)calloc(id_list_len, sizeof(int));	// 제출할때는 solution에 넣으슈
int ch_k = 0;




bool str_compare(char a[]) {
	for (int i = 0; i < id_list_len; i++) {
		if (strcmp(id_list[i], a) == 0) {
			ch_k = i;
			return 1;
		}
	}
	return 0;
}

void str_token(int p,const char* report[], char a[], char* tmp[]) {
	strcpy(a, report[p]);
	char* ptr = strtok(a, " ");
	tmp[0] = ptr;
	ptr = strtok(NULL, " ");
	tmp[1] = ptr;

}

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len,const char* report[], size_t report_len, int k) {

	int* answer = (int*)calloc(id_list_len, sizeof(int));

	for (int p = 0; p < report_len; p++) {
		char same_t[30];
		char* tmp_s[2] = { NULL, };
		str_token(p, report, same_t, tmp_s);
		str_compare(tmp_s[1]);
		number_k[ch_k]++;

		for (int q = p + 1; q < report_len; q++) {
			if (strcmp(report[q], report[p]) == 0) {
				number_k[ch_k]--;
			}
		}
	
	}


	for (int i = 0; i <= id_list_len; i++) {
		char mail[30];
		char* tmp[2] = { NULL, };
		str_token(i, report, mail, tmp);
	
		if (answer != NULL) {
			if (str_compare(tmp[1]) && number_k[ch_k] >= k) {
				str_compare(tmp[0]);
				answer[ch_k]++;
			}
		}	
	}

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


	printf("\n*   number_k[]   *\n");
	printf(" [");
	for (int i = 0; i < id_list_len; i++) {
		printf(" %d ", number_k[i]);
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