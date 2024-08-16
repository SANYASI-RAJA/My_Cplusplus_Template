// 1 Based indexing

#include<bits/stdc++.h>
using namespace std; 

struct Fenwick{
   int n;
   vector<int>bit;

   Fenwick(int a){
     n=a;
     bit.resize(n+1);
   }

   void update(int ind,int val){
    for(;ind<=n;ind+=(ind&(-ind)))
        bit[ind]+=val;
   }

   int query(int ind){
    int res=0;
    for(;ind;ind-=(ind&(-ind)))
        res+=bit[ind];
    return res;
   }

};
 

int main(){   
    int n;cin>>n;
    vector<int>v(n);
    Fenwick fen(n);
    vector<int>psm(n);
    cout<<5<<endl;
    for (int i = 0; i < n; ++i){
        cin>>v[i];
        fen.update(i+1,v[i]);
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<fen.query(r)-fen.query(l-1)<<endl;
    }
}