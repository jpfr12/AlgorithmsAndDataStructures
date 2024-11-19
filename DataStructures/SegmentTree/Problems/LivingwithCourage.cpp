    #include <bits/stdc++.h>
        
    typedef long long ll;
    typedef unsigned int long long ull;
    using namespace std;
    ll MOD = 1e9+7;
     
    //global
    int N, Q;
    vector<ll> vec;
     
    //classes
    class SegTree{
    public:
        ll sum = 0;
        ll mn;
        int left, right;
        SegTree* leftChild = NULL;
        SegTree* rightChild = NULL;
     
        SegTree(vector<ll>& vec, int l, int r){
            left = l;
            right = r;
            if(l == r){
                sum = vec[l];
                mn = vec[l];
                return;
            }
            int mid = l + (r-l)/2;
            leftChild = new SegTree(vec, l, mid);
            rightChild = new SegTree(vec, mid+1, r);
            sum = leftChild->sum + rightChild->sum;
            mn = min(leftChild->mn, rightChild->mn);
        }
     
        ll getMin(int l, int r){
            if(left > r || right < l) return 1e9;
            if(left >= l && right <= r) return mn;
            return min(leftChild->getMin(l, r), rightChild->getMin(l, r));
        }
        
        ll getSum(int l, int r){
            if(left > r || right < l) return 0LL;
            if(left >= l && right <= r) return sum;
            return leftChild->getSum(l, r) + rightChild->getSum(l, r);
        }
     
        void updatePoint(int pos, ll val){
            if(left == right && left == pos){
                sum += val;
                mn = sum;
                return;
            }
            if(pos <= leftChild->right) leftChild->updatePoint(pos, val);
            else if(pos >= rightChild->left) rightChild->updatePoint(pos, val);
            sum = leftChild->sum + rightChild->sum;
            mn = min(leftChild->mn, rightChild->mn);
        }
     
    };
     
        
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //stop
        cin >> N;
        vec.resize(N);
        for(ll& i: vec) cin >> i;
        SegTree* st = new SegTree(vec, 0, N-1);
        cin >> Q;
        while(Q--){
            string str;
            cin >> str;
            if(str == "EAT"){
                int pos;
                ll val;
                cin >> val >> pos;
                st->updatePoint(pos, val*(-1));
            }
            else if(str == "GROW"){
                ll val;
                int pos;
                cin >> val >> pos;
                st->updatePoint(pos, val);
            }
            else{
                int left, right;
                cin >> left >> right;
                cout << st->getSum(left, right) - st->getMin(left, right) << '\n';
            }
        }
        return 0;
    }  