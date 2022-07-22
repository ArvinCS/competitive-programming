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
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	ll prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = a[x] + (x > 0 ? prefix[x-1] : 0);
	}
	
	map<ll, int> mp;
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		if(mp[a[x]] == 0) v.push_back({a[x], x});	
		mp[a[x]]++;
	}
	
	ll ans = inf_ll;
	for(int x=0;x<n;x++){
		auto it = lower_bound(v.begin(), v.end(), make_pair(a[x]-1, -1));
		auto it2 = lower_bound(v.begin(), v.end(), make_pair(a[x]+2, -1));
		
		int cntLeft = (it != v.end() ? (*it).second : 0);
		int cntRight = (it2 != v.end() ? n-(*it2).second : 0);
		
		if(mp.find(a[x]-1) == mp.end()) mp[a[x]-1] = 0;
		if(mp.find(a[x]+1) == mp.end()) mp[a[x]+1] = 0;
		
		int need = k-mp[a[x]];
		if(need <= 0){
			ans = min(ans, 0ll);
			continue;
		}
		if(cntLeft+mp[a[x]-1] >= need){
			ll cnt = need;
			if(cntLeft > 0){
				int idxLeft = (*it).second-1;
				cnt += cntLeft*(a[x]-1) - prefix[idxLeft];
			}
			
			ans = min(ans, cnt);
		}
		if(cntRight+mp[a[x]+1] >= need){			
			ll cnt = need;
			if(cntRight > 0){
				int idxRight = (*it2).second;
				cnt += prefix[n-1] - (idxRight > 0 ? prefix[idxRight-1] : 0) - cntRight*(a[x]+1);
			}
			
			ans = min(ans, cnt);
		}
		if(cntLeft+cntRight+mp[a[x]-1]+mp[a[x]+1] >= need){
			ll cnt = need;
			if(cntLeft > 0){
				int idxLeft = (*it).second-1;
				cnt += cntLeft*(a[x]-1) - prefix[idxLeft];
			}
			if(cntRight > 0){
				int idxRight = (*it2).second;
				cnt += prefix[n-1] - (idxRight > 0 ? prefix[idxRight-1] : 0) - cntRight*(a[x]+1);
			}
			
			ans = min(ans, cnt);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

