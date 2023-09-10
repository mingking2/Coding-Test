#include <iostream>
using namespace std;

//int main() {
//	cin.tie(NULL);
//	cin.sync_with_stdio(false);
//
//	int num = 0; 
//	int sum = 0;
//	int Arr[42] = { 0, };
//	for (int i = 0; i < 10; i++) {
//		cin >> num;
//		Arr[num % 42]++;
//	}
//
//	for (int i = 0; i < 42; i++) {
//		if (Arr[i] > 0)
//			sum++;
//	}
//
//	cout << sum;
//	
//
//}		// 다시 공부

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N;
	double max = -100;
	double sum=0;
	double grade[100000];
	double fixgrade[100000];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> grade[i];
		if (max < grade[i])
		{
			max = grade[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		fixgrade[i] = ((grade[i] / max) * 100);
		sum += fixgrade[i];
	}

	double res = sum / N;

	cout << res << endl;
	return 0;

}