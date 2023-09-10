#include <iostream>
#include <string>

using namespace std;

int main() {
	string eng = "abcdefghijklmnopqrstuvwxyz";
	string input;

	cin >> input;
	for (int i = 0; i <eng.length(); i++) {
		cout << (int)input.find(eng[i]) << " ";
		}
	}

