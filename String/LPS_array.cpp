// pi(i) denotes the maximum length of a substring that ends at position i,
// is a prefix of the string, and whose length is at most i-1.


vector<int> pi_function(string &s)
{
    int n = s.size();
    vector<int>lps(n);
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j && s[j] != s[i])
            j = lps[j - 1];
        if (s[j] == s[i])
            j++;
        lps[i] = j;
    }
    return lps;
}