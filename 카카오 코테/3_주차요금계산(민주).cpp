#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct array {
	char* num, * in_out;
	int pre_time, money, store;
};

char* value;
int n = 0;
int capacity = 4;
struct array* INFO = NULL;

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len);
int check_time(char* time);
int check_number(char* number);

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
	INFO = (struct array*)malloc(sizeof(struct array) * records_len);
	char* time, * in_out, * Number;
	float af_time = 0.0;
	int store = 0;
	int check = 0;

	for (int i = 0; i < records_len; i++) {
		value = strdup(records[i]);
		time = strtok(value, " ");
		Number = strdup(strtok(NULL, " "));
		in_out = strdup(strtok(NULL, " "));
		af_time = check_time(time);
		check = check_number(Number); //number 인덱스 찾기
		if (strcmp(in_out, "IN") == 0) {
			if (INFO[i].money < 0) {
				INFO[i].money = 0;
				INFO[i].store = 0;
			}

			if (check == -1) { // 새로 입력된 차량 && 배열 "
				INFO[n].num = Number;
				INFO[n].pre_time = af_time;
				INFO[n++].in_out = strdup(in_out);
			}
			else {
				INFO[check].pre_time = af_time;
				INFO[check].in_out = strdup(in_out);
			}
		}
		else {
			INFO[check].in_out = strdup("OUT");
			INFO[check].pre_time = af_time - INFO[check].pre_time;
			INFO[check].store = INFO[check].pre_time;
			if (INFO[check].pre_time < fees[0]) {
				INFO[check].money = fees[1];
			}
			else {
				if (INFO[i].money < 0) {
					INFO[check].money = fees[1];
				}
				af_time = (float)(INFO[check].pre_time - fees[0]) / (float)fees[2];
				INFO[check].money += ceil(af_time) * fees[3];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		float af_time = 0.0;
		if (strcmp(INFO[i].in_out, "IN") == 0) {
			INFO[i].pre_time = 1439 - INFO[i].pre_time;
			INFO[i].pre_time += INFO[i].store;
			if (INFO[i].pre_time < fees[0]) INFO[i].money = fees[1];
			else {
				INFO[i].money = fees[1];
				af_time = (float)(INFO[i].pre_time - fees[0]) / (float)fees[2];
				INFO[i].money += ceil(af_time) * fees[3];
			}
		}
	}

	int* answer = (int*)malloc(sizeof(int*) * n);
	char* tmp;
	printf("정렬시작\n");
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(INFO[i].num, INFO[j].num) > 0) { //i가 더 크다면
				tmp = INFO[i].num;  //?//recored
				INFO[i].num = strdup(INFO[j].num);
				INFO[j].num = strdup(tmp);
				store = INFO[i].money;
				INFO[i].money = INFO[j].money;
				INFO[j].money = store;
				printf("확인\n");
				for (int in = 0; in < n; in++) {
					printf("%d\n", INFO[in].money);
				}
			}
		}
		answer[i] = INFO[i].money;
	}

	answer[n] = INFO[n].money;
	return answer;
}


int check_time(char* time) {
	int total_time = atoi(strtok(time, ":"));
	total_time *= 60;
	total_time += atoi(strtok(NULL, ":"));
	return total_time;
}

int check_number(char* number) {
	for (int i = 0; i < n; i++) {
		if (strcmp(INFO[i].num, number) == 0) {
			return i; //현재 인덱스를 반환
		}
	}
	if (n < capacity) { //만약 현재 번호가 배열 범위내에 있지만, 입력되지 않았던 경우라면
		return -1;
	}
}


