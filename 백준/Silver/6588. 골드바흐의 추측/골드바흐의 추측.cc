#include <iostream>
using namespace std;

int a[1000001];

void isPrime(int num)
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    isPrime(1000001);
    bool ch = false;

    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;


        for (int i = 3; i <= n; i += 2) {
            if (a[i] != 0 && a[n-i] != 0) {
                ch = true;
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }

        if(!ch)
            cout << "Goldbach's conjecture is wrong." << "\n";
    }

    return 0;
}
