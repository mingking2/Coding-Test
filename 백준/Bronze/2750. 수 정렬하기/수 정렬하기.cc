#include <iostream>
using namespace std;

int main() {
	int num1;
	cin >> num1;
	int* arr = new int[num1];

	for (int i = 0; i < num1; i++) {
		cin >> arr[i];
	}

	int tmp;
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num1 - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < num1; i++) {
		cout << arr[i] << endl;
	}

	delete[]arr;
}