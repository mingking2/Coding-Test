#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char* id_list[] =  { "muzi", "frodo", "apeach", "neo" }; 
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }; 

size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
size_t report_len = sizeof(report) / sizeof(report[0]);

int str_compare(char a[]) {
	for (int i = 0; i < id_list_len; i++) {
		if (strcmp(id_list[i], a) == 0) {
			return i;
		}
	}
	return -1;
}

void str_token(int p, const char* report[], char a[], char* tmp[]) {
	strcpy(a, report[p]);
	char* ptr = strtok(a, " ");
	tmp[0] = ptr;
	ptr = strtok(NULL, " ");
	tmp[1] = ptr;

}

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
	
	int** ch;
	ch = (int**)malloc(id_list_len, sizeof(int*));
	for (int i = 0; i < id_list_len; ++i) {
		if (ch != NULL) {
			ch[i] = (int*)malloc(id_list_len, sizeof(int));
		}
	}

	for (int i = 0; i < report_len; ++i) {
		char* report_strtok;
		char report_copy[20];
		strcpy(report_copy, report[i]);
		report_strtok = strtok(report_copy, " ");

		
		char copy[30]="";
		char* tmp[2] = { NULL, };
		int a = 0;	int b = 0;
		str_token(i, report, copy, tmp);

		a = str_compare(tmp[0]);
		b = str_compare(tmp[1]);
		ch[a][b] = 1;


	}

	//printf("\n*   ch[]   *\n");
	//for (int j = 0; j < id_list_len; j++) {
	//	for (int k = 0; k < id_list_len; k++) {
	//		printf("%d ", ch[j][k]);
	//	}
	//	printf("\n");
	//}


	int target = 0;
	int sum = 0;
	for (int i = 0; i < id_list_len; ++i) {
		sum = 0;
		for (int j = 0; j < id_list_len; ++j) {
			if (ch != NULL && *ch !=NULL) {
				sum += ch[j][i];
				target = i;
			}
		}
	
	int* result = (int*)malloc(id_list_len, sizeof(int));
	for (int j = 0; j < id_list_len; j++) {
		for (int i = 0; i < id_list_len; i++) {
			if (ch[i][j] == 1) result[j] += 1;
		}
	}

	for (int i = 0; i < id_list_len; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	int* answer = (int*)malloc(id_list_len, sizeof(int));
	for (int j = 0; j < id_list_len; j++) {
		for (int i = 0; i < id_list_len; i++) {
			if (ch[j][i] == 1 && result[i]>=k) answer[j] += 1;
		}
	}


	//	//printf("%d\n", sum);

	//	if (sum >= k) {
	//		for (int m = 0; m < id_list_len; ++m) {
	//			if (ch != NULL &&*ch!=NULL&& answer != NULL) {
	//				if (ch[m][target] == 1) {
	//					answer[m]++;
	//				}
	//			}

	//		}
	//	}
	//}

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