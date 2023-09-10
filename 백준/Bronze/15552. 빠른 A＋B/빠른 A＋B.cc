#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int A, B;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B<<"\n";
	}
}

