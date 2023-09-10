#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int num[10];
	int x = 1;
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	int max = num[0];

	for (int i = 1; i < 10; i++) {
		if (max < num[i]) {
			max = num[i];
			x = i + 1;
		}
	}

	cout << max << "\n";
	cout << x;


}
