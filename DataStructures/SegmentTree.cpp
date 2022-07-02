#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegTree{
private:
    int n;
    vector<int> A, st, lazy;

    int left(int p){
        return p << 1;
    }

    int right(int p){
        return (p << 1) +1;
    }

    int conquer(int a, int b){
        if(a == -1) return b;
        if(b == -1) return a;
        return min(a, b);
    }

    void build(int p, int L, int R){
        if(L == R){
            st[p] = A[L];
        }
        else{
            int m = (L+R)/2;
            build(left(p), L, m);
            build(right(p), m+1, R);
            st[p] = conquer(st[left(p)], st[right(p)]);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p] != -1){
            st[p] = lazy[p];
            if(L != R){
                lazy[left(p)] = lazy[right(p)] = lazy[p];
            }
            else{
                A[L] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    int RMQ(int p, int L, int R, int i, int j){
        propagate(p, L, R);
        if(i > j) return -1;
        if( (L>= i) && (R <= j)) return st[p];
        int m = (L+R)/2;
        return conquer(RMQ(left(p), L, m, i, min(m, j)), RMQ(right(p), m+1, R, max(i, m+1), j) );
    }

    void update(int p, int L, int R,int i, int j, int val){
        propagate(p, L, R);
        if(i >j) return;
        if((L >= i) && (R <= j)){
            lazy[p] = val;
            propagate(p, L, R);
        }
        else{
            int m = (L+R)/2;
            update(left(p), L, m, i, min(m, j), val);
            update(right(p), m+1, R, max(i, m+1), j, val);
            int lsubtree = (lazy[left(p)] != -1) ? lazy[left(p)] : st[left(p)];
            int rsubtree = (lazy[right(p)] != -1) ? lazy[right(p)]: st[right(p)];
            st[p] = (lsubtree <= rsubtree) ? st[left(p)] : st[right(p)];
        }
    }
public:
    SegTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {
        
    }

    SegTree(vector<int>& initialA): SegTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }

    void update(int i,int j, int val){
        update(1, 0, n-1, i, j, val);
    }

    int RMQ(int i, int j){
        return RMQ(1, 0, n-1, i, j);
    }
};

int main(){
    vector<int> vec = {33, 47, 10, -100, 89, 64, 0};
    int n = vec.size()-1;
    cout << "max value: " << n << endl;
    SegTree* seg = new SegTree(vec);
    int l, r;
    while(true){
        cout << "====================MENU====================\n";
        cout << "working array: {";
        for(int i = 0; i <= n; i++){
            if(i == n) cout << vec[i];
            else cout << vec[i] << ", ";
        } 
        cout << "}\n";
        cout << "1 - Select range" << endl;
        cout << "2 - Update point" << endl;
        int selection;
        cout << "Select an option: ";
        cin >> selection;
        if(selection == 1){
            cout << "Insert left number: ";
            cin >> l;
            cout << "Insert right number: ";
            cin >> r;
            cout << seg->RMQ(l, r) << endl;
        }
        else if(selection == 2){
            int index, value;
            cout << "Insert index: ";
            cin >> index;
            cout << "Insert new value: ";
            cin >> value;
            vec[index] = value;
            seg->update(index, index, value);
        }
        else break;
    }
    
    return 0;
}


//Segment Tree increment value
class SegTree{
private:
    int n;
    vector<int> A, st, lazy;

    int left(int p){
        return p << 1;
    }

    int right(int p){
        return (p << 1) +1;
    }

    int conquer(int a, int b){
        if(a == -1) return b;
        if(b == -1) return a;
        return a + b;
    }

    void build(int p, int L, int R){
        if(L == R){
            st[p] = A[L];
        }
        else{
            int m = (L+R)/2;
            build(left(p), L, m);
            build(right(p), m+1, R);
            st[p] = conquer(st[left(p)], st[right(p)]);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p] != 0){
            st[p] += lazy[p];
            if(L != R){
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }
            else{
                A[L] = lazy[p];
            }
            lazy[p] = 0;
        }
    }

    int RMQ(int p, int L, int R, int i, int j){
        propagate(p, L, R);
        if(i > j) return -1;
        if( (L>= i) && (R <= j)) return st[p];
        int m = (L+R)/2;
        return conquer(RMQ(left(p), L, m, i, min(m, j)), RMQ(right(p), m+1, R, max(i, m+1), j) );
    }

    void update(int p, int L, int R,int i, int j, int val){
        propagate(p, L, R);
        if(i >j) return;
        if((L >= i) && (R <= j)){
            lazy[p] = val;
            propagate(p, L, R);
        }
        else{
            int m = (L+R)/2;
            update(left(p), L, m, i, min(m, j), val);
            update(right(p), m+1, R, max(i, m+1), j, val);
            int lsubtree = (lazy[left(p)] != -1) ? lazy[left(p)] : st[left(p)];
            int rsubtree = (lazy[right(p)] != -1) ? lazy[right(p)]: st[right(p)];
            st[p] = st[left(p)] + st[right(p)];
        }
    }
public:
    SegTree(int sz) : n(sz), st(4*n), lazy(4*n, 0) {
        
    }

    SegTree(vector<int>& initialA): SegTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }

    void update(int i,int j, int val){
        update(1, 0, n-1, i, j, val);
    }

    int RMQ(int i, int j){
        return RMQ(1, 0, n-1, i, j);
    }
};