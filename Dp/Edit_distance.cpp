#include <bits/stdc++.h>
using namespace std;
int Edit_Distance(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});

        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    cout << Edit_Distance(s1, s2);
}