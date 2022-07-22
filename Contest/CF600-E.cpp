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

void chmin(ll &a, ll b){
	if(a > b) a = b;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	ll m;
	cin >> n >> m;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+n);
	
	ll table[m+1];
	fill(table, table+m+1, inf_ll);
	
	table[0] = 0;
	for(int x=0;x<n;x++){
		ll mn = inf_ll;
		
		for(int y=m;y>=max(p[x].first-p[x].second, 0ll);y--) chmin(mn, table[y]);
		for(int y=0;p[x].second+y<=m;y++){
			chmin(mn, table[max(p[x].first-p[x].second-y-1, 0ll)]);
			chmin(table[min(p[x].first+p[x].second+y, m)], mn+y);
		}
	}
	
	cout << table[m] << "\n";
    return 0;
}

