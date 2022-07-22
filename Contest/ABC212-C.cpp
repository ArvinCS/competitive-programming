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
	
	int n, m;
	cin >> n >> m ;
	
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	sort(a, a+n);
	sort(b, b+m);
	
	int ans = inf_int;
	int pos = 0;
	for(int x=0;x<n;x++){
		while(pos+1 < m && abs(b[pos]-a[x]) >= abs(b[pos+1]-a[x])){
			pos++;
		}
		ans = min(ans, abs(b[pos]-a[x]));
	}
	
	cout << ans << "\n";
    return 0;
}

