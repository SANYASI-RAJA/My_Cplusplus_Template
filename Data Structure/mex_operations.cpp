#include<bits/stdc++.h>
using namespace std;

class mex {
public:
    set<int>st;
    map<int, int>freq;
    int n;
    mex(vector<int>&v) {
        n = v.size();
        for (int i = 0; i <= n; ++i)
        {
            st.insert(i);
        }
        for (int i = 0; i < n; ++i)
        {
            freq[v[i]]++;
            if (st.find(v[i]) != st.end()) {
                st.erase(v[i]);
            }
        }
    }

    int find() {
        return *(st.begin());
    }

    void insert(int val) {
        if (val >= 0 && val <= n) {
            if (freq[val] == 0) {
                st.erase(val);
            }
        }
        freq[val]++;
    }

    void remove(int val) {
        if (val >= 0 && val <= n) {
            if (freq[val] > 0) {
                freq[val]--;
                if (freq[val] == 0) {
                    st.insert(val);
                }
            }
        }
        else {
            if (freq[val] > 0)freq[val]--;
        }
    }

};

int main() {
    int n; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    mex chk(v);
    // After every update find mex of the array;

    int q; cin >> q;
    while (q--) {
        int ind, val; cin >> ind >> val;
        ind--;
        chk.remove(v[ind]);
        v[ind] = val;
        chk.insert(v[ind]);
        cout << chk.find() << " ";
    }
}