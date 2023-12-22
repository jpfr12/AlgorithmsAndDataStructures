#include <iostream>

using namespace std;

int main(){
    unsigned int num;
    cin >> num;
    unsigned int ans = 0;
    while(num){
        ans <<= 1;
        if(num&1) ans ^= 1;
        num >>= 1;
    }
    cout << ans << '\n';
    return 0;
}