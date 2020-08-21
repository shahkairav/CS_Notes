#include<bits/stdc++.h>

using namespace std;

#define DEBUG true
#define ll long long
#define tki(x) int x;cin>>x;
#define tkll(x) ll x;cin>>x;
#define tkstr(x) string x;cin>>x;
#define MOD (ll)(1000000007)
#define vll vector<ll>
#define vii vector<int>
#define vbb vector<bool>
#define vvii vector<vii>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpii vector<pii>
#define vpll vector<pll>
#define MP make_pair
#define XX first
#define YY second
#define PB push_back
#define EB emplace_back
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define RAND srand(time(NULL));
#define pcout(y,x) cout<<setprecision(y)<<x<<endl;
#define forll(i,j,k) for(ll i=j;i<k;i++)
#define rforll(i,j,k) for(ll i=j;i>=k;i--)
#define _find(x, y) ((x).find((y)) != (x).end())
#define si(x) ((int)(x).size())
#define mem(x, y) memset((x), (y), sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define debout(v) if(DEBUG) cout<<#v<<" is "<<v
#define TEST tkll(T);while(T--)
#define count1(x) __builtin_popcount(x)
#define endl "\n"

bool isPowerOfTwo (int x){return x && (!(x&(x-1)));} 

template<class T> inline T __lcm( T x, T y) { return (x*y)/__gcd(x,y);}
template<class T> inline T max3( T a, T b, T c) { return max(a,max(b,c));}
template<class T> inline T min3( T a, T b, T c) { return min(a,min(b,c));}

ll power(ll x, unsigned ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
template<class T> T modInv(T n, T p){return power(n, p-2, p);} 
template<class T> T fact(T n){ T res = 1,i =2;	while(i<=n){res = res * i;i++;} return res; }
template<class T> T nCr(T n, T r){ T i, j; vector<T> row(n+1,0); row[0] = 1; for(i = 1; i <= n; i++) for(j = i; j > 0; j--) row[j] += row[j - 1]; return row[r]; }
template<class T> T nCrModP(T n, T r, T p) { if (r==0) return 1; T fac[n+1]; fac[0] = 1; for (T i=1 ; i<=n; i++) fac[i] = fac[i-1]*i%p; return (fac[n]* modInverse(fac[r], p) % p * modInverse(fac[n-r], p) % p) % p; } 
template<class T> T nPr(T n,T r){return fact(n)/fact(n-r);}

template <class T1,class T2> ostream& operator << (ostream & out, const pair<T1,T2> &p){out << p.first<<' '<<p.second<<endl; return out;}
template <class T> ostream& operator << (ostream & out, const vector < T > & Vector){out << "[ ";for (auto a : Vector)out<<a<<" , "; out << ']';return out;}
template <class T> ostream& operator << (ostream & out, const set<T> & S){out<<'{'; for(auto a:S) out<<a<<" , "; out<<'}'<<endl; return out;}

template<class T> vector<T> tkvec(ll N){vector<T> v;T temp;forll(i,0,N){cin>>temp;v.PB(temp);} return v;}

void mergesortutil(vector<int> &arr, int i, int j){
    if(i>=j){return;}
    else{
        int mid = (i+j)/2;

        // Recurse for the left & right side
        mergesortutil(arr,i,mid);
        mergesortutil(arr,mid+1,j);

        // Merging the left and right array 
        // into a new array ans

        // NOTE:: Inplace merging is O(n**2)
        // So we take use of extra memory

        vector<int> ans(j-i+1,0);
        int l=i,r=mid+1,cc=0;

        while((l<=mid)&&(r<=j)){
            if(arr[l]<=arr[r]){ans[cc++]=arr[l++];}
            else{ans[cc++]=arr[r++];}
        }
        while(l<=mid){ans[cc++]=arr[l++];}
        while(r<=j){ans[cc++]=arr[r++];}

        // Storing values back
        for(int ii=i;ii<=j;ii++){arr[ii] = ans[ii-i];}
    }
}
void mergesort(vector<int> &arr){
    mergesortutil(arr,0,arr.size()-1);    
}
int main(){
    vector<int> arr = {1,3,5,2,4,6,8,-1,2,4,1,3};
    mergesort(arr);
    cout<<arr<<endl;
}