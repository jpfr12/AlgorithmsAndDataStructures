#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long int ull;
using namespace std;
const ll MOD = (ll)1e9+7;
int MAXN = 1e6;

//classes



//global
int N;
int M;
vector<int> dp;
vector<vector<int>> graph;

int sol(int pos){
  if(dp[pos] != -1) return dp[pos];
  dp[pos] = 0;
  for(int& i: graph[pos]){
    dp[pos] = max(dp[pos], 1 + sol(i));
  }
  return dp[pos];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //ifstream fin("optmilk.in");
  //ofstream fout("optmilk.out");
  //stop
  cin >> N >> M;
  graph.resize(N+1);
  for(int i = 0; i < M; i++){
    int start, end;
    cin >> start >> end;
    graph[start].push_back(end);
  }
  dp.assign(N+1, -1);
  int ans = 0;
  for(int i = 1; i <= N; i++){
    ans = max(ans, sol(i));
  }
  cout << ans << '\n';
  return 0;
}
