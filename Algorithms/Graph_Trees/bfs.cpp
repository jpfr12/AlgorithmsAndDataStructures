/*
this program counts the number of steps you need to take starting from node 1 to the other nodes
on a direct but unweighted graph.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[4];
int dist[4];
queue<int> q;
vector<vector<int>> vec(4);

void bfs(int x){
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        for(auto v: vec[pos]){
            if(visited[v]) continue;
            visited[v] = true;
            dist[v] = dist[pos] +1;
            q.push(v);
        }
    }
    
}

int main(void){
    vec[0].push_back(1);
    vec[1].push_back(2);
    vec[1].push_back(3);
    vec[2].push_back(3);
    vec[3].push_back(0);
    bfs(1);
    for(auto i: dist){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
