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
	
	ll n, m;
	cin >> n >> m;
	
	ull sum = 0;
	pair<ll, int> l[m];
	for(int x=0;x<m;x++){
		cin >> l[x].first;
		sum += l[x].first;
		l[x].second = x;
	}
	
	if(sum < n){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=1;x<m;x++){
		if(n-l[x].first < x || x+l[x].first > n){
			cout << "-1\n";
			return 0;
		}
	}
		
	ll suffix[m], ans[m];
	fill(ans, ans+m, -1);
	suffix[m-1] = l[m-1].first;
	
	for(int x=m-2;x>=0;x--){
		suffix[x] = suffix[x+1] + l[x].first;
	}
	
	for(int x=0;x<m;x++){
		ans[x] = max(x*1ll, n-suffix[x]);
	}

	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";

    return 0;
}

// Santai
// Pikirin dengan benar-benar

