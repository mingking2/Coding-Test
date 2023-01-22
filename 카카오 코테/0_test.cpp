#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// id_list_len�� �迭 id_list�� �����Դϴ�.
// report_len�� �迭 report�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.

    int temp[id_list_len][id_list_len];

    for (int i = 0; i < id_list_len; ++i)
    {
        for (int j = 0; j < id_list_len; ++j)
        {
            temp[i][i] = 0;
        }
    }


    for (int i = 0; i < report_len; ++i)
    {
        char* report_edit;
        report_edit = strtok(report[i], " ");

        int idx1 = 0;
        for (int j = 0; j < id_list_len; ++j)
        {
            if (strcmp(id_list[j], report_edit) == 0)
            {
                idx1 = j;
            }
        }

        report_edit = strtok(NULL, " ");
        int idx2 = 0;
        for (int j = 0; j < id_list_len; ++j)
        {
            if (strcmp(id_list[j], report_edit) == 0)
            {
                idx2 = j;
            }
        }
        temp[idx1][idx2] = 1;
    }

    int result[id_list_len];
    for (int j = 0; j < id_list_len; ++j)
    {
        result[j] = 0;
        for (int i = 0; i < id_list_len; ++i)
        {
            if (temp[i][j] == 1)
            {
                result[j] += 1;
            }
        }
    }


    int* answer = (int*)malloc(id_list_len * sizeof(int));

    for (int j = 0; j < id_list_len; ++j)
    {
        answer[j] = 0;
        for (int i = 0; i < id_list_len; ++i)
        {
            if (temp[j][i] == 1 && result[i] >= k)
            {
                answer[j] += 1;
            }
        }
    }


    return answer;
}