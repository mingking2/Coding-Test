#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int b;
    string result;
    int tmp = 1;

    cin >> n >> b;

    while(n) {
        char c;
        if(n % b < 10) {
            result += to_string(n%b);
            n/=b;
        } else {
            c = n%b - 10 +'A';
            n/=b;
            result += c;
        }
    }

    reverse(result.begin(), result.end());
    

    cout << result;

}