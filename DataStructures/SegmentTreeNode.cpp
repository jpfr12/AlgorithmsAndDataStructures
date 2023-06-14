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
class SegTree{
  public:
  int sum;
  int left, right;
  SegTree* node_left = NULL;
  SegTree* node_right = NULL;

  SegTree(vector<int>& vec, int l, int r){
    left = l;
    right = r;
    if(l == r){
      sum = vec[l];
      return;
    }
    else{
      int mid = (left+right)/2;
      node_left = new SegTree(vec, l, mid);
      node_right = new SegTree(vec, mid+1, r);
      sum = node_left->sum + node_right->sum;
    }
  }

  void pointUpdate(int index, int val){
    if(left == right){
      this->sum += val;
      return;
    }
    if(index <= node_left->right) node_left->pointUpdate(index, val);
    else{
      node_right->pointUpdate(index, val);
    }
    this->sum = node_left->sum + node_right->sum;

  }

  int rangeSum(int l, int r){
    if(l > right || r < left) return 0;
    if(l <= left && r >= right){
      return sum;
    }
    return node_left->rangeSum(l, r) + node_right->rangeSum(l, r);
  }

};



//global




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //stop
  int n, t;
  cin >> n >> t;
  vector<int> vec(n);
  SegTree* st = new SegTree(vec, 0, n-1);
  while(t--){
    string s;
    int a, b;
    cin >> s >> a >> b;
    if(s == "find") cout << st->rangeSum(a-1, b-1)<< '\n';
    else st->pointUpdate(a-1, b);
  }
  return 0;
}