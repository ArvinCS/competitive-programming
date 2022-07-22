#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m = n*(n+1)/2;
	int a[m];
	for(int x=0;x<m;x++){
		cin >> a[x];
		a[x]--;
	}
	
	int cnt[m][n];
	fill(cnt[0], cnt[m], 0);
	
	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++){
			if(x > 0) cnt[x][y] = cnt[x-1][y];
		}
		
		cnt[x][a[x]]++;
	}
	
	vector<int> v[n];
	for(int x=0;x<m;x++){
		v[a[x]].push_back(x);
	}
	
	bool valid[m];
	fill(valid, valid+m, false);
	
	ll table[m];
	fill(table, table+m, 0);
	
	for(int x=0;x<m;x++){
		bool exist[n];
		fill(exist, exist+n, false);
		
		if(x > 0){
			if(!valid[x-1]) continue;
			
			int cur = 0;
			for(int y=n-1;y>=0;y--){
				if(cnt[x-1][y] > cur){
					exist[y] = true;
					cur++;
				}
			}
		}
		
		int mx = 0;
		for(int y=0;y<n;y++){
			int idx = lower_bound(v[y].begin(), v[y].end(), x) - v[y].begin();
			if(idx >= v[y].size()) break;
			mx = max(mx, v[y][idx]);
			
			if(mx-x == y && !exist[y]){
				valid[x+y] = true;
				chadd(table[x+y], (x > 0 ? table[x-1] : 1));
			}
		}
	}
	
	cout << table[m-1] << "\n";
    return 0;
}

