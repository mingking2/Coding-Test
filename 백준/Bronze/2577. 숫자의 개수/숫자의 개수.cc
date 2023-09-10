#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int A, B, C;
	int multi;
	int Arr[10] = { 0, };

	cin >> A >> B >> C;
	multi = A * B * C;

	while (multi > 0) {
		Arr[multi % 10]++;

		multi /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << endl;
	}

}


