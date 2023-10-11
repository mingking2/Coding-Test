#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, power;
    cin >> n;
    vector<long long> a(n);
    vector<int> count(63, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]!=0) {
            power = log2(a[i]); // 로그를 이용하여 2의 거듭제곱 찾기
            //cout << power << endl;
            count[power]++;
        }

    }

    long long answer = *max_element(a.begin(), a.end());
    //cout << answer << endl;

    int index = 0;
    for (int j = 0; j < 64; j++) {
        if (count[j] > 0) {
            count[j+1] += count[j]/2;
            index = j;
        }
    }

    
    answer = max(answer, (long long)pow(2,index));

    cout << answer << endl;
    // return 0;
}
