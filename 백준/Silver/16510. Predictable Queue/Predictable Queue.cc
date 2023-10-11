#include <iostream>
#include <vector>
 
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0, M = 0;
    long long input = 0, sum = 0;
 
    vector<long long> v;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        sum += input;
        v.push_back(sum);
    }
    
    int s = v.size();
    
    
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        int cnt = 0;
 
        int left = 0, right = s - 1;
 
        int mid = 0;
        while (left <= right) {
 
            mid = (left + right) / 2;
            
            if (v.at(mid) > input)
                right = mid - 1;
            else if (v.at(mid) <= input)
                left = mid + 1;    
        }
        cnt = left;
        
        cout << cnt << "\n";
    }
 
 
    return 0;
}