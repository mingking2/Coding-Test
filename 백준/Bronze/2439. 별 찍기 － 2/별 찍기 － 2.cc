#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int N;

	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i-1; j++) {
			cout << " ";
		}
		for (int k = 0; k < N-i+1; k++) {
			cout << '*';
		}
		cout << "\n";
	}
}
