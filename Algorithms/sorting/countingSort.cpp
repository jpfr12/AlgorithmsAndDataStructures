#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> countingSort(vector<int>& vec){
    int n = vec.size();
    map<int,int> Map;
    for(int& i: vec){
        Map[i]++;
    }
    vec.clear();
    vec.resize(n, -1e9);
    int index = 0;
    for(auto& i: Map){
        vec[index] = i.first;
        index += i.second;
    }
    for(int i = 1; i < n; i++){
        if(vec[i] == -1e9) vec[i] = vec[i-1];
    }
    return vec;
}

int main(){
    vector<int> vec = {10, 4, 9, 2, 4};
    cout << "Before: ";
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
    vec = countingSort(vec);
    cout << "After: ";
    for(int i: vec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}