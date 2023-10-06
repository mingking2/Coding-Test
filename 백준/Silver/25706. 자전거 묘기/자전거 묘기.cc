#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> road(N);
    vector<int> result(N);

    for (int i = 0; i < N; i++)
    {
        cin >> road[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
            result[i] = 1;
        else
        {
            if (road[i] == 0)
                result[i] = result[i + 1] + 1;
            else
            {
                if (i + road[i] + 1 >= N)
                    result[i] = 1;
                else
                    result[i] = result[i + road[i] + 1] + 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
}