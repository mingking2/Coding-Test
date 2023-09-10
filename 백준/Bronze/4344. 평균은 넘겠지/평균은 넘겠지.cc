#include <iostream>
#include <string.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int c;
	int Case=0;
	int N[1000] = { 0, };
	cin >> c;
	for (int i = 0; i < c; i++) {
		int sum = 0;
		int people = 0;

		cin >> Case;
		for (int j = 0; j < Case; j++) {
			cin >> N[j];
			sum += N[j];
		}

		double ave = double(sum / Case);

		for (int j = 0; j < Case; j++) {
			if (N[j] > ave) {
				people++;
			}
		}
		cout << (double(people) / double(Case))*100<< "%" << "\n";
	}

	
}