#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

//global
ll MAXN = 1e6;
ll MOD = 1e9;

vector<ll> fac(MAXN + 1), inv(MAXN + 1);
		
/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

/** Precomputes all modular inverse factorials from 0 to MAXN in O(n log p) time */
void inverses(long long p) {
	inv[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		inv[i] = exp(fac[i], p - 2, p);
	}
}
		
/** Computes nCr mod p */
long long nCr(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

/** Computes nPr mod p */
long long nPr(long long n, long long r, long long p) {
	return fac[n] * inv[n - r] % p;
}