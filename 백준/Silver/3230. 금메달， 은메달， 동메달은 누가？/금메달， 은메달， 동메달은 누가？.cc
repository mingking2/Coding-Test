#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    int race[101];
    int ans[101];

    int rank;
    for(int i = 1;i<=n;i++) {
        cin >> rank;

        if(race[rank] != 0 && i != 1) {
            for(int j=i-1;j>=rank;j--) {
                race[j+1] = race[j];
            }
            race[rank] = i;
        } else {
            race[rank] = i;
        }
    }

    for(int i=1;i<=m;i++) {
        cin >> rank;
        int player = race[m-i+1];

        if(race[rank] != 0 && i != 1) {
            for(int j=i-1;j>=rank;j--) {
                ans[j+1] = ans[j];
            }
            ans[rank] = player;
        } else {
            ans[rank] = player;
        }
    }

    for(int i = 1; i<=3;i++) {
        cout << ans[i] << "\n";
    }
}