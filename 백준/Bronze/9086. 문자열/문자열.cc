#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string a;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cout << a[0] << a[a.size() - 1] << endl;
    }
}