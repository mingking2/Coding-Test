#include <iostream>
using namespace std;

int main() {
	int N;
	int a, b, c;
	int sum=0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 100)
		{
			sum++;
		}
		else if (i<1000)
		{
			a = i / 100;
			b = (i - a * 100) / 10;
			c = i % 10;

			if ((b - a) == (c - b))
			{
				sum++;
			}
		}
	}

	cout << sum;
}