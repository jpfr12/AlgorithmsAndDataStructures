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
class UnionFind{
    public:
    vector<int> p, rank, setSize;
    int numSets;

    UnionFind(int n){
        p.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        rank.resize(n, 0);
        setSize.resize(n, 1);
        numSets = n;
    }

    int findSet(int i){
        return p[i] == i ? i: (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
        setSize[y] += setSize[x];
        numSets--;
    }
};


//global
vector<tuple<int, int, int>> graph;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //stop
    return 0;
}