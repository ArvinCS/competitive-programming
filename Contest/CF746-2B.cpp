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
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		ll a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			b[x] = a[x];
		}
		
		sort(b, b+n);
		
		bool sorted = true;
		for(int x=0;x<n;x++){
			if(a[x] != b[x]){
				sorted = false;
				break;
			}
		}
		
		if(sorted){
			cout << "YES\n";
			continue;
		}
		
		if(n <= m){
			cout << "NO\n";
			continue;
		}
		
		bool possible = true;
		int dist = n-m;
		for(int x=dist;x<n-dist;x++){
			if(a[x] != b[x]){
				possible = false;
				break;
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

