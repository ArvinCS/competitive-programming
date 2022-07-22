#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

const int maxM = 2e5 + 55;

ll tree[maxM][2];

void update(int pos, ll val, int id){
	pos++;
	val %= mod;
	
	while(pos < maxM){
		tree[pos][id] = (tree[pos][id] + val + mod) % mod;
		
		pos += pos&(-pos);
	}
}

ll query(int pos, int id){
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos][id];
		ans %= mod;
		
		pos -= pos&(-pos);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> m >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	fill(tree[0], tree[maxM], 0);
	update(0, 1, 0);
	update(1, -1, 0);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<=m;y++){
			if(y+p[x].first > m) break;
			
			ll cur = query(y, 0);
			
			update(y+p[x].first, cur, 1);
			update(min(y+p[x].second+1, m+1), -cur, 1);
		}
		
		for(int y=0;y<maxM;y++){
			tree[y][0] = tree[y][1];
			tree[y][1] = 0;
		}
	}
	
	cout << query(m, 0) << "\n";
    return 0;
}

