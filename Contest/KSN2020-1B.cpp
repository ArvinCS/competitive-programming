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

const int maxN = 3 * 1e5;
const int maxL = log2(maxN);

pair<int, int> table[maxL][maxN];
ll n, k, cur = 0, cnt = 0;
vector<ll> v;
unordered_map<ll, ll> mp;

void update(){
	for(int x=1;x<=log2(n);x++){
		int length = 1 << x;
		for(int y=0;y+length<=n;y++){
			table[x][y] = min(table[x-1][y], table[x-1][y+(length/2)]);
		}
	}	
}

pair<int, int> query(int l, int r){
	int lg = log2(r-l+1);
	int length = 1 << lg;
	
	return min(table[lg][l], table[lg][r-length+1]);	
}

void solve(int l, int r, int tmp){
	if(l > r || cur >= k) return;
	int length = r-l+1;
	pair<int, int> p = query(l, r);
	int low = p.first-tmp;
	while(cur < k){
		if(v[cur] > cnt+low*1ll*length) break;
		int res = (v[cur]-cnt)%length;
		if(res == 0) res = length;
		
		mp[v[cur++]] = l+res-1;
	}
	cnt += low*1ll*length;
	
	solve(l, p.second-1, p.first);
	solve(p.second+1, r, p.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> table[0][x].first;
		table[0][x].second = x;
	}
	
	cin >> k;
	
	ll ans[k];
	for(int x=0;x<k;x++){
		cin >> ans[x];
		
		v.push_back(ans[x]);
	}
	
	sort(v.begin(), v.end());
	
	update();

	solve(0, n-1, 0);
	
	for(int x=0;x<k;x++){
		cout << mp[ans[x]]+1 << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

