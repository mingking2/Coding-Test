#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int A, B;

	cin >> A >> B;
	
	cout << A * (B % 10) << endl;
	cout << A * (((B-(B % 10))/10)%10) << endl;
	cout << A * (B/100) << endl;
	cout << A * B  << endl;

}


