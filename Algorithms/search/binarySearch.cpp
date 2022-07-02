/*
this program will tell how many times the while loop will run until finding your value
if it returns -1, it means the number you entered is out of range
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int val){
    int left = 0, right = 1e9;
    int counter = 0;
    while(left <= right){
        counter++;
        int mid = (left+right)/2;
        if(mid == val) return counter;
        else if(val < mid){
            right = mid-1;
        }
        else left = mid +1;
    }
    return -1;
}

int main(){
    int val;
    cout << "Insert a number from 0 (zero) to 10^9: ";
    cin >> val;
    cout << binarySearch(val) << endl;
    return 0;
}