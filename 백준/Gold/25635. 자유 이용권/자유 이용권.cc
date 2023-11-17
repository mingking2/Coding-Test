#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    if (N == 1) {
        cout << 1 << endl;
    } else {
        long long sum = 0;
        for (int i = 0; i < N - 1; ++i) {
            sum += A[i];
        }
        
        if (A[N - 1] <= sum + 1) {
            long long totalSum = 0;
            for (int i = 0; i < N; ++i) {
                totalSum += A[i];
            }
            cout << totalSum << endl;
        } else {
            cout << sum * 2 + 1 << endl;
        }
    }
    return 0;
}
