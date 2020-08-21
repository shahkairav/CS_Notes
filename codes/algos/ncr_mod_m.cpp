#include<bits/stdc++.h>

using namespace std;


long long ncrmodm(long long n, long long r, long long m, map<pair<long long,long long>,long long> &store){
    if(n == r){return 1%m;}
    else if(r==1){return n%m;}
    else{
        pair<long long,long long> p = make_pair(n,r);
        if(store.find(p)==store.end()){
            store[p] = (ncrmodm(n-1,r-1,m,store) + ncrmodm(n-1,r,m,store))%m;
        }
        return store[p];
    }
}
int main(){
    map<pair<long long,long long>, long long> store;
    cout<<ncrmodm(10,5,10000003,store)<<endl;
}