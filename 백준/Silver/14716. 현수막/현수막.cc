#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> board;
vector<vector<bool>> visited;

int xD[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int yD[8] = {1, 0, 0, -1, 1, -1, -1, 1};

void DFS(int x, int y) {
    visited[x][y] = true; // 방문 표시

    for(int i=0;i<8;i++) {
        int xA = x + xD[i]; // 다음 위치 계산
        int yA = y + yD[i];

        if (xA >= M || yA >= N || xA < 0 || yA < 0) continue; // 범위 체크

        if (board[xA][yA] == 1 && !visited[xA][yA]) {
            DFS(xA,yA);
        }
    }

}

int main() {
    cin >> M >> N;

    board.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false)); // 초기값은 모두 false로 설정

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

   int count = 0;

   for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if (board[i][j] == 1 && !visited[i][j]) { // 현수막의 값이 '1'이고 아직 방문하지 않았다면
                DFS(i,j); // DFS 탐색 수행
                count++; // 덩어리 개수 증가
            }
        }
    }

   cout << count << endl; // sum 출력
    
}
