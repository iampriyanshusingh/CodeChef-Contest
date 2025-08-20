#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll,ll> memoH;
unordered_map<ll,ll> memoF;

ll h(ll m){
    if(m<=0) return 0;
    if(memoH.count(m)) return memoH[m];
    
    int x = 63 - __builtin_clzll(m);
    ll L = 1LL << x;
    
    return memoH[m] = h(L-1) + h(m-L)+L;
}

ll f(ll n){
    if(n<=1) return 0;
    if(memoF.count(n)) return memoF[n];
    
    int k = 63 - __builtin_clzll(n);
    ll L = 1LL << k;
    ll p = n-L;
    ll d = (p==0?1:0);
    
    return memoF[n] = f(L-1)+h(p) + L + d;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int X;
	cin>>X;
	while(X--){
	    ll N;
	    cin>>N;
	    cout<<f(N)<<endl;
	}
	
	return 0;

}
