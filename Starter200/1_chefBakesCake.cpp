#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,x,y;
    
    cin>>n>>x>>y;
    
    int z = y/x;
    
    cout<<(n+z-1)/z<<endl;
}
