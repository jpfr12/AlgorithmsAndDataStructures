#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long int ull;
using namespace std;
const ll MOD = (ll)1e9+7;
int MAXN = 1e6;

//classes



//global
int N;
vector<ll> coins = { 2, 5, 10, 20, 50, 100};
vector<ll> vec;
vector<vector<ll>> dp;

ll sol(int index, int sum){
  if(index == 6) return sum == 0;
  if(dp[index][sum] != -1) return dp[index][sum];
  dp[index][sum] = 0;
  for(int i = 0; i <= vec[index]; i++){
    if(sum - i*coins[index] >= 0) dp[index][sum] += sol(index+1, sum - i*coins[index]);
  }
  return dp[index][sum];
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //ifstream fin("hps.in");
  //ofstream fout("hps.out");
  //stop
  cin >> N;
  vec.resize(6);
  for(ll& i: vec) cin >> i;
  dp.resize(6, vector<ll>(N+1, -1));
  cout << sol(0, N) << '\n';
  return 0;
}
