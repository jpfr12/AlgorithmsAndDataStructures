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

//classes


//global
vector<vector<pair<int,int>>> graph;
vector<int> taken;
priority_queue<pair<int,int>> pq;

void prim(int pos){
    
    taken[pos] = 1;
    for(auto& i: graph[pos]){
        if(!taken[i.first]){
            pq.emplace(-i.second, -i.first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //stop
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].emplace_back(b, cost);
        graph[b].emplace_back(a, cost);
    }
    taken.resize(n);
    prim(0);
    int mst_cost = 0;
    int many = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        p.first = -p.first;
        p.second = -p.second;
        if(taken[p.second]) continue;
        mst_cost += p.first;
        prim(p.second);
        many++;
        if(many == n-1)break;
    }
    cout << mst_cost << endl;
    return 0;
}