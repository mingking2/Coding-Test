#include <iostream>
using namespace std;

int main() {
    long long n, k;

    cin >> n >> k;

    long long s = 0;
    long long e = n;

    while(s<=e) {
        long long mid = (s + e) / 2;
        long long sum = (mid+1)*(n-mid+1);
        if(sum == k) {
            cout << "YES";
            return 0;
        } else if(sum < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << "NO";
    return 0;

}