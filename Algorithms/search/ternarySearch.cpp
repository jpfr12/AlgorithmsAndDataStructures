/*
this program asks the user to insert a target number from 0 to 10^9
using ternary search, it tells how many times the while loops is used
*/

#include <iostream>

using namespace std;

int ternary(){
    int target;
    cout << "Insert number to search between 0-10^9: ";
    cin >> target;
    int left = 0, right = 1e9;
    int steps = 0;
    while(left <= right){
        steps++;
        int mid1 = left + (right-left)/3;
        int mid2 = right - (right- left)/3;
        if(target == mid1 || target == mid2){
            return steps;
        }
        if(target < mid1){
            right = mid1-1;
        }
        else if( target > mid2){
            left = mid2+1;
        }
        else{
            left = mid1+1;
            right = mid2-1;
        }
    }
    return -1;
}

int main(){
    cout << ternary() << endl;
    return 0;
}