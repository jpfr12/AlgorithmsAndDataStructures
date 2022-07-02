/*
this program counts the number of connected components of a given unweighted graph
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis(5);
vector<vector<int>> graph;

void dfs(int x){
    if(vis[x]) return;
    vis[x] = true;
    for(int i: graph[x]){
        dfs(i);
    }
}

int main(){
    graph = {{2,3}, {}, {3}, {4}, {3}};
    int islands = 0;
    for(int i = 0; i < 5; i++){
        if(vis[i]) continue;
        dfs(i);
        islands++;
    }
    cout << "The number of connected components is/are " << islands << endl;
    return 0;
}