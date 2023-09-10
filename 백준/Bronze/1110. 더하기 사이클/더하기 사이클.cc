#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int N1;
	int N = -1;
	int num = 0;
	cin >> N1;
	int a = N1 / 10;
	int b = N1 % 10;

	while (N1 != N) {
		N = (10 * b) + ((a + b)%10);
		a = N / 10;
		b = N % 10;
		num++;

	}
	cout << num;

}
