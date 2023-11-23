#include <iostream>
using namespace std;

string reverse(string input) {
    string str;
    int size = input.size();
    for(int i=size-1;i>=0;i--) {
        str += input[i];
    }

    return str;
}

int main() {
    string input;
    cin >> input;

    string str = reverse(input);

    if(input == str) cout << 1;
    else cout << 0;
}