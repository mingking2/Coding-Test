#include <iostream>
using namespace std;

int main() {
    string n;
    int b;
    int result = 0;
    int tmp = 1;

    cin >> n >> b;

    for(int i=n.length()-1;i>=0;i--) {
        int num;

        if(n[i] >= '0' && n[i] <= '9') {
            num = n[i] - '0';
        } else {
            num = n[i] - 'A' + 10;
        }

        num *= tmp;
        result += num;
        tmp *= b;
    }

    cout << result;

}