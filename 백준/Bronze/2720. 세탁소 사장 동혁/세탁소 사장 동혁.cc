#include <iostream>
using namespace std;

int main() {
    int t, price;
    cin >> t;

    int rest[] = {25, 10, 5, 1};

    for(int i=0;i<t;i++) {
        cin >> price;
        

        for(int j=0;j<4;j++) {
            if(price/rest[j] > 0) {
                cout << price/rest[j] << " ";
                price %= rest[j];
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

}