#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <bitset>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;

//global
vector<vector<pair<ll,ll>>> graph;
vector<ll> dis;

//Dijkstra
void bfs(int pos){
    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    dis[pos] = 0;
    pq.emplace(0, pos);
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        int val = p.first;
        int node = p.second;
        if(val > dis[node]) continue;
        for(auto i: graph[node]){
            if(val + i.first >= dis[i.second]) continue;
            dis[i.second] = val + i.first;
            pq.emplace(dis[i.second], i.second);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //stop
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    dis.resize(n+1, LONG_MAX);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }
    bfs(1);
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}