#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int T = 0;
	int num;
	int max = -1000000;
	int min = 1000000;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
	}

	cout << min <<" "<< max;

}
