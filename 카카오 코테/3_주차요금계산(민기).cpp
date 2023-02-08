#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
fee[]
0	   1   	      2	        3
�⺻�ð�	   �⺻���    �����ð�   �������


record[] : "�ð� ������ȣ ����"
-->> ���ҵ��� �ð��� �������� �������� ����

�ð� -> HH:MM ����, ����5�� ���ڿ�

������ȣ -> '0' ~ '9'�� ������ ����4�� ���ڿ�

���� -> ���� 2 �Ǵ� 3�� ���ڿ�
    IN or OUT


*/
typedef struct parking_cal {
    int time;
    char* cnumber;
    char* tf;
}Parking;

typedef struct parking_result {
    int use_time = 0;
    char* cnumber;
    int money = 0;
}Result;


int fees[] = {180, 5000, 10, 600};
const char* records[] = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
                            "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
                            "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

size_t fees_len = sizeof(fees) / sizeof(fees[0]);
size_t records_len = sizeof(records) / sizeof(records[0]);

Parking* park = (Parking*)malloc(sizeof(Parking) * records_len);
Result* result = (Result*)malloc(sizeof(Result) * records_len);


int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char copy_record[30] = {};
    char copy_time[30] = {};
   // printf("recodes_len : %d\n", records_len);

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

    for (int i = 0; i < records_len; i++) {
        printf("%d\n", park[i].time);
        printf("%s\n", park[i].cnumber);
        printf("%s\n\n", park[i].tf);
    }
    int i = 0;
    int j = 0;
    while(i<records_len) {
        for (j = i + 1; j < records_len; j++) {
            if (strcmp("OUT", park[i].tf) == 0) {
                i++;
                j = i + 1;
            }
            if (strcmp(park[j].cnumber, park[i].cnumber) == 0 && strcmp("IN",park[i].tf) == 0) {
                strcpy(result[i].cnumber, park[i].cnumber);
                  
                result[i].use_time += park[j].time - park[j].time;
                i++;
                j = i + 1;
                
            }
        }
        if (strcmp("IN", park[i].tf) == 0) {

            i++;
            j = i + 1;
        }
        
    }


    int* answer = (int*)malloc(1);
    return answer;
}

int main() {
    int* a = solution(fees, fees_len, records, records_len);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }
    
}