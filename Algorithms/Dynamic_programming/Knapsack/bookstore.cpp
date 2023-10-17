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
using namespace std;
 
//classes
 
 
 
//global
 
 
 
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //stop
  int n, x;
  cin >> n >> x;
  vector<vector<int>> dp(n+1, vector<int>(x+1));
  vector<int> price(n);
  vector<int> pages(n);
  for(int& i: price) cin >> i;
  for(int& i: pages) cin >> i;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= x; j++){
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if(left >= 0) dp[i][j] = max(dp[i][j], dp[i-1][left] + pages[i-1]);
    }
  }
  cout << dp[n][x] << '\n';
  return 0;
}