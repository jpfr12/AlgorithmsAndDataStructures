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
    for(int& i: vec){
        cin >> i;
    }
    vector<int> ans_right(n);
    stack<pair<int,int>> S;
    for(int i = n-1; i >= 0; i--){
        while(!S.empty() && S.top().first >= vec[i]){
            S.pop();
        }
        ans_right[i] = (S.empty() ? -1: S.top().second - i-1);
        S.emplace(vec[i], i);
    }
    stack<pair<int,int>> S1;
    vector<int> ans_left(n);
    for(int i = 0; i < n; i++){
        while(!S1.empty() && S1.top().first >= vec[i]){
            S1.pop();
        }
        ans_left[i] = (S1.empty() ? -1: i-S1.top().second-1);
        S1.emplace(vec[i], i);
    }
    for(int i = 0; i < n; i++){
        cout << (ans_left[i] == -1 || ans_right[i] == -1 ? -1: ans_left[i] + ans_right[i]) << " ";
    }
    cout << '\n';
  }
  return 0;
} 