#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> one, vector<int> two){
    vector<int> ans;
    while(one.size() > 0 && two.size() > 0){
        if(one[0] <= two[0]){
            ans.push_back(one[0]);
            one.erase(one.begin());
        }
        else{
            ans.push_back(two[0]);
            two.erase(two.begin());
        }
    }
    while(one.size() > 0){
        ans.push_back(one[0]);
        one.erase(one.begin());
    }

    while(two.size() > 0){
        ans.push_back(two[0]);
        two.erase(two.begin());
    }
    return ans;
}

vector<int> mergeSort(vector<int> a){
    int len = a.size();
    if(len == 1) return a;

    vector<int> l;
    vector<int> r;
    for(int i = 0; i < a.size(); i++){
        if(i < a.size()/2) l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    
    vector<int> one = mergeSort(l);
    vector<int> two = mergeSort(r);

    return merge(one, two);
}


int main(){
    vector<int> a = {6, 5, 4, 3, 2, 1};
    vector<int> ans = mergeSort(a);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}