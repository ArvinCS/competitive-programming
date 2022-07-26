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
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	map<pair<int, int>, int> mp;
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(p[x].second == p[y].second){
				ans += mp[{p[x].first, p[y].first}];
				mp[{p[x].first, p[y].first}]++;
				mp[{p[y].first, p[x].first}]++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

