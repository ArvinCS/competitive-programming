#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 405;

pair<ll, ll> table[maxN][maxN];
vector<int> v[maxN];

pair<ll, ll> solve(int left, int right){
	if(left == right) return {0, 0};
	if(left > right) return {1, 0};
	if(table[left][right].first != -1) return table[left][right];
	
	ll ans = 0, cnt = 0;
	for(int y=0;y<v[left].size();y++){
		if(v[left][y] > right) break;
		
		pair<ll, ll> p1 = solve(left+1, v[left][y]-1), p2 = solve(v[left][y]+1, right);
		ans += p1.first * p2.first % mod * (p1.second+1+p2.second) % mod;
		cnt += (p1.second+1+p2.second);
		cnt %= mod;
		ans %= mod;
	}
	return table[left][right] = {ans, cnt};
}

bool customSort(pair<int, int> a, pair<int, int> b){
	return a.second-a.first < b.second-b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	fill(table[0], table[maxN], make_pair(-1, -1));
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
		
		if((p[x].second-p[x].first) % 2 == 0) continue;
		
		v[p[x].first].push_back(p[x].second);
	}
	
	cout << solve(0, 2*n-1).first << "\n";
    return 0;
}

