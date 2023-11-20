#include <iostream>
using namespace std;

int main() {
    int a[101] = {0, };
    int n,m;
    int i,j,k;

    cin >> n >> m;

    for(int q=1;q<=n;q++) {
        a[q] = q;
    }

    for(int q=0;q<m;q++) {
        cin >> i >> j;
        int min = i;
        for(int p=j;p>=i;p--) {
            if(min > p) break;
            int temp = a[p];
            a[p] = a[min];
            a[min] = temp;
            min+=1;
        }
        
    }

    for(int r=1;r<=n;r++) {
        cout << a[r] << " ";
    }    

}