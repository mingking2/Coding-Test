#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
fee[]
0	   1   	      2	        3
기본시간	   기본요금    단위시간   단위요금


record[] : "시각 차량번호 내역"
-->> 원소들은 시각을 기준으로 오름차순 정렬

시각 -> HH:MM 형식, 길이5인 문자열

차량번호 -> '0' ~ '9'로 구성된 길이4인 문자열

내역 -> 길이 2 또는 3인 문자열
    IN or OUT


*/


int fees[] = {180, 5000, 10, 600};
const char* records[] = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
                            "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
                            "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

size_t fees_len = sizeof(fees) / sizeof(fees[0]);
size_t records_len = sizeof(records) / sizeof(records[0]);

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* copy_record;
    char* time;
    char* cnumber;
    char* tf;

    for (int i = 0; i < records_len; i++) {
        strcpy(copy_record, records[i]);
        time = strtok(copy_record, " ");
        cnumber = strtok(NULL, " ");
        tf = strtok(NULL, " ");


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