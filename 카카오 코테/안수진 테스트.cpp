#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'findSchedules' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER workHours
 *  2. INTEGER dayHours
 *  3. STRING pattern
 */

 /*
  * To return the string array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * char** return_string_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
  *
  *     return a;
  * }
  *
  * char** return_string_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     char** a = malloc(5 * sizeof(char*));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = malloc(20 * sizeof(char));
  *     }
  *
  *     *(a + 0) = "dynamic";
  *     *(a + 1) = "allocation";
  *     *(a + 2) = "of";
  *     *(a + 3) = "string";
  *     *(a + 4) = "array";
  *
  *     return a;
  * }
  *
  */

int* change_question(char* copy_pattern,int time) {
    int val[7] = { 0 };
 
    for (int i = 0; copy_pattern[i] != '\0'; i++) {
        if (copy_pattern[i] != 63) {
           val[i]=copy_pattern[i] - '0';
        }
        else {
            val[i] = time;
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", val[i]);
    }

    return val;
}


int n = 7;
int index = 0;
int* qmark;
int promising(int i, int remain_time, int dayHours, int qmark_num) {
    int k = dayHours;
    while (i < k) {
        int day = (remain_time - i) / (qmark_num - 1);
        int rest_day = (remain_time - i) % (qmark_num - 1);
        if (day > k) 
            return 0;
        i++;
    }
    return 1;
}

void find_num(int i, int remain_time, int dayHours, int qmark_num) {
    if (promising(i, remain_time, dayHours, qmark_num)) {
        if (i == n) {

            return;
        }
        else {
            qmark[index++] = i;
            find_num(, remain_time - i, dayHours, qmark_num--);
        }
    }
}

char** findSchedules(int workHours, int dayHours, char* pattern, int result_count) {
    int sum_work = 0;
    char copy_pattern[7];
    int qmark_num = 0;
    int remain_time = 0;
    int div_daytime = 0;
    int div_rest = 0;
    int val[7];
    strcpy(copy_pattern, pattern);

    for (int i = 0; copy_pattern[i] != '\0'; i++) {
        if (copy_pattern[i] != 63) {
            val[i] = copy_pattern[i] - '0';
            printf("val[%d] : %d\n",i ,val[i]);
            sum_work += val[i];
        }
        else {
            qmark_num++;
            printf("qmark_num : %d\n", qmark_num);
        }
            
    }

    qmark = (int*)calloc(qmark_num, sizeof(int));
    remain_time = workHours - sum_work;
    div_daytime = remain_time / qmark_num;
    div_rest = remain_time % qmark_num;

    printf("remain_time : %d\n", remain_time);
    printf("div_daytime : %d\n", div_daytime);
    printf("div_rest : %d\n", div_rest);

    for (int j = 0; j < qmark_num; j++) {

    }
    
}

int main() {
    char pattern[] = {"???8???"};
    
    findSchedules(56, 8, pattern, 1);
}