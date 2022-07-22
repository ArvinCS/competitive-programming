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
		int n;
		cin >> n;
		
		pair<int, int> a[n];
		for(int x=0;x<n;x++){
			cin >> a[x].first;
			a[x].second = x+1;
		}
		
		sort(a, a+n);
		
		int ans[n+1];
		ans[0] = 0;
		
		ll cnt = 0;
		int l = -1, r = 1;
		for(int x=n-1;x>=0;x--){
			if(abs(r) <= abs(l)){
				cnt += 2ll*abs(r)*a[x].first;
				ans[a[x].second] = r++;
			} else {
				cnt += 2ll*abs(l)*a[x].first;
				ans[a[x].second] = l--;
			}
		}
		
		cout << cnt << "\n";
		for(int x=0;x<=n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

