#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<long long int> ans;

int main()
{
    int T;
    int num;
    cin >> T;

    while (T != 0)
    {
        vector<long long int> buy;
        while (true)
        {
            cin >> num;
            if (num == 0)
                break;
            buy.push_back(num);
        }
        num = 1;

        sort(buy.begin(), buy.end(), [](int a, int b)
             {
                 return a > b; // 비교 함수에서 a > b로 설정하여 내림차순 정렬
             });

        // for(int i=0;i<buy.size();i++) {
        //     cout << buy[i] << " ";
        // }
        // cout << endl;

        // cout << buy.front() << " " << buy.back() << endl;

        long long int sum = 0;
        for (int i = 0; i < buy.size(); i++)
        {
            sum += 2 * pow(buy[i], i + 1);
        }

        ans.push_back(sum);

        T -= 1;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] < 5 * pow(10, 6))
        {
            cout << ans[i] << endl;
        }
        else
        {
            cout << "Too expensive" << endl;
        }
    }
}