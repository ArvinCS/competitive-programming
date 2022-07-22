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
	
	vector<pair<int, int>> w;
	vector<int> v[n+1];
	int c[n*k], nxt[n*k];
	for(int x=0;x<n*k;x++){
		cin >> c[x];		
		v[c[x]].push_back(x);
	}
	
	pair<int, int> ans[n+1];
	fill(ans, ans+n+1, make_pair(-1, -1));
	
	for(int x=1;x<=n;x++){
		nxt[v[x].back()] = inf_int;
		for(int y=0;y+1<k;y++){
			nxt[v[x][y]] = v[x][y+1];
			
			w.push_back({v[x][y], x});
			w.push_back({nxt[v[x][y]]+1, -x});
		}
	}
	
	sort(w.begin(), w.end());
	
	int cnt = 0, mx = (n+(k-1)-1)/(k-1);
	bool active[n+1], done[n+1];
	fill(active, active+n+1, false);
	fill(done, done+n+1, false);
	
	for(int x=0;x<w.size();x++){
		int pos = w[x].first, color = abs(w[x].second);
		bool add = (w[x].second > 0);
		
		if(add){
			if(!active[color] && !done[color]){
				bool valid = true;
				if(cnt >= mx){
					int mostRight = -1, mostC = -1;
					for(int y=0;y<=n;y++){
						if(active[y] && mostRight < nxt[ans[y].first]){
							mostRight = nxt[ans[y].first];
							mostC = y;
						}
					}
					
					if(mostC != -1){
						cnt--;
						ans[mostC].first = -1;
						
						active[mostC] = false;
					} else {
						valid = false;
					}
				}
				
				if(valid){
					cnt++;
					ans[color].first = pos;
					
					active[color] = true;
				}
			}
		} else {
			if(active[color] && nxt[ans[color].first] == pos-1 && !done[color]){
				cnt--;
				ans[color].second = pos-1;
				
				active[color] = false;
				done[color] = true;
			}
		}
	}
	
	for(int x=1;x<=n;x++){
		cout << ans[x].first+1 << " " << ans[x].second+1 << "\n";
	}
    return 0;
}
