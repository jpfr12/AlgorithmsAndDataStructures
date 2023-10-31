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
int MOD = (int)1e18;
int MAXN = 1e6;

//classes



//global


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //ifstream fin("teleport.in");
  //ofstream fout("teleport.out");
  //stop
  int n, h;
  cin >> n >> h;
  vector<int> slide(h);
  bool floor = true;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    if(floor){
      slide[0]++;
      slide[a]--;
    }
    else{
      slide[h-a]++;
    }
    floor = !floor;
  }
  int cost = 0;
  int ans = 1e9, mi = 0;
  for(int i = 0; i < h; i++){
    slide[i] += cost;
    cost = slide[i];
    if(slide[i] < ans){
      ans = slide[i];
      mi = 1;
    }
    else if(slide[i] == ans) mi++;
  }
  cout << ans << " " << mi << '\n';
  return 0;
}
