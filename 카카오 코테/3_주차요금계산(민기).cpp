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


int fees[] = {180, 5000, 10, 600};
const char* records[] = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
                            "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
                            "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

size_t fees_len = sizeof(fees) / sizeof(fees[0]);
size_t records_len = sizeof(records) / sizeof(records[0]);

// fees_len�� �迭 fees�� �����Դϴ�.
// records_len�� �迭 records�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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