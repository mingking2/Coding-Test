#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num = 0; 
	int sum = 0;
	int Arr[42] = { 0, };
	for (int i = 0; i < 10; i++) {
		cin >> num;
		Arr[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (Arr[i] > 0)
			sum++;
	}

	cout << sum;
	

}

