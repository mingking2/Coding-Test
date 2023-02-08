#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct parking_cal {
	int time;
	char* cnumber;
	char* tf;
}Parking;


int m = 0;
int fees[] = { 180, 5000, 10, 600 };
const char* records[] = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
							"07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
							"19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

size_t fees_len = sizeof(fees) / sizeof(fees[0]);
size_t records_len = sizeof(records) / sizeof(records[0]);

Parking* park = NULL;
Parking* result = NULL;

int find_index(char* cnumber) {
	for (int i = 0; i < m; i++) {
		if (strcmp(result[i].cnumber, cnumber) == 0) {
			return i;
		}
	}
	return -1;
}

int compare(const void* a, const void* b) {
	return strcmp(((Parking*)a)->cnumber, ((Parking*)b)->cnumber);
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	park = (Parking*)malloc(sizeof(Parking) * records_len);
	result = (Parking*)malloc(sizeof(Parking) * records_len);


	char copy_record[30] = {};
	char copy_time[30] = {};

	// printf("recodes_len : %d\n", records_len);

	for (int i = 0; i < records_len; i++) {
		result[i].cnumber = _strdup("");
		result[i].time = 0;
	}

	for (int i = 0; i < records_len; i++) {
		int sum = 0;
		char h[10] = {};
		char m[10] = {};
		strcpy(copy_record, records[i]);

		strcpy(copy_time, strtok(copy_record, " "));
		park[i].cnumber = _strdup(strtok(NULL, " "));
		park[i].tf = _strdup(strtok(NULL, " "));

		strcpy(h, strtok(copy_time, ":"));
		strcpy(m, strtok(NULL, " "));

		sum += atoi(h) * 60 + atoi(m);
		printf("sum : %d\n", sum);

		park[i].time = sum;

	}

	//for (int i = 0; i < records_len; i++) {
	//    printf("%d\n", park[i].time);
	//    printf("%s\n", park[i].cnumber);
	//    printf("%s\n\n", park[i].tf);
	//}

	int i = 0;
	int j;
	
	while (i != records_len-1) {
		for (j = i + 1; j < records_len; j++) {

			if (strcmp("OUT", park[i].tf) == 0) {
				i++;
				j = i;
				continue;
			}

			if (find_index(park[i].cnumber) != -1) {
				if (strcmp("IN", park[i].tf) == 0 && strcmp(park[j].cnumber, park[i].cnumber) == 0) {
					int index = find_index(park[i].cnumber);
					result[index].time += park[j].time - park[i].time;
					i++;
					j = i;
				}

			}

			if (strcmp(park[j].cnumber, park[i].cnumber) == 0 && strcmp("IN", park[i].tf) == 0 && find_index(park[i].cnumber)==-1) {

				result[m].cnumber = _strdup(park[i].cnumber);
				printf("cnumber : %s\n", result[m].cnumber);
				result[m].time += park[j].time - park[i].time;
				printf("time : %d\n", park[j].time);
				printf("time : %d\n", park[i].time);
				printf("time : %d\n", result[m].time);
				m++;
				i++;
				j = i;

			}


		}
		if (strcmp("IN", park[i].tf) == 0) {
			int index = find_index(park[i].cnumber);
			printf("index : %d\n", 1439 - park[i].time);
			result[index].time += (1439 - park[i].time);
			i++;
			j = i;
		}


	}

	printf("\n\n\n");
	for (int i = 0; i < records_len; i++) {
		printf("cnumber : %s\n", result[i].cnumber);
		printf("time : %d\n", result[i].time);
		printf("\n");
	}

	int* answer = (int*)malloc(sizeof(int)*m);
	qsort((Parking*)result, m, sizeof(Parking), compare);

	for (int i = 0; i < m; i++) {
		printf("%s ", result[i].cnumber);
		if (result[i].time > fees[0]) {
			answer[i] = fees[1] + (ceil((float)(result[i].time - 180) / (float)fees[2])) * fees[3];
		}
		else {
			answer[i] = fees[1];
		}
	}
	printf("\n");
	free(park);
	free(result);

	return answer;
}

int main() {
	int* a = solution(fees, fees_len, records, records_len);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", a[i]);
	}

}