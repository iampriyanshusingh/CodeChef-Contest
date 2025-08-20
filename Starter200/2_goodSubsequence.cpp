#include <bits/stdc++.h>
using namespace std;

int findLongestSubsequence(vector<int> &arr){
    int even = 0, odd = 0;
    
    for(int x: arr){
        if(x%2==0){
            even = max(even,odd+1);
            even = max(even,1);
        }else{
            odd=max(odd,even+1);
            odd=max(odd,1);
        }
    }
    
    return max(even,odd);
}

void solve(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<findLongestSubsequence(arr)<<endl;
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
