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

void join(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		sz[a] += sz[b];
		parrent[b] = a;
	}
}

bool check(int x, int y){
	return getParrent(x) != getParrent(y);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
	
	int cnt = 0;
	ll ans = 0;
	for(auto t : edges){
		int a = get<1>(t), b = get<2>(t);
		ll c = get<0>(t);
		
		if(check(a,b)){
			ans += c;
			join(a,b);
			cnt++;
		}
	}
	
	if(cnt != n-1){
		cout << "-1\n";
		return 0;
	}
	
	cout << ans << "\n";
    return 0;
}

