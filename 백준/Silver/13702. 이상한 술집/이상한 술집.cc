#include <iostream>
using namespace std;

int main()
{
    int N, K;
    int max = -1;
    cin >> N >> K;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    long long left = 1;
    long long right = max;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; ++i)
            sum += arr[i] / mid;
        if (sum >= K)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << right;
}