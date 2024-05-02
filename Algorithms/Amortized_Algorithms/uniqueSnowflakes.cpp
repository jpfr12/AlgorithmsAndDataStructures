#include <bits/stdc++.h>
 
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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int& i: vec) cin >> i;
    int mx = 0;
    int left = 0;
    map<int,int> M;
    for(int i = 0; i < n; i++){
      M[vec[i]]++;
      while(M[vec[i]] > 1){
        M[vec[left]]--;
        left++;
      }
      mx = max(mx, i-left+1);
    }
    cout << mx << '\n';
  }
  return 0;
} 