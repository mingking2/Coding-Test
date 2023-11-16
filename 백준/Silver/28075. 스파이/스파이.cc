#include <iostream>
using namespace std;

int n, m;
int infor[2][3];
int count = 0;

void countWays(int days, int sum, int place)
{
    if (days == n)
    {
        if (sum >= m)   count++;
        return;
    }

    if (days == 0)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                countWays(days + 1, sum + infor[i][j], j);
    }
    else
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                if (j == place)
                    countWays(days + 1, sum + infor[i][j] / 2, j);
                else
                    countWays(days + 1, sum + infor[i][j], j);
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> infor[i][j];
        }
    }

    countWays(0, 0, 0);
    cout << count << endl;
}