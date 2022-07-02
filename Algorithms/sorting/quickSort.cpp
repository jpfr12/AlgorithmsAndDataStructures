#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int>& vec, int lo, int hi){
    int piv = vec[hi];
    int pos = lo;
    for(int i = lo; i <= hi; i++){
        if(vec[i] < piv){
            swap(vec[i], vec[pos]);
            pos++;
        }
    }
    swap(vec[pos], vec[hi]);
    return pos;
}

void quick(vector<int>& vec, int lo, int hi){
    if(lo < hi){
        int pivot = partition(vec, lo, hi);
        quick(vec, lo, pivot-1);
        quick(vec, pivot+1, hi);
    }
    
}

int main(){
    vector<int> vec = {9,6,5,4,3,2,1};
    int n = vec.size()-1;
    quick(vec, 0, n);
    for(int i: vec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}