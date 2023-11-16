#include <iostream>
using namespace std;

int a[1000001];

void isPrime(int m, int num)
{
    for (int i = 2; i <= num; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= num; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i + i; j <= num; j += i)
        {
            a[j] = 0;
        }
    }
    for (int i = m; i <= num; i++)
    {
        if (a[i] != 0)
            cout << a[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    isPrime(m, n);
}