#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int main()
{
    int w, h, n, sum = 0;
    vector<pair<int, int>> board;
    int d[2];

    cin >> w >> h >> n;

    int tmp1, tmp2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        board.push_back(make_pair(tmp1, tmp2));
    }

    cin >> d[0] >> d[1];

    for (int i = 0; i < n; i++)
    {
        if (d[0] == board[i].first)
            sum += abs(d[1] - board[i].second);
        else if (d[0] == 1 || d[0] == 2)
        {
            if (board[i].first == 3 || board[i].first == 4)
            {
                if (board[i].first == 3)
                    sum += d[1];
                else
                    sum += w - d[1];

                if (d[0] == 1)
                    sum += board[i].second;
                else
                    sum += h - board[i].second;
            }
            else
            {
                if (h + board[i].second + d[1] > h + w)
                    sum += 2 * (w + h) - (h + board[i].second + d[1]);
                else
                    sum += h + board[i].second + d[1];
            }
        }
        else
        {
            if (board[i].first == 1 || board[i].first == 2)
            {
                if (board[i].first == 1)
                    sum += d[1];
                else
                    sum += h - d[1];

                if (d[0] == 3)
                    sum += board[i].second;
                else
                    sum += w - board[i].second;
            }
            else
            {
                if (w + board[i].second + d[1] > h + w)
                    sum += 2 * (w + h) - (w + board[i].second + d[1]);
                else
                    sum += w + board[i].second + d[1];
            }
        }
    }

    cout << sum;
}