#include <iostream>
using namespace std;

int main() {
	int n1, n2;
	int rn1, rn2;

	cin >> n1;
	cin >> n2;

	rn1 = 100 * (n1 % 10) + 10 * ((n1 / 10) % 10) + (n1 / 100);
	rn2 = 100 * (n2 % 10) + 10 * ((n2 / 10) % 10) + (n2 / 100);

	if (rn1 > rn2) cout << rn1;
	else cout << rn2;

}