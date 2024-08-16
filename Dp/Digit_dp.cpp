// Problem Statement() :-
// Find the number of integers between 1 and K (inclusive) satisfying the following condition, modulo 1e9+7.
// The sum of the digits in base ten is a multiple of D.

// Constraints :-
// All values in input are integers.
// 1≤K<10^10000
// 1≤D≤100

// Explanation :-
// It is digit dp.
// dp[ind][last][val]=number of integer till index ind and is this is last value of
// index or not and what is sum of digit mod to k for find it's divisibility.



#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

int dp[10001][2][101];
string k;
int d;
int solve(int ind, bool last, int val) {
    if (ind == k.size())return (val == 0);
    int &res = dp[ind][last][val];
    if (res != -1)return res;
    int till = (last ? (k[ind] - '0') : 9);
    res = 0;
    for (int i = 0; i <= till; ++i)
    {
        res += solve(ind + 1, (last && (i == till)), (val + i) % d);
        res = res % M;
    }
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << (solve(0, 1, 0) - 1 + M) % M << endl;

}