#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    sort(data.begin(), data.end(), greater<int>());

    int start = 0;
    int end = n - 1;
    vector<int> after_data;

    while (start <= end)
    {
        after_data.push_back(data[start]);
        if (start != end)
        {
            after_data.push_back(data[end]);
        }
        start++;
        end--;
    }
    
    int temp = 0;
    int answer = 0;

    for (int i : after_data)
    {   
        //cout << temp << " " << i << endl;
        if (temp < i)
        {   
            
            answer += i - temp;
        }
        temp = i;
    }

    cout << answer << endl;
}
