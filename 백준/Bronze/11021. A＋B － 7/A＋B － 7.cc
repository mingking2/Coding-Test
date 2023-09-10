#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int T=0;
	int A, B;

	cin >> T;
	for (int i = 0; i <T; i++) {
		cin >> A >> B;
		cout << "Case #"<< i+1 <<": " << A + B << "\n";
	}
}
