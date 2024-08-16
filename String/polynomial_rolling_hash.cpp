#include<bits/stdc++.h>
using namespace std;

// Always use base more than number of different character
// base=33,mod=1e9+7
const int N = 1e6 + 5;
const int mod = 1e9 + 7, base = 33;
int pw[N], inv[N], Hash[N];

int add(int a, int b, int mod) {
    int res = (a + b) % mod;
    if (res < 0) {
        res += mod;
    }
    return res;
}

int mult(int a, int b, int mod) {
    int res = (a * 1ll * b) % mod;
    if (res < 0) {
        res += mod;
    }
    return res;
}

int binpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2)res = mult(res, a, mod);
        a = mult(a, a, mod);
        b /= 2;
    }
    return res;
}

// need to call this function once to initialise values
void precal() {
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = mult(pw[i - 1], base, mod);
    int pw_inv = binpow(base, mod - 2, mod);
    inv[0] = 1;
    for (int i = 1; i < N; ++i)
        inv[i] = mult(inv[i - 1], pw_inv, mod);
}

// Need to call this function once to create Hash array.
void build(string &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i)
        Hash[i] = add((i == 0) ? 0 : Hash[i - 1], mult(s[i] - 'a' + 1, pw[i], mod), mod);
}

int getHash(int l, int r) {
    int res = add(Hash[r], (l == 0) ? 0 : -Hash[l - 1], mod);
    res = mult(res, (l == 0) ? 1 : inv[l], mod);
    return res;
}


int main()
{
    int t; cin >> t;
    precal();
    while (t--) {
        string s; cin >> s;
        build(s);
    }
}