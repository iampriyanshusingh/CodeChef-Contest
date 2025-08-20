#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x;
	cin>>x;
	while(x--){
	    int n;
	    cin>>n;
	    
	    string pattern = "aabbc";
	    string res = "";
	    
	    for(int i=0; i<n; i++){
	        res+=pattern[i%5];
	    }
	    cout<<res<<endl;
	}
	return 0;
}
