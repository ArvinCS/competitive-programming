#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	for(int x=1;x<=log2(n);x++){
		
	}
	
	ll ans = a[0], sum = a[0];
	for(int x=1;x<n;x++){
		for(int y=a[x-1];y>a[x];y--){
			
		}
	}
    return 0;
}

