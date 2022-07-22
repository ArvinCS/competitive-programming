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

	int n, k;
	cin >> n >> k;
	
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	sort(c, c+n);
	
	priority_queue<ll> pq;
	for(int x=0;x<=k;x++) pq.push(0);
	
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		ll best = pq.top();
		pq.pop();
		
		ans += best;
		pq.push(best+c[x]);
	}
	
	cout << ans << "\n";
    return 0;
}

