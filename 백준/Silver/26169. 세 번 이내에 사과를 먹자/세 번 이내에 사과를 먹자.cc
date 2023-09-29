#include <iostream>
#include <vector>
using namespace std;

/* 백준 26169번: 세 번 이내에 사과를 먹자

0 0 1 0 0
0 0 -1 0 0
0 0 1 0 0
1 1 -1 1 0
0 0 0 -1 0
4 1

0 0 1 0 0
0 0 -1 0 0
0 0 1 0 0
1 0 -1 1 0
0 0 0 -1 0
2 3

*/

struct value
{
    int cost;
    int dep;
};

int xD[4] = {0, 1, -1, 0};
int yD[4] = {1, 0, 0, -1};

vector<vector<int>> board;
vector<vector<int>> cost;
bool answer;

void DFS(int x, int y, int depth)
{
    int temp = board[x][y];
    if (depth >= 3)
    {
        if (cost[x][y] >= 2)
            answer = true;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int xA = x + xD[i];
            int yA = y + yD[i];
            if(xA >=5 || yA>=5 || xA <0 || yA <0) continue;
            if(board[xA][yA] == -1) continue;

            if(board[xA][yA] == 1) {
                cost[xA][yA] = max(cost[xA][yA], cost[x][y] + 1);
            } else {
                cost[xA][yA] = max(cost[xA][yA], cost[x][y]);
            }
            board[x][y] = -1;
            DFS(xA, yA, depth + 1);
        }
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        vector<int> temp;
        vector<int> temp2;
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
            temp2.push_back(0);
        }
        cost.push_back(temp2);
        board.push_back(temp);
    }
    int r, c;
    cin >> r >> c;

    DFS(r, c, 0);
    cout << answer;
}