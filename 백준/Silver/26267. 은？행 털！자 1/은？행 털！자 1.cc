#include <iostream>
#include <unordered_map>
using namespace std;

/*
백준 26267번 : 은?행 털!자 1


1
0 3 4

2
0 0 10
1 0 3

5
0 2 4
1 6 1
2 4 4
3 8 10
4 5 2

 */

int main()
{
    int n;
    cin >> n;

    unordered_map<int, long long int> m;
    long long int maxPrice = 0;

    for (int i = 0; i < n; ++i)
    {
        int x, t, c;
        cin >> x >> t >> c;
        m[x - t] += c;
        if(m[x - t] > maxPrice) maxPrice = m[x - t];
    }

    cout << maxPrice;
}