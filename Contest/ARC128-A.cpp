#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans[n];
	fill(ans, ans+n, 0);
	
	bool inc = true;
	for(int x=0;x<n;x++){
		if(x+1 < n){
			if(inc && a[x] < a[x+1]){
				continue;
			}
			if(!inc && a[x] > a[x+1]){
				continue;
			}
		}
		
		if(x != n-1 || !inc) ans[x] = true;
		inc ^= 1;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

