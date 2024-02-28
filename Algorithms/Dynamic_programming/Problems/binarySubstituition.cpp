#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
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
#include <assert.h>
#include <fstream>
#include <bitset>
#include <iomanip>
 
typedef long long ll;
typedef unsigned long long int ull;
using namespace std;
int MOD = 998244353; //(int)1e9+7;
int MAXN = 1e6;
 
//classes
 
 
 
//global
ll n;
string s;
vector<ll> dp;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //ifstream fin("longpath.in");
  //ofstream fout("longpath.out");
  //stop
  int t;
  cin >> t;
  while(t--){
    cin >> s;
    n = s.length();
    dp.resize(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
      if(s[i-1] == 'a'){
        dp[i] += dp[i-1];
        dp[i] %= MOD;
      }
      if(s[i-1] == 'b'){
        dp[i] += dp[i-1];
        dp[i] %= MOD;
      }
      if(i-2 >= 0 && s[i-2] == 'a' && s[i-1] == 'b'){
        dp[i] += dp[i-2];
        dp[i] %= MOD;
      }
      if(i-2 >= 0 && s[i-2] == 'b' && s[i-1] == 'a'){
        dp[i] += dp[i-2];
        dp[i] %= MOD;
      }
    }
    cout << dp[n] << '\n';
    dp.clear();
  }
  return 0;
} 