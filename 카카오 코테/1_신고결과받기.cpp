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

const char* id_list[] = { "muzi","frodo","apeach","neo" };
size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
int ch_k = 0;

void show(char* report[], size_t report_len) {
	printf("*   id_list[]   *\n");
	for (int i = 0; i < id_list_len - 1; i++) {
		printf(" %s\n", id_list[i]);
	}

	printf("*   report[]   *\n");
	for (int i = 0; i < report_len - 1; i++) {
		printf(" %s\n", report[i]);
	}
}

// 개인 코드
//int main() {
//    char* id_list[20];
//    char input_id[20];
//    char div_line[] = "============";
//    int i = 0;
//    int k = 0;
//    int ch1, ch2 = 0;
//    size_t id_list_len;
//    while (i!=3) {
//        printf("유저 ID :");
//        scanf("%s", input_id);
//        id_list[i] = _strdup(input_id);
//        i++;
//        id_list_len = i;
//    }
//
//    char* report[20];
//    size_t report_len;
//
//    i = 0;
//    while (1) {
//        ch1 = 0;
//        printf("신고자 유저 ID :");
//        scanf("%s", input_id);
//
//        if (strcmp(input_id, "exit") == 0) break;
//        if (strcmp(input_id, "show") == 0) show(id_list,id_list_len,report,report_len);
//
//        for (int j = 0; j < id_list_len; j++) {
//            if (strcmp(id_list[j], input_id) == 0) {
//                ch1 = 1;
//                report[i] = _strdup(input_id);
//                i++;
//                report_len = i;
//                while (1) {
//                    ch2 = 0;
//                    printf("신고 대상의 유저 ID :");
//                    scanf("%s", input_id);
//
//                    if (strcmp(input_id, "exit") == 0) {
//                        break;
//                    } 
//
//                    for (int m = 0; m < id_list_len; m++) {
//                        if (strcmp(id_list[m], input_id) == 0) {
//                            ch2 = 1;
//                            strcat(input_id, " #");
//                            report[i] = _strdup(input_id);
//                            i++;
//                            report_len = i;
//                        }
//                    }
//                    if (ch2 != 1) {
//                        printf("신고할 대상의 유저 ID가 존재하지 않습니다.\n");
//                    }
//                }
//               
//            }
//        }
//        if (ch1 != 1&& strcmp(input_id, "show") !=0&&strcmp(input_id, "exit") != 0) {
//            printf("신고자의 유저 ID가 존재하지 않습니다.\n");
//        }
//
//
//    }
//
//
//
//    
//
//}


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

	printf("id_list_len : %d\n", id_list_len);
	printf("report_len : %d\n", report_len);

	char** report = (char**)malloc(sizeof(char*) * report_len);
	char command[BUFFER_SIZE];
	char target[BUFFER_SIZE];
	int* number_k = (int*)calloc(id_list_len,sizeof(int));
	int i = 0;
	int k = 2;

	while (1) {
		printf("$ ");
		scanf("%s %s", command, target);

		if (strcmp(command, "exit") == 0 || strcmp(target,"exit")==0) break;

		if (str_compare(command) == 1) {
			if (strcmp(command, target) != 0 && str_compare(target) == 1) {
				number_k[ch_k]++;
				printf("'%s'가 '%s'를 신고했습니다.\n", command, target);
				strcat(command, " ");
				strcat(command, target);
				report[i] = _strdup(command);
				i++;

				printf("*   report[]   *\n");
				for (int j = 0; j < i; j++) {
					printf(" %s\n", report[j]);
				}
			}
			else {
				if (strcmp(command, target) == 0) printf("동일한 ID입니다.\n");
				else printf("신고하려는 대상의 ID가 존재하지 않습니다.\n");
			}
		}
		else {
			printf("신고자의 ID가 존재하지 않습니다.\n");
		}
	}

	int* get_mail = (int*)calloc(id_list_len, sizeof(int));


	for (int i = 0; i < id_list_len; i++) {
		char rev_target[30];
		char* tmp = {};
		strcpy(rev_target, report[i]);
		
		printf("%s\n", rev_target);
		
		char* ptr = strtok(rev_target, " ");
		
		while (ptr != NULL) {
			printf("%s\n", ptr);
			tmp = ptr;
			//strcpy(tmp, ptr);
			ptr = strtok(NULL, " ");
			
		}

		if (strcmp(id_list[i], ptr) == 0 && number_k[i] >= k) {
			str_compare(tmp);
			get_mail[ch_k]++;
		}

	}
	printf("*   get_mail[]   *\n");
	for (int j = 0; j < id_list_len; j++) {
		printf(" %d ", get_mail[j]);
	}


}