#include <iostream>
#define REST 998244353
using namespace std;

/*
백준 22971번: 증가하는 부분 수열의 개수


5
1 2 3 4 5

5
1 1 1 1 1

5
1 2 2 4 3
*/

int main()
{
    int N, A, sum;
    cin >> N;

    int *arr = new int[N];
    int *test = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        test[i] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i]){
                test[i] += test[j];
                test[i] %= REST;
            }
        }
    }

    for(int i=0; i<N; i++) 
    {
        cout << test[i] << " ";
    }


}