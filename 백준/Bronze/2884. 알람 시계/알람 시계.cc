#include <iostream>
using namespace std;

int main() {
	int hour, minute;

	cin >> hour >> minute;

	if (minute >= 45) {
		cout << hour << " " << (minute - 45);
	}
	else {
		if (hour > 0) {
			cout << (hour - 1) << " " << (minute + 15);
		}
		else if (hour == 0) {
			hour = 23;
			cout << hour << " " << (minute + 15);
		}

	}
}