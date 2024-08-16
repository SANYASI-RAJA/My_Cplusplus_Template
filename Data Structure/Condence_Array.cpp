#include<bits/stdc++.h>
using namespace std;

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

signed main()
{
    int n; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    convert(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
}