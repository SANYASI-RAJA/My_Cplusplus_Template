const int M = 1e9 + 7;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
        res = res % M;
        a = a % M;
    }
    return res;
}