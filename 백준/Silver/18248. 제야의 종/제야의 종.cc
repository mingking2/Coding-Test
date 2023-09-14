#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
백준 18248번: 제야의 종

1 2
1 1

2 2
1 0
0 1

*/


int main() {
    int N, M;
    cin >> N >> M;

    vector <vector<int>> arr(N, vector<int>(M+1,0)); // N행 M열을 가지는 벡터 선언

    for(int i=0; i<N; i++) {
        int sum =0;
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        arr[i][M] = sum;
    }

    bool answer = true;

    sort(arr.begin(), arr.end(), [M](const vector<int>& v1, const vector<int>& v2){
        return v1[M] > v2[M];
    });

    for(int i=0;i<M;i++) {
        int check = arr[0][i];
        for(int j=0;j<N;j++) {
            if(check < arr[j][i]) {
                answer = false;
                break;
            }
            check = arr[j][i];
        }
    }

    if(answer) cout << "YES\n";
    else cout << "NO\n";
   
}