#include <iostream>
using namespace std;

int dp[1000] = {};
int n, k;

int DP(int j) {
	for (int i = 3; i <= j; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[j] = dp[i];
	}
	return dp[j];
}

int main() {
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int j;
	for (int i = 1; i <= n; i++) {
		cin >> j;
		cout << DP(j) << '\n';
	}
}