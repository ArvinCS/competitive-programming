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

const int maxM = 1e6 + 5;

int tree[4*maxM], lazy[4*maxM];

void push(int v) {
    tree[2*v] += lazy[v];
    lazy[2*v] += lazy[v];
    
    tree[2*v+1] += lazy[v];
    lazy[2*v+1] += lazy[v];
    
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += val;
        lazy[v] += val;
    } else {
        push(v);
        
        int tm = (tl + tr) >> 1;
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r) return inf_int;
	if(l <= tl && tr <= r){
		return tree[v];
	}
	
	push(v);
	
	int tm = (tl + tr) >> 1;
	return min(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	tuple<int, int, int> s[n];
	for(int x=0;x<n;x++){
		int l, r, val;
		cin >> l >> r >> val;
		
		s[x] = make_tuple(val, l, r);
	}

	sort(s, s+n);
	
	fill(tree, tree+4*maxM, 0);
	fill(lazy, lazy+4*maxM, 0);
	
	int ans = inf_int, pos = 0;
	for(int x=0;x<n;x++){
		while(pos < n && query(1, 0, m, 1, m-1) == 0){
			update(1, 0, m, get<1>(s[pos]), get<2>(s[pos])-1, 1);
			pos++;
		}
		
		if(query(1, 0, m, 1, m-1) > 0){
			ans = min(ans, get<0>(s[pos-1]) - get<0>(s[x]));
		}
		update(1, 0, m, get<1>(s[x]), get<2>(s[x])-1, -1);
	}
	
	cout << ans << "\n";
    return 0;
}

