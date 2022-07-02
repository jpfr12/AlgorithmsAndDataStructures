/*
Insertion sort algorithm with a exemple ready to test/run
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> insertionSort(vector<int>& vec){
    int n = vec.size();
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && vec[j-1] > vec[j]){
            swap(vec[j-1], vec[j]);
            j--;
        }
    }
    return vec;
}

int main(){
    vector<int> vec = {10, 4, 9, 2, 8};
    cout << "Before: ";
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
    vec = insertionSort(vec);
    cout << "After: ";
    for(int i: vec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}