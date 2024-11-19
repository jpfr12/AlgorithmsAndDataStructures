#include <bits/stdc++.h>
    
typedef long long ll;
typedef unsigned int long long ull;
using namespace std;
ll MOD = 1e9+7;

//global
int N, M;
vector<vector<int>> tree;
vector<int> euler;
vector<int> rightLimit;
vector<int> leftLimit;
vector<ll> salary;

//classes
class SegTree{
    public:
    int left, right;
    ll lazy = -1;
    SegTree* leftChild = NULL;
    SegTree* rightChild = NULL;


    SegTree(vector<int>& vec, int l, int r){
        left = l;
        right = r;
        if(l == r) return;
        int mid = l + (r-l)/2;
        leftChild = new SegTree(vec, l, mid);
        rightChild = new SegTree(vec, mid+1, r);
    }

    void updateSalary(int l, int r, ll many){
        if(lazy != -1 && left < right){
            conquer(leftChild, lazy);
            conquer(rightChild, lazy);
            lazy = -1;
        }
        if(left > r || right < l ) return;
        if(left >= l && right <= r){
            if(lazy == -1) lazy = many;
            else lazy += many;
            return;
        }
        leftChild->updateSalary(l, r, many);
        rightChild->updateSalary(l, r, many);
    }
    
    void conquer(SegTree* node, ll cost){
        if(node){
            node->lazy = (node->lazy == -1? cost: node->lazy+cost);
            
        }
    }

    ll getSalary(int l, int r, int pos){
        if(lazy != -1 && left < right){
            conquer(leftChild, lazy);
            conquer(rightChild, lazy);
            lazy = -1;
        }
        if(left > r || right < l) return 0;
        if(left == right){
            if(lazy != -1){
                salary[pos] += lazy;
                lazy = -1;
            }
            return (left == leftLimit[pos] ?salary[pos]:0);
        }
        return leftChild->getSalary(l, r, pos) + rightChild->getSalary(l, r, pos);
    }

};

void dfs(int pos, int& index){
    euler.push_back(pos);
    index++;
    leftLimit[pos] = index;
    for(int& i: tree[pos]){
        dfs(i, index);
    }
    rightLimit[pos] = index;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //stop
    cin >> N >> M;
    tree.resize(N);
    rightLimit.resize(N);
    leftLimit.resize(N);
    salary.resize(N);
    for(int i = 0; i < N; i++){
        int parent;
        cin >> parent;
        if(i > 0) tree[parent].push_back(i);
    }
    for(int i = 0; i < N; i++) cin >> salary[i];
    int index = -1;
    dfs(0, index);
    SegTree* st = new SegTree(euler, 0, N-1);
    while(M--){
        int t;
        cin >> t;
        if(t == 0){
            int x; 
            ll d;
            cin >> x >> d;
            st->updateSalary(leftLimit[x], rightLimit[x], d);
        }
        else{
            int x;
            cin >> x;
            cout << st->getSalary(leftLimit[x], leftLimit[x], x) << '\n';
        }
    }
    return 0;
} 