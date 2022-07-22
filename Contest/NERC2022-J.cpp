#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 205;

ll c[maxN][maxN];
pair<ll, int> ans[maxN][maxN][maxN];
int p[maxN];
int n;

pair<ll, int> solve(int prvNode, int left, int right, ll sum, ll val){
	if(ans[prvNode][left][right].first != 1e18) return ans[prvNode][left][right];
	if(left > right) return ans[prvNode][left][right] = {0, -1};
	if(left == right){
		return ans[prvNode][left][right] = {sum, left};
	}
	
	pair<ll, int> mn = {1e18, 1e9};
	for(int x=left;x<=right;x++){
		ll pref = c[x][right]-(left > 0 ? c[x][left-1] : 0);
		ll exc = c[x][n-1] - c[x][right];
		if(left > 0){
			exc += c[x][left-1];
		}
		
		pair<ll, int> l = solve(x, left, x-1, sum+val+pref, val+pref-exc);
		pair<ll, int> r = solve(x, x+1, right, sum+val+pref, val+pref-exc);
		mn = min(mn, {l.first+r.first+sum, x});		
	}
	
	cout << prvNode << " " << left << " " << right << " -> " << mn.first << " " << mn.second << " " << sum << " " << val << "\n";
	return ans[prvNode][left][right] = mn;
}

void dfs(int left, int right, int prvNode){
	if(ans[prvNode][left][right].second == -1) return;
	if(left > right) return;
	
	p[ans[prvNode][left][right].second] = prvNode;
	dfs(left, ans[prvNode][left][right].second-1, ans[prvNode][left][right].second);
	dfs(ans[prvNode][left][right].second+1, right, ans[prvNode][left][right].second);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> c[x][y];
			if(y > 0) c[x][y] += c[x][y-1];
		}
	}
	
	fill(*ans[0], *ans[maxN], make_pair(1e18, 1e9));
	
	solve(0, 0, n-1, 0, 0);
	dfs(0, n-1, 0);
	
	p[ans[0][0][n-1].second] = -1;
	cout << ans[0][0][n-1].first << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << p[x]+1;
	}
	cout << "\n";
    return 0;
}

