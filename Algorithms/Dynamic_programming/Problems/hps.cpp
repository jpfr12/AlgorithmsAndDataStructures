#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long int ull;
using namespace std;
const ll MOD = (ll)1e9+7;
int MAXN = 1e6;

//classes



//global
int n, k;
vector<int> vec;
vector<vector<vector<ll>>> dp;
map<int,int> Map;


/*
P = 0;
S = 1;
H = 2
*/
ll sol(int index, int cur, int turn){
  if(index >= n) return 0;
  if(dp[index][cur][turn] != -1) return dp[index][cur][turn];
  if(turn == 0){
    dp[index][cur][turn] = (Map[cur] == vec[index]) + sol(index+1, cur, 0);
  }
  else{
    dp[index][cur][turn] = (Map[cur] == vec[index]) + sol(index+1, cur, turn);
    for(int i = 0; i <= 2; i++){
      if(i == cur) continue;
      dp[index][cur][turn] = max(dp[index][cur][turn], (Map[cur] == vec[index]) + sol(index+1, i, turn-1));
    }
  }
  return dp[index][cur][turn];
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("hps.in");
  ofstream fout("hps.out");
  //stop
  fin >> n >> k;
  vec.resize(n);
  dp.resize(n, vector<vector<ll>>(3, vector<ll>(k+1, -1)));
  for(int& i: vec){
    char c;
    fin >> c;
    if(c == 'P') i= 0;
    else if(c == 'S') i = 1;
    else i = 2;
  }
  Map[0] = 2;
  Map[1] = 0;
  Map[2] = 1;
  ll ans = max(sol(0, 0, k), max(sol(0, 1, k), sol(0, 2, k)));
  fout << ans << '\n';
  return 0;
}
