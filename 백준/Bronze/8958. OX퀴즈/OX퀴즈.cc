#include <iostream>
#include <string.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	char score[100] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		int sum = 0;
		int count = 1;
		for (int i = 0; i < strlen(score); i++) {
			if (score[i] == 'O') {
				sum += count;
				count += 1;
			}
			else
				count = 1;
			
		}
		cout << sum << endl;
	}


}