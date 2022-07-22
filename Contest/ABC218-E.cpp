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

int parrent[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x), b = getParrent(y);
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
	
	for(int x=0;x<n;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	vector<tuple<ll, int, int>> edges;
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;	
		
		a--; b--;
		edges.push_back(make_tuple(c, a, b));
	}
	
	sort(edges.begin(), edges.end());
	
	ll ans = 0;
	for(int x=0;x<edges.size();x++){
		int a = get<1>(edges[x]), b = get<2>(edges[x]);
		ll c = get<0>(edges[x]);
		
		if(getParrent(a) != getParrent(b)){
			merge(a, b);
		} else {
			if(c >= 0){
				ans += c;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

