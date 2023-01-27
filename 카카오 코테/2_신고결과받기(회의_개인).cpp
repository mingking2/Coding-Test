#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// id_list_len�� �迭 id_list�� �����Դϴ�.
// report_len�� �迭 report�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	int* answer = (int*)malloc(1);
	return answer;
}


//{ "muzi","frodo","apeach","neo" };
//{ "con","ryan" };
const char* id_list[] = { "con","ryan" };

//2
//3
int k = 2;

size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
int ch_k = 0;


bool str_compare(char command[]) {
	for (int i = 0; i < id_list_len; i++) {
		if (strcmp(id_list[i], command) == 0) {
			ch_k = i;
			return 1;
		}
	}
	return 0;
}


int main() {
	size_t report_len = id_list_len * (id_list_len - 1);

	//printf("id_list_len : %d\n", id_list_len);
	//printf("report_len : %d\n", report_len);

	char** report = (char**)malloc(sizeof(char*) * report_len);
	char command[BUFFER_SIZE];
	char target[BUFFER_SIZE];

	int* number_k = (int*)malloc(id_list_len,sizeof(int));
	int i = 0;
	

	//�Ű��ڿ� �Ű����� �Է� �ް� report[]�� ����, �� �Ű��� �� �Ű� ���� Ƚ���� number_k[]�� ����
	while (1) {
		printf("$ ");
		scanf("%s %s", command, target);

		if (strcmp(command, "exit") == 0 || strcmp(target,"exit")==0) break;

		if (str_compare(command) == 1) {
			if (strcmp(command, target) != 0 && str_compare(target) == 1) {
				number_k[ch_k]++;
				printf("'%s'�� '%s'�� �Ű��߽��ϴ�.\n", command, target);

				strcat(command, " ");
				strcat(command, target);

				report[i] = _strdup(command);
				i++;

			}
			else {
				if (strcmp(command, target) == 0) printf("������ ID�Դϴ�.\n");
				else printf("�Ű��Ϸ��� ����� ID�� �������� �ʽ��ϴ�.\n");
			}
		}
		else {
			printf("�Ű����� ID�� �������� �ʽ��ϴ�.\n");
		}
	}

	printf("*   report[]   *\n");
	for (int j = 0; j < i; j++) {
		printf(" %s\n", report[j]);
	}


	// report[]�� ������ ������ (�Ű��ڿ� �Ű����� ���� ������)�� ������ ���� ���
	for (int p = 0; p < i; p++) {
		for (int q = p+1; q < i; q++) {
			if (strcmp(report[q], report[p])==0) {
				char same_t[30];
				char* tmp_s[2];
				strcpy(same_t, report[p]);
				int n = 0;

				char* ptr_s = strtok(same_t, " ");
				while (ptr_s != NULL) {
					tmp_s[n] = ptr_s;
					//printf("\n %s \n", tmp_s[0]);
					n++;
					ptr_s = strtok(NULL, " ");
				}

				str_compare(tmp_s[1]);
				number_k[ch_k]--;
			}
		}
	}

	
	//report[]�� number_k[]�� ����Ͽ� ó����������� �Ű��ڸ��� ���� Ƚ���� get_mail[]�� ����
	int* get_mail;
	get_mail = (int*)malloc(id_list_len, sizeof(int));

	for (int i = 0; i < id_list_len; i++) {
		char rev_target[30];
		char* tmp[2] = {NULL, };
		int m = 0;
		strcpy(rev_target, report[i]);
		
		//printf("%s\n", rev_target);
		
		char* ptr = strtok(rev_target, " ");
		
		while (ptr != NULL) {
			
			tmp[m] = ptr;
			//printf("%s\n", tmp[m]);
			m++;
			ptr = strtok(NULL, " ");
			
		}

		
		if (str_compare(tmp[1]) && number_k[ch_k] >= k) {
			str_compare(tmp[0]);
			get_mail[ch_k]++;
		}
	}


	printf("\n*   get_mail[]   *\n");
	printf("  [");
	for (int j = 0; j < id_list_len; j++) {
		printf(" %d ", get_mail[j]);
	}
	printf("]");

}