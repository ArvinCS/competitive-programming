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

const int maxNK = 1e4 + 5;

int tree[4*maxNK], lazy[4*maxNK];

void push(int v){
	tree[2*v] += lazy[v];
	lazy[2*v] += lazy[v];
	
	tree[2*v+1] += lazy[v];
	lazy[2*v+1] += lazy[v];
	
	lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
	if(l > r) return;
	if(l == tl && r == tr){
		tree[v] += val;
		lazy[v] += val;
	} else {
		push(v);
		
		int tm = (tl+tr) >> 1;
		update(v*2, tl, tm, l, min(r, tm), val);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r) return -inf_int;
	if(l <= tl && tr <= r){
		return tree[v];
	}
	
	push(v);
	int tm = (tl+tr) >> 1;
	return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	int c[n*k], cnt[n*k];
	for(int x=0;x<n*k;x++){
		cin >> c[x];
		c[x]--;
		
		cnt[x] = 0;		
	}
	
	pair<int, int> ans[n];
	fill(ans, ans+n+1, make_pair(-1, -1));
	
	int prv[n], mx = (n+(k-1)-1)/(k-1);
	fill(prv, prv+n, -1);
	
	for(int x=0;x<n*k;x++){
		if(ans[c[x]].first == -1){
			if(prv[c[x]] != -1){
				int cur = 0;
				for(int y=prv[c[x]];y<=x;y++){
					cur = max(cur, cnt[y]);
				}
				
				if(cur < mx){
					ans[c[x]].first = prv[c[x]];
					ans[c[x]].second = x;
					for(int y=prv[c[x]];y<=x;y++){
						cnt[y]++;
					}
				}
			}
			
			prv[c[x]] = x;
		}
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x].first+1 << " " << ans[x].second+1 << "\n";
	}
    return 0;
}

