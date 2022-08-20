#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;
typedef long long ll;

//Binary exponentiation
ll binpow(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1)  // if n is odd
			res = res * x % m;
		x = x * x % m;
		n /= 2;  // divide by two
	}
	return res;
}

//Greatest Common Divisor
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}