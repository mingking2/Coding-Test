#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<bool>> visited;
string answer;

void DFS(int x, int y)
{
    if (x >= N || y >= N)
    {
        return;
    }

    int jump = board[x][y];
    if (jump == -1)
    {
        answer = "HaruHaru";
        return;
    }

    // 오른쪽으로 점프
    int nx = x + jump;
    int ny = y;

    if (nx >= 0 && nx < N && !visited[nx][ny]) { // 아직 방문하지 않은 경우에만 재귀 호출
        visited[nx][ny] = true; // 방문 체크
        DFS(nx, ny);
    }

    // 아래쪽으로 점프
    nx = x;
    ny = y + jump;

    if (ny >= 0 && ny < N && !visited[nx][ny]) { // 아직 방문하지 않은 경우에만 재귀 호출
        visited[nx][ny] = true; // 방문 체크
        DFS(nx, ny);
   }
}

int main()
{

    cin >> N;

    board.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false)); // 초기값은 모두 false로 설정

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    answer = "Hing";
    visited[0][0] = true; // 시작 위치(0, 0)를 방문했다고 표시
    DFS(0, 0);

    cout << answer;

    return 0;
}
