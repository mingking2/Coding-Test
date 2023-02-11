#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int seq = 0;
int count = 0;
int test = 0;

struct IN_AND_OUT {
    char IN_car_number[5];
    char OUT_car_number[5];
    int count_min;
    int check_in_out;
    int check_parking_min;
    char IN_hour[3], OUT_hour[3];
    char IN_min[3], OUT_min[3];
}; struct IN_AND_OUT car_in_out[1000];

char records_car(const char* records) {
    char* copy, * hour, * min, * car_number, * check_IN_OUT;
    copy = _strdup(records);
    hour = strtok(copy, ":");
    min = strtok(NULL, " ");
    car_number = strtok(NULL, " ");
    check_IN_OUT = strtok(NULL, " ");

    if (strcmp(check_IN_OUT, "IN") == 0) {
        strcpy(car_in_out[seq].IN_car_number, car_number);
        strcpy(car_in_out[seq].IN_hour, hour);
        strcpy(car_in_out[seq].IN_min, min);
        car_in_out[seq].check_in_out = 1;
        seq++;
    }
    else if (strcmp(check_IN_OUT, "OUT") == 0) {
        for (int i = 0; i < seq; i++) {
            if (strcmp(car_in_out[i].OUT_car_number, "\0") == 0 && strcmp(car_number, car_in_out[i].IN_car_number) == 0) {
                strcpy(car_in_out[i].OUT_car_number, car_number);
                strcpy(car_in_out[i].OUT_hour, hour);
                strcpy(car_in_out[i].OUT_min, min);
                car_in_out[i].check_in_out = 0;
                break;
            }
        }
    }
    return 0;
}

void check_in(int record_lens) {
    for (int i = 0; i < record_lens; i++) {
        if (car_in_out[i].check_in_out == 0) {
            car_in_out[i].count_min += (atoi(car_in_out[i].OUT_hour) - atoi(car_in_out[i].IN_hour)) * 60;
            if (strcmp(car_in_out[i].IN_min, car_in_out[i].OUT_min) > 0) {
                car_in_out[i].count_min -= 60;
                car_in_out[i].count_min += (atoi(car_in_out[i].OUT_min) + 60) - atoi(car_in_out[i].IN_min);
            }
            else {
                car_in_out[i].count_min += atoi(car_in_out[i].OUT_min) - atoi(car_in_out[i].IN_min);
            }
        }
        else if (car_in_out[i].check_in_out == 1) {
            car_in_out[i].count_min += (23 - atoi(car_in_out[i].IN_hour)) * 60;
            car_in_out[i].count_min += 59 - atoi(car_in_out[i].IN_min);
        }
    }
}

void parking_min(IN_AND_OUT in_car, int cons, int record_lens) {
    int test = cons;
    car_in_out[test].check_parking_min += car_in_out[test].count_min;
    for (int i = cons + 1; i < record_lens; i++) {
        if (strcmp(in_car.IN_car_number, car_in_out[i].IN_car_number) == 0) {
            car_in_out[test].check_parking_min += car_in_out[i].count_min;
            count++;
            strcpy(car_in_out[i].IN_car_number, "\0");
        }
    }
}

void sort(int len) {
    char* namech;
    int change = 0;
    for (int i = test + 1; i < len; i++) {
        if (strcmp(car_in_out[i].IN_car_number, "\0") == 0) {
            break;
        }
        if (strcmp(car_in_out[test].IN_car_number, car_in_out[i].IN_car_number) > 0) { // 5961 0000 0148 0000 5961
            change = car_in_out[test].check_parking_min;
            //namech = _strdup(car_in_out[test].IN_car_number);
            car_in_out[test].check_parking_min = car_in_out[i].check_parking_min;
            //strcpy(car_in_out[test].IN_car_number, car_in_out[i].IN_car_number);
            car_in_out[i].check_parking_min = change;
            //strcpy(car_in_out[i].IN_car_number, namech);
        }
    }
    test++;
}

int parking_fee(IN_AND_OUT time, int fee[]) {
    int result = 0;
    int a = 0;
    if (time.check_parking_min < fee[0]) {
        result = fee[1];
        printf("%d\n", result);
    }
    else if (time.check_parking_min > fee[0]) {
        if ((time.check_parking_min - fee[0]) % fee[2] != 0) {
            a = ((time.check_parking_min - fee[0]) / fee[2]) + 1;
            result = fee[1] + a * fee[3];
            printf("%d\n", result);
        }
        else if ((time.check_parking_min - fee[0]) % fee[2] == 0) {
            result = fee[1] + ((time.check_parking_min - fee[0]) / fee[2]) * fee[3];
            printf("%d\n", result);
        }
    }

    return result;
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    int* answer = (int*)malloc(sizeof(int) * records_len);
    for (int i = 0; i < records_len; i++) {
        records_car(records[i]);
    }

    check_in(records_len);


    for (int i = 0; i < records_len; i++) {
        parking_min(car_in_out[i], i, records_len);
    }

    for (int i = 0; i < records_len; i++) {
        sort(records_len);
    }

    for (int i = 0; i < count; i++) {
        if (car_in_out[i].check_parking_min == 0) {
            continue;
        }
        answer[i] = parking_fee(car_in_out[i], fees);
    }
    return answer;
}

int put_records1(const char* records[]) {      //record 값 넣어주는 함수
    int i = 0;
    records[i++] = _strdup("05:34 5961 IN");
    records[i++] = _strdup("06:00 0000 IN");
    records[i++] = _strdup("06:34 0000 OUT");
    records[i++] = _strdup("07:59 5961 OUT");
    records[i++] = _strdup("07:59 0148 IN");
    records[i++] = _strdup("18:59 0000 IN");
    records[i++] = _strdup("19:09 0148 OUT");
    records[i] = _strdup("22:59 5961 IN");
    int n = i;
    return n;
}

int main() {
    int fees[4] = { 180, 5000, 10, 600 };
    const char* records[9];
    put_records1(records);
    solution(fees, 4, records, 8);
}