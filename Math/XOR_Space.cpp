#include<bits/stdc++.h>
using namespace std;
const int d = 31;
int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
    for (int i = d - 1; i >= 0; i--) {
        if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            basis[i] = mask;
            ++sz;

            return;
        }

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        insertVector(a);
    }
    int distinct_xor = (1 << sz);
    int max_xor = 0;
    for (int i = d - 1; i >= 0; i--) {
        if (!basis[i]) continue;

        if (max_xor & 1 << i) continue;

        max_xor ^= basis[i];
    }
    cout << distinct_xor << endl; //number of distinct integers that can be represented using xor over the set of the given elements.
    cout << max_xor << endl;  //maximum possible xor of the elements of some subset.
}