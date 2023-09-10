#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int c[26] = { 0 };
	cin >> a;

	int max = -1, overlap = 0, d = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 'a') {
			a[i] -= ('a' - 'A');
		}
		c[a[i]-'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (max < c[i]) {
			max = c[i];
			d = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max == c[i])
			overlap++;
	}

	if (overlap >= 2) {
		cout << "?" << endl;
	}
	else {
		cout << (char)('A' + d) << endl;
	}
}