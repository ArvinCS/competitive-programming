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
		int a[3], m;
		cin >> a[0] >> a[1] >> a[2] >> m;
		
		sort(a, a+3);
		
		int mn = max(a[2]-a[1]-a[0]-(a[1] > 0 ? 1 : 0), 0);
		int mx = max(a[0]-1, 0)+max(a[1]-1, 0)+max(a[2]-1, 0);
		
		if(m >= mn && m <= mx){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

