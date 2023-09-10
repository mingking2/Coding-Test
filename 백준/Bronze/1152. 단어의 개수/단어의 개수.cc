#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int b = 0;
	getline(cin, a);

	if (a[0] == ' ') b--;
	if (a[a.length() - 1] == ' ') b--;
	for (int i = 0; i < a.length(); i++) {	
		if (a[i] == ' ') {
			b++;
		}
	}

	cout << b + 1;

}