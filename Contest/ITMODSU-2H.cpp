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

const int maxN = 1e5 + 5;

int parrent[maxN], sz[maxN];
vector<tuple<ll, int, int, int>> v;

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

bool check(int x, int y){
	return getParrent(x) == getParrent(y);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	ll s;
	cin >> n >> m >> s;
	
	for(int x=0;x<=n;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		v.push_back(make_tuple(c, a, b, x));
	}
	
	sort(v.rbegin(), v.rend());
	
	bool valid[m];
	fill(valid, valid+m, true);
	
	for(int x=0;x<m;x++){
		int a = get<1>(v[x]), b = get<2>(v[x]);
		if(!check(a, b)){
			merge(a, b);
			valid[x] = false;
		}
	}
	
	vector<int> ans;
	ll cost = 0;
	for(int x=m-1;x>=0;x--){
		int a = get<1>(v[x]), b = get<2>(v[x]);
		ll c = get<0>(v[x]);
		if(cost+c > s) break;
		if(valid[x]){
			cost += c;
			ans.push_back(get<3>(v[x])+1);
			valid[x] = false;
		}
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
