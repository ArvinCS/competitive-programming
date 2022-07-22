#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 303;

bool valid[3][maxN][maxN][maxN];
vector<int> v[maxN];
ll table[maxN][maxN], new_table[maxN][maxN];

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int l[m], r[m], w[m];
	for(int x=0;x<m;x++){
		cin >> l[x] >> r[x] >> w[x];
		
		l[x]--; r[x]--;
		
		v[r[x]+1].push_back(x);
	}
	
	bool valid[3][n+1][n+1][n+1];
	for(int l1=0;l1<=n;l1++){
		for(int l2=l1;l2<=n;l2++){
			for(int l3=l2;l3<=n;l3++){
				valid[0][l1][l2][l3] = valid[1][l1][l2][l3] = valid[2][l1][l2][l3] = true;
				if(v[l3+1].empty()) continue;
				
				for(int x=0;x<v[l3+1].size();x++){
					int y = v[l3+1][x];
					
					int cnt = 1;
					if(l[y] <= l1-1){
						cnt++;
					}
					if(l[y] <= l2-1){
						cnt++;
					}
					
					if(cnt != w[y]){
						valid[0][l1][l2][l3] = false;
						continue;
					}
				}
				for(int x=0;x<v[l3+1].size();x++){
					int y = v[l3+1][x];
					
					int cnt = 1;
					if(l[y] <= l1-1){
						cnt++;
					}
					if(l[y] <= l3-1){
						cnt++;
					}
					
					if(cnt != w[y]){
						valid[1][l1][l2][l3] = false;
						continue;
					}
				}
				for(int x=0;x<v[l3+1].size();x++){
					int y = v[l3+1][x];
					
					int cnt = 1;
					if(l[y] <= l2-1){
						cnt++;
					}
					if(l[y] <= l3-1){
						cnt++;
					}
					
					if(cnt != w[y]){
						valid[2][l1][l2][l3] = false;
						continue;
					}
				}
			}
		}
	}
	
	fill(table[0], table[n+1], 0);
	
	table[0][0] = 1;
	
	for(int x=0;x<n;x++){
		fill(new_table[0], new_table[n+1], 0);
		
		for(int l1=0;l1<=x;l1++){
			for(int l2=l1;l2<=x;l2++){
				if(l1 == l2 && l1 != 0) continue;
				
				int l3 = (max(l1, l2) != x ? x : 0);
				
				if(valid[0][l1][l2][l3]){
					chadd(new_table[l1][l2], (x == 0 ? 3 : 1) * table[l1][l2] % mod);
				}
				
				if(valid[1][l1][l2][l3] && l3 != 0){
					chadd(new_table[l1][x], (1+(l2 == 0)) * table[l1][l2] % mod);
				}
				
				if(valid[2][l1][l2][l3] && l3 != 0 && l2 != 0){
					chadd(new_table[l2][x], table[l1][l2]);
				}
			}
		}
		
		for(int l1=0;l1<=n;l1++){
			for(int l2=l1;l2<=n;l2++){
				table[l1][l2] = new_table[l1][l2];
			}
		}
	}
	
	ll ans = 0;
	for(int l1=0;l1<=n;l1++){
		for(int l2=l1;l2<=n;l2++){
			int l3 = (max(l1, l2) != n ? n : -1);
			chadd(ans, table[l1][l2]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

