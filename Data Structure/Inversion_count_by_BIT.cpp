#include<bits/stdc++.h>
using namespace std;

class Fenwick {
public:
    int n;
    vector<int>bit;
    Fenwick(int a)
    {
        n = a;
        bit.resize(n + 1);
    }
    void update(int ind, int val)
    {
        for (; ind <= n; ind += (ind & (-ind)))
            bit[ind] += val;
    }

    int query(int ind)
    {
        int res = 0;
        for (; ind; ind -= (ind & (-ind)))
            res += bit[ind];
        return res;
    }

};

void convert(vector<int>&arr)
{
    int n = arr.size();
    vector<int>temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(temp.begin(), temp.end() , arr[i]) - temp.begin() + 1;
    }
}

int inversion_count(vector<int>&arr) {
    int n = arr.size();
    int inv_count = 0;
    convert(arr);
    Fenwick fen(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        inv_count += fen.query(arr[i] - 1);
        fen.update(arr[i], 1);
    }
    return inv_count;
}

signed main()
{
    int n; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << inversion_count(v);
}