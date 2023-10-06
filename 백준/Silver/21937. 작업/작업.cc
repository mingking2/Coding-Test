#include <iostream>
#include <vector>
using namespace std;

vector<int> board[100005];
bool visited[100005] = {false, };

int dfs(int end) {
    int sum = 0;
    visited[end] = true;
    //cout << "end: " <<end<<endl;
    for(auto to: board[end]) {
        //cout << "to: " <<to<<endl;
        if(!visited[to]) sum += dfs(to) + 1;
    }
    return sum;
}

int main () {
    int n,m;
    cin >> n>> m;
    
    int a,b,end;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        board[b].push_back(a);
    }

    cin >> end;

    cout << dfs(end) << endl;

}