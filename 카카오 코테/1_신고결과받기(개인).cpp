#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	int* answer = (int*)malloc(1);
	return answer;
}


int main() {
	char* id_list[20];
	char input_id[20];
	char div_line[] = "============";
	int i = 0;
	int k = 0;
	int ch1, ch2 = 0;
	size_t id_list_len;
	while (i != 3) {
		printf("유저 ID :");
		scanf("%s", input_id);
		id_list[i] = _strdup(input_id);
		i++;
		id_list_len = i;
	}

	char* report[20];
	size_t report_len;

	i = 0;
	while (1) {
		ch1 = 0;
		printf("신고자 유저 ID :");
		scanf("%s", input_id);

		if (strcmp(input_id, "exit") == 0) break;

		for (int j = 0; j < id_list_len; j++) {
			if (strcmp(id_list[j], input_id) == 0) {
				ch1 = 1;
				report[i] = _strdup(input_id);
				i++;
				report_len = i;
				while (1) {
					ch2 = 0;
					printf("신고 대상의 유저 ID :");
					scanf("%s", input_id);

					if (strcmp(input_id, "exit") == 0) {
						break;
					}

					for (int m = 0; m < id_list_len; m++) {
						if (strcmp(id_list[m], input_id) == 0) {
							ch2 = 1;
							strcat(input_id, " #");
							report[i] = _strdup(input_id);
							i++;
							report_len = i;
						}
					}
					if (ch2 != 1) {
						printf("신고할 대상의 유저 ID가 존재하지 않습니다.\n");
					}
				}

			}
		}
		if (ch1 != 1 && strcmp(input_id, "show") != 0 && strcmp(input_id, "exit") != 0) {
			printf("신고자의 유저 ID가 존재하지 않습니다.\n");
		}


	}




}

