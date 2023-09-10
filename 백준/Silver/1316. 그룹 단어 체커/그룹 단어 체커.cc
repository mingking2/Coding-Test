#include <iostream>
#include <string>
using namespace std;

int main() {
	int N,sum=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		int check = 1;
		for (int j = 0; j < a.length(); j++) {
			for (int k = 0; k < j; k++) {
				if (a[j] != a[j - 1] && a[j]==a[k]) {
					check = 0;
					break;
				}	
			}
		}
		if(check==1) sum++;

	}
	cout << sum;
}