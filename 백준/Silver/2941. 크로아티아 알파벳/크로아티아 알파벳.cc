#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	int count = 0;
	for (int i = 0; i <= a.size(); i++) {
		if (a[i] == 'c') {
			if (a[i + 1] == '=')
				i += 1;
			else if (a[i + 1] == '-')
				i += 1;
		}
		if (a[i] == 'd') {
			if (a[i + 1] == 'z' && a[i + 2] == '=')
				i += 2;
			else if (a[i + 1] == '-')
				i += 1;
		}
		if (a[i] == 'l' && a[i + 1] == 'j')
			i += 1;
		if (a[i] == 'n' && a[i + 1] == 'j')
			i += 1;
		if (a[i] == 's' && a[i + 1] == '=')
			i += 1;
		if (a[i] == 'z' && a[i + 1] == '=')
			i += 1;
		count++;
	}
	cout << count-1 << endl;
}