#include <iostream>
 
using namespace std;
 
int n;
int cnt[10001]; // 숫자의 개수를 저장하는 배열
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> n;
    // 숫자의 개수 세기
    for (int i = 0; i < n; i++) {
        cin >> num;
        cnt[num]++;
    }
 
    // 숫자의 개수만큼 출력
    for (int i = 1; i < 10001; i++) {
        while (cnt[i] != 0) {
            cout << i << '\n';
            cnt[i]--;
        }
    }
}

