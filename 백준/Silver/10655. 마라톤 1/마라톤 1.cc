#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // 초기값 설정
    int totalDistance = 0;
    for (int i = 1; i < N; ++i) {
        totalDistance += abs(points[i].first - points[i - 1].first) + abs(points[i].second - points[i - 1].second);
    }

    int minDistance = totalDistance;
    for(int i=1; i<N-1;i++) {
        int jumpDistance = abs(points[i+1].first - points[i-1].first) + abs(points[i+1].second - points[i-1].second);
        int diff = abs(points[i + 1].first - points[i].first) + abs(points[i + 1].second - points[i].second)
            + abs(points[i].first - points[i - 1].first) + abs(points[i].second - points[i-1 ].second);

        minDistance = min(minDistance, totalDistance+jumpDistance-diff);
    }

    cout << minDistance << endl;
   
}