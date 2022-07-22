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

const int maxN = 2e5 + 5;

ll parrent[maxN], sz[maxN], ans[maxN];
vector<pair<int, int>> edges[maxN];

void newSet(int x){
	parrent[x] = x;
	sz[x] = 1;
}

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]) swap(a, b);
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=1;x<=n;x++){
		newSet(x);
	}
	
	for(int x=0;x<n-1;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		edges[c].push_back({a, b});
	}
	
	fill(ans, ans+maxN, 0);
	
	ll cnt = 0;
	for(int x=1;x<maxN;x++){
		for(auto e : edges[x]){
			int par1 = getParrent(e.first), par2 = getParrent(e.second);
			
			cnt -= sz[par1]*(sz[par1]-1)/2;
			cnt -= sz[par2]*(sz[par2]-1)/2;
			
			merge(e.first, e.second);
			
			cnt += sz[getParrent(e.first)]*(sz[getParrent(e.first)]-1)/2;
		}
		
		ans[x] = cnt;
	}
	
	for(int x=1;x<=m;x++){
		int mx;
		cin >> mx;
		
		if(x > 1) cout << " ";
		cout << ans[mx];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

