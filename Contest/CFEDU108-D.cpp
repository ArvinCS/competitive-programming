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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	ll prefix[n];
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	for(int x=0;x<n;x++){
		prefix[x] = (a[x]*b[x]) + (x > 0 ? prefix[x-1] : 0);
	}
	
	ll sum = prefix[n-1];
	for(int x=0;x<n;x++){ // center point of reverse
		ll tmp = a[x]*b[x];
		for(int y=1;x-y >= 0 && x+y<n;y++){ // radius of reverse
			tmp += a[x-y] * b[x+y] + a[x+y] * b[x-y];
			ll cur = (x-y > 0 ? prefix[x-y-1] : 0) + tmp + (prefix[n-1]-prefix[x+y]);
			
			sum = max(cur, sum);
		}
		
		tmp = 0;
		for(int y=1;x+1-y >= 0 && x+y<n;y++){ // radius of reverse
			tmp += a[x+1-y] * b[x+y] + a[x+y] * b[x+1-y];
			ll cur = (x+1-y > 0 ? prefix[x+1-y-1] : 0) + tmp + (prefix[n-1]-prefix[x+y]);
			
			sum = max(cur, sum);
		}
	}
	
	cout << sum << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

