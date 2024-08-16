#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int>dp(m + 1, 0), prev(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[j] = 1 + prev[j - 1];
            else dp[j] = max(prev[j], dp[j - 1]);
        }
        prev = dp;
    }
    return dp[m];
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2);
}