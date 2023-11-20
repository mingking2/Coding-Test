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
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        
    }

    for(int r=1;r<=n;r++) {
        cout << a[r] << " ";
    }    

}