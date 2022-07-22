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
	cin >> n >> m;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	pair<ll, int> q[m];
	for(int x=0;x<m;x++){
		cin >> q[x].first;
		q[x].second = x;
	}
	
	sort(q, q+m);
	
	ll ans[m], cur = 0, cnt = 0, idx = 0;
	for(int x=0;x<m;x++){
		cur += q[x].first-cnt;
		cnt = q[x].first;
		
		while(idx < n && data[idx] <= cur){
			idx++;
			cur++;
		}
		
		if(idx == n){
			cur += q[x].first-cnt;
			cnt = q[x].first;
			ans[q[x].second] = cur;
			continue;
		}
		
		ans[q[x].second] = cur;
	}
	
	for(int x=0;x<m;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}



