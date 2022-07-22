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
	
	set<ll> st;
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		st.insert(data[x]);
	}
	
	ll dist = 1, sum = 0;
	ll ans[m];
	
	ll cnt = 0;
	queue<pair<ll, ll>> q;
	for(int x=0;x<n;x++){
		if(!st.count(data[x]-1)) q.push(make_pair(data[x]-1, -1));
		if(!st.count(data[x]+1)) q.push(make_pair(data[x]+1, 1));
	}
	
	while(!q.empty() && cnt < m){
		pair<ll, ll> p = q.front();
		q.pop();
		
		if(st.count(p.first)) continue;
		st.insert(p.first);
		
		sum += abs(p.second);
		ans[cnt++] = p.first;
		
		ll move = (p.second > 0 ? 1 : -1);
		if(st.count(p.first+move)) continue;
		q.push(make_pair(p.first+move, p.second+move));
	}
	
	cout << sum << "\n";
	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

