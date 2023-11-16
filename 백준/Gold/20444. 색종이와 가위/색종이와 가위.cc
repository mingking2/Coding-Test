#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double n, k;
    cin >> n >> k;
    long double sq = sqrt(n*n + 4*(n-k+1));

    if(sq != (long long)sq) {
        cout << "NO\n";
        return 0;
    }

    long double x=(n+sq)/2.0;
    if(x == (long long)x && x>0) {
        cout << "YES\n";
    } else if(1) {
        x=(n-sq)/2.0;
        if(x == (long long)x && x>0) {
        cout << "YES\n";
        }
    } else {
        cout << "NO\n";
    }
}