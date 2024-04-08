#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
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
const int MOD = (int)1e9+7;
int MAXN = 1e6;
 
//classes
 
 
 
//global



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //ifstream fin("longpath.in");
  //ofstream fout("longpath.out");
  //stop
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int& i: vec) cin >> i;
  stack<pair<int,int>> S;
  int mx = 0;
  for(int i = n-1; i >= 0; i--){
    while(!S.empty() && vec[i] >= S.top().first){
      S.pop();
    }
    S.emplace(vec[i], (S.empty() ? vec[i]: vec[i] ^S.top().second));
    mx = max(mx, S.top().second);
  }
  cout << mx << '\n';
  return 0;
} 