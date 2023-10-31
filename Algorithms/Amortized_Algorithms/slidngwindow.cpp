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
ll MOD = -1e9;
ll MAXN = 1e6;
 
//classes
 
 
 
//global
int bs(int a, int target){
  int left = 1, right = 9;
  while(left <= right){
    int mid = (left+right)/2;
    if(a*mid == target) return mid;
    else if(target < a*mid) right = mid-1;
    else left = mid+1;
  }
  return -1;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //stop
  int n, t;
  cin >> n >> t;
  vector<ll> vec(n);
  for(ll& i: vec) cin >> i;
  while(t--){
    ll k;
    cin >> k;
    int left = 0;
    ll sum = 0;
    int len = 1e9;
    int l = 0, r = 0;
    for(int right = 0; right < n; right++){
      sum += vec[right];
      while( sum > k){
        sum -= vec[left];
        left++;
      }
      if(sum == k){
        if(right-left+1 < len){
          len = right-left+1;
          l = left;
          r = right;
        }
      }
    }
    cout << l << " " << r << '\n';
  }
  return 0;
}