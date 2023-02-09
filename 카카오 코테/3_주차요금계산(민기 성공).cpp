#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fees[] = { 180, 5000, 10, 600 };//{ 1,461,1,10 };//{ 120,0,60,591 };//
const char* records[] = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
	"07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
	"19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

//{ "00:00 1234 IN" };

//{ "16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN" };



size_t fees_len = sizeof(fees) / sizeof(fees[0]);
size_t records_len = sizeof(records) / sizeof(records[0]);

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
	int* in_time = (int*)malloc(sizeof(int) * 10000);
	for (int i = 0; i < 10000; i++) in_time[i] = -1439;
	int* total_time = (int*)calloc(10000, sizeof(int));

	char copy_record[30] = {};
	char copy_time[30] = {};
	char* cnumber;
	char* tf;

	for (int i = 0; i < records_len; i++) {
		int sum = 0;
		char h[10] = {};
		char m[10] = {};
		strcpy(copy_record, records[i]);

		strcpy(copy_time, strtok(copy_record, " "));
		cnumber = _strdup(strtok(NULL, " "));
		tf = (strtok(NULL, " "));
		printf("%s\n", cnumber);
		if (strcmp("IN", tf) == 0) {
			strcpy(h, strtok(copy_time, ":"));
			strcpy(m, strtok(NULL, " "));

			sum += atoi(h) * 60 + atoi(m);
			printf("IN - sum : %d\n", sum);

			in_time[(atoi)(cnumber)] = sum;

		}
		else if (strcmp("OUT", tf) == 0) {
			strcpy(h, strtok(copy_time, ":"));
			strcpy(m, strtok(NULL, " "));

			sum += atoi(h) * 60 + atoi(m);
			printf("OUT - sum : %d\n", sum);
			
			total_time[(atoi)(cnumber)] += (sum - in_time[(atoi)(cnumber)]);
			
			in_time[(atoi)(cnumber)] = -1;
		}

	}


	for (int i = 0; i < 10000; i++) {
		if (in_time[i] != -1) {
			total_time[i] += (1439 - in_time[i]);
			//printf("total_time[%d] = %d\n", i, total_time[i]);
		}
	}
	int length = 0;
	int* answer = (int*)malloc(sizeof(int) * records_len);
	for (int i = 0; i < 10000; i++) {
		if (total_time[i] <= 1439) {
			printf("in_time[%d] = %d\n", i, in_time[i]);
			printf("total_time[%d] = %d\n", i, total_time[i]);
			if (total_time[i] > fees[0]) {
				answer[length++] = fees[1] + (ceil((float)(total_time[i] - fees[0]) / (float)fees[2])) * fees[3];
			}
			else {
				answer[length++] = fees[1];
			}

		}

	}

	free(in_time);
	free(total_time);

	return answer;

}

int main() {
	int* a = solution(fees, fees_len, records, records_len);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", a[i]);
	}

}