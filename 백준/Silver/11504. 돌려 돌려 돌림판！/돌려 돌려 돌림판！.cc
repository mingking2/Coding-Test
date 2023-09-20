#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int T, N;
    double M;
    cin >> T;
    int disc[200] = {};
    int X[10] = {};
    int Y[10] = {};
    double x = 0, y = 0;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int sum = 0;

        for (int i = 0; i < M; i++)
        {
            cin >> X[i]; // X의 각 자리수를 입력 받습니다.
            x = x + X[i] * pow(10.0, M - i - 1);
        }

        for (int i = 0; i < M; i++)
        {
            cin >> Y[i]; // Y의 각 자리수를 입력 받습니다.
            y = y + Y[i] * pow(10.0, M - i - 1);
        }

        for (int i = 0; i < N; i++)
        {
            cin >> disc[i]; // 돌림판의 상태를 입력 받습니다.
            //disc[i + N] = disc[i];
        }

        for (int i = N; i < 2*N; ++i) {
            disc[i] = disc[i-N];
        }

        double num = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                num += disc[i + j] * pow(10.0, M - j - 1);
            }
            if (num >= x && num <= y)
                sum++;
            num = 0;
        }

        cout << sum << endl;
        x=0;
        y=0;
    }
}