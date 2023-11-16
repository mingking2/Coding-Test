#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> files;
long long n, num;


bool checking(long long col) {
    for (long long k = 0; k < n; k++)
    {
        for (long long j = k + 1; j < n; j++)
        {
            vector<long long> subseqA(files[k].begin(), files[k].begin() + col + 1);
            vector<long long> subseqB(files[j].begin(), files[j].begin() + col + 1);
            
            if (subseqA == subseqB) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    long long max = -1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<long long> input;
        while (true)
        {
            cin >> num;
            if (num == -1)
                break;
            input.push_back(num);
        }
        files.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        long long size = files[i].size();
        if (size > max)
        {
            max = size;
        }
    }

    for (int i = 0; i < n; i++)
    {   
        if (files[i].size() != max) {
            long long size1 = max - files[i].size();
            for (int k = 0; k < size1; k++)
            {
                files[i].push_back(0);
            }
        }
            
    }

    long long ch = 0;
    for(int i=0;i<max;i++) {
        if(checking(i)) {
            ch = i+1;
            break;
        }
    }

    cout << ch << endl;
}