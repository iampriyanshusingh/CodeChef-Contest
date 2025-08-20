#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;
const int MAX = 200000;

vector<ll> fact(MAX+1), inv(MAX+1);

ll power(ll b, ll e, ll m){
    ll r = 1;
    while(e>0){
        if(e&1) r = r*b%m;
        b = b*b%m;
        e>>=1;
    }
    return r;
}

void compute(){
    fact[0] = 1;
    for(int i=1; i<=MAX; i++){
        fact[i] = fact[i-1]*i%MOD;
    }
    
    inv[MAX]=power(fact[MAX],MOD-2,MOD);
    for(int i=MAX; i>0;i--){
        inv[i-1] = inv[i]*i%MOD;
    }
}

ll X(int x,int y){
    if(y<0 || y>x) return 0;
    return fact[x]*inv[y]%MOD*inv[x-y]%MOD;
}

ll solve(int T){
    int a = T/3;
    int b= (T+2)/3;
    int c = (T+1) /3;
    if(b+c==0) return 0;
    
    ll total =0;
    for(int i=a-1; i<=a+1; i++){
        if(i<1) continue;
        int r = a-(i-1);
        if(r<0 || r>2) continue;
        
        ll e = X(2,r);
        
        int low = max(0,i-c);
        int high = min(i,b);
        ll w = 0;
        
        for(int x = low; x<= high; x++){
            int j = i-x;
            ll compB = (x==0 && b==0)?1:(x>0?X(b-1,x-1):0);
            ll compC = (j==0 && c==0)?1:(j>0?X(c-1,j-1):0);
            
            w = (w+X(i,x)*compB%MOD*compC)%MOD;
        }
        total = (total+w*e)%MOD;
    }
    return total*fact[a]%MOD*fact[b]%MOD*fact[c]%MOD;
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    compute();
    
    int X;
    cin>>X;
    while(X--){
        int N,k;
        cin>>N>>k;
        cout<<solve(N)<<endl;
    }
    return 0;
}
