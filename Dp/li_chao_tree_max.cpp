#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mymin -1000000000000000001

struct line {
    int m, c;
    line() {
        m = c = 0;
    }
    line(int _m, int _c) {
        m = _m;
        c = _c;
    }
    int value(int x) {
        return m * x + c;
    }
};

//max
class li_chao_tree {
public:
    vector<line>st;
    int mx, mn;
    li_chao_tree(int _mn, int _mx) {
        mx = _mx;
        mn = _mn;
        st.resize(4 * (mx - mn + 1), line(0, mymin));
    }

    void add_line(int ind, int low, int high, line curr) {
        int mid = low + (high - low) / 2;
        bool l = (st[ind].c == mymin || curr.value(low) >= st[ind].value(low));
        bool m = (st[ind].c == mymin || curr.value(mid) >= st[ind].value(mid));
        if (m)swap(curr, st[ind]);
        if (low == high)return;
        if (l ^ m) {
            add_line((ind << 1), low, mid, curr);
        }
        else {
            add_line((ind << 1) | 1, mid + 1, high, curr);
        }
    }

    int find(int ind, int low, int high, int x) {
        int mid = low + (high - low) / 2;
        if (low == high)return st[ind].value(x);
        if (x <= mid) {
            return max(st[ind].value(x), find((ind << 1), low, mid, x));
        }
        else {
            return max(st[ind].value(x), find((ind << 1) | 1, mid + 1, high, x));
        }
    }

};