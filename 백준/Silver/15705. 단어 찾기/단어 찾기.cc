#include <iostream>
using namespace std;

string s;
int n, m;

char alpha[100][100];
bool visited[100][100];

// 상하좌우 및 대각선 8방향
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dfs(int x, int y, int length, int dir)
{
    if (length == s.length())
        return true;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    //cout << alpha[nx][ny] << " ";

    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
    {
        if (!visited[nx][ny] && alpha[nx][ny] == s[length])
        {
            visited[nx][ny] = true;
            if (dfs(nx, ny, length + 1, dir))
                return true;
            visited[nx][ny] = false; // 백트래킹
        }
    }

    return false;
}

int main()
{

    cin >> s;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> alpha[i][j];
            visited[i][j] = false; // visited 배열 초기화
        }
    }

    bool result = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (alpha[i][j] == s[0])
            {
                for (int dir = 0; dir < 8; ++dir)
                { // 모든 방향에 대해서 탐색을 시작합니다.
                    visited[i][j] = true;
                    if (dfs(i, j, 1, dir))
                    {
                        result = true;
                        break;
                    }
                    visited[i][j] = false; // 백트래크
                }
            }
            if (result)
                break;
        }

        if (result)
            break;
    }

    cout << result << endl;
}