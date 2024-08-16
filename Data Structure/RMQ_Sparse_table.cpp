const int N = (1 << 14);
const int lg = 14;

class sparse_table {
public:
    int dp[N][lg];
    int pre_lg[N], n;
    sparse_table(int a) {
        memset(dp, 0, sizeof(dp));
        memset(pre_lg, 0, sizeof(pre_lg));
        n = 0;
    }

    void init(vector<int>&a) {
        int n = a.size();
        for (int i = 2; i < 2 * n; i++) {
            pre_lg[i] = pre_lg[i >> 1] + 1;
        }

        for (int i = 0; i < n; i++)dp[i][0] = a[i];

        for (int j = 1;  (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int k = pre_lg[r - l + 1];
        return min(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};