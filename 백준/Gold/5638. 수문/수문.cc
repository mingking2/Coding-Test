#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct DamGate {
    long long flow;  // 유량
    long long cost;  // 비용
};

int main() {
    int n; // 수문의 개수
    cin >> n;
    vector<DamGate> gates(n);

    for (int i = 0; i < n; ++i) {
        cin >> gates[i].flow >> gates[i].cost;
    }

    int m; // 테스트 케이스의 수
    cin >> m;

    for (int t = 0; t < m; ++t) {
        long long V, T;
        cin >> V >> T;

        long long minCost = LLONG_MAX;

        // 모든 수문 조합에 대해 루프
        for (int mask = 0; mask < (1 << n); ++mask) {
            long long totalFlow = 0;
            long long totalCost = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    totalFlow += gates[i].flow;
                    totalCost += gates[i].cost;
                }
            }

            if (totalFlow * T >= V && totalCost < minCost) {
                minCost = totalCost;
            }
        }

        cout << "Case "<< t+1 << ": ";
        if (minCost == LLONG_MAX) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout <<minCost << endl;
        }
    }

    return 0;
}
