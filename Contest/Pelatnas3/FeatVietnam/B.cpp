#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const ll mx = 1e15;
const int maxC = 3e5 + 5;
const int maxR = 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define tnode TNode*
struct TNode {
	int sz, key, lazy;
	ll val, sum;
	ll prior;
	TNode *par;
	TNode *l, *r;
	
	TNode() : sz(1), lazy(0), val(0), sum(0), prior(rng()), par(nullptr), l(nullptr), r(nullptr){
		
	}
};

void update(tnode &t){
	if(!t) return;
	
	t->sz = 1;
	t->sum = t->val;
	
	if(t->l != NULL){
		t->l->par = t;
		t->sz += t->l->sz;
		t->sum += t->l->sum;
	}
	if(t->r != NULL){
		t->r->par = t;
		t->sz += t->r->sz;
		t->sum += t->r->sum;
	}
}

int getSize(tnode &t){
	if(t == NULL) return 0;
	return t->sz;
}

void push(tnode &t){
	if(!t) return;
	
	if(t->l != NULL){
		t->l->key += t->lazy;
		t->l->lazy += t->lazy;
	}
	if(t->r != NULL){
		t->r->key += t->lazy;
		t->r->lazy += t->lazy;
	}
	t->lazy = 0;
}

void split(tnode t, tnode &l, tnode &r, int pos){
	if(t == NULL){
		l = r = NULL;
		return;
	}	
	
	push(t);
	
	if(t->key <= pos){
		split(t->r, t->r, r, pos);
		l = t;
	} else {
		split(t->l, l, t->l, pos);
		r = t;
	}
	
	update(t);
}

void merge(tnode &t, tnode l, tnode r){
	push(l); push(r);
	
	if(l == NULL || r == NULL){
		if(l) t = l;
		else t = r;
		return;
	}
	
	if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	
	update(t);
}

int getIdx(tnode t){
	if(!t) return 0;
	
	int sz = getSize(t->l);
	while(t->par != NULL){
		sz += (t->par->l != t ? 1 + getSize(t->par->l) : 0);
		t = t->par;
	}
		
	return sz;	
}

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void insert(tnode &t, tnode &x, int val){
	tnode l;
	tnode r;
	split(t, l, r, val);
	
	tnode tmp;
	merge(tmp, l, x);
	
	merge(t, tmp, r);
}

tnode row[maxR];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input_b.txt","r",stdin);
	// 1 <= R <= 10
	// 1 <= C <= 3 × 10^5
	// 1 <= N
	// Q <= 3×10^5
	// 1 <= B <= 10^8
		
	ll r, c, n, q, b;
	while(cin >> r >> c >> n >> q >> b){		
		ll cnt = r*c;
		
		pair<int, int> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		pair<int, string> p2[q];
		for(int x=0;x<q;x++){
			cin >> p2[x].first >> p2[x].second;
			p2[x].first--;
		}
		
		for(int x=0;x<r;x++){
			row[x] = nullptr;
		}
		
		tnode pos[n];
		for(int x=0;x<n;x++){
			int pos_r = p[x].first, pos_c = p[x].second;
			
			pos[x] = new TNode();
			pos[x]->val = pos[x]->sum = x+1;
			pos[x]->key = pos_c;
			
			insert(row[pos_r], pos[x], pos_c);
		}
		
		for(int i=0;i<q;i++){
			int idx = p2[i].first;
			string dir = p2[i].second;
			
			if(dir == "up"){
				int p2 = -1;
				for(int x=0;x<r;x++){
					if(!row[x]) continue;
					
					tnode nw = row[x];
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, pos[idx]->key-1);
					split(r, r, r2, pos[idx]->key);
					if(r && r == pos[idx]){
						p2 = x;
					}
					
					merge(r, r, r2);
					merge(nw, l, r);
					
					row[x] = nw;
				}
				
				int p3 = p2;
				
				for(int x=p2;x>=0;x--){
					tnode nw = row[x];
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, pos[idx]->key-1);
					split(r, r, r2, pos[idx]->key);
					
					if(r){
						p3 = x;
					}
					
					merge(r, r, r2);
					merge(nw, l, r);
					
					row[x] = nw;
					
					if(p3 != x){
						break;
					}
				}
				
				if(p3 > 0){
					for(int x=p3;x<=p2;x++){
						tnode nw = row[x];
						tnode l;
						tnode r;
						tnode r2;
						
						split(nw, l, r, pos[idx]->key-1);
						split(r, r, r2, pos[idx]->key);
						
						insert(row[x-1], r, r->key);
						merge(nw, l, r2);
						
						row[x] = nw;
					}
				}
			} else if(dir == "down"){
				int p2 = -1;
				for(int x=0;x<r;x++){
					tnode nw = row[x];
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, pos[idx]->key-1);
					split(r, r, r2, pos[idx]->key);
					
					if(r && r == pos[idx]){
						p2 = x;
					}
					
					merge(r, r, r2);
					merge(nw, l, r);
					
					row[x] = nw;
				}
				
				int p3 = p2;
				
				for(int x=p2;x<r;x++){
					tnode nw = row[x];
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, pos[idx]->key-1);
					split(r, r, r2, pos[idx]->key);
					
					if(r){
						p3 = x;
					}
					
					merge(r, r, r2);
					merge(nw, l, r);
					
					row[x] = nw;
					
					if(p3 != x){
						break;
					}
				}
				
				if(p3 < r-1){
					for(int x=p3;x>=p2;x--){
						tnode nw = row[x];
						tnode l;
						tnode r;
						tnode r2;
						
						split(nw, l, r, pos[idx]->key-1);
						split(r, r, r2, pos[idx]->key);
						
						insert(row[x+1], r, pos[idx]->key);
						merge(nw, l, r2);
						
						row[x] = nw;
					}
				}
			} else if(dir == "left"){
				int bound = pos[idx]->key;
				int left = 0, right = pos[idx]->key;
				
				tnode nw = pos[idx];
				while(nw->par) nw = nw->par;
				
				while(left <= right){
					int mid = (left+right) >> 1;
					
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, mid-1);
					split(r, r, r2, pos[idx]->key);
					
					if(getSize(r) == pos[idx]->key-mid+1){
						bound = mid;
						right = mid-1;
					} else {
						left = mid+1;
					}
					
					merge(r, r, r2);
					merge(nw, l, r);
				}
				
				if(bound > 0){
					tnode l;
					tnode r;
					tnode r2;
					
					split(nw, l, r, bound-2);
					split(r, r, r2, pos[idx]->key);
					
					r->key--;
					r->lazy--;
					
					merge(r, r, r2);
					merge(nw, l, r);
				}
			} else if(dir == "right"){
				int bound = pos[idx]->key;
				int left = bound, right = c-1;
				
				tnode nw = pos[idx];
				while(nw->par) nw = nw->par;
					
				while(left <= right){
					int mid = (left+right) >> 1;
					
					tnode tmp;
					tnode l;
					tnode r;
					split(nw, l, tmp, pos[idx]->key-1);
					split(tmp, tmp, r, mid);
					
					if(getSize(tmp) == mid-pos[idx]->key+1){
						bound = mid;
						left = mid+1;
					} else {
						right = mid-1;
					}
					
					merge(tmp, tmp, r);
					merge(nw, l, tmp);
				}
				
				if(bound < c-1){
					int cp = 0;
					for(int x=0;x<r;x++){
						if(nw == row[x]){
							cp = x;
							break;		
						}
					}
					
					tnode l;
					tnode r;
					tnode r2;
										
					split(nw, l, r, pos[idx]->key-1);
					split(r, r, r2, bound);
					
					r->key++;
					r->lazy++;
					
					merge(r, r, r2);
					merge(nw, l, r);
					row[cp] = nw;
				}
			}
		}
		
		ll ans = 0;
		for(int x=0;x<r;x++){
			if(!row[x]) continue;
			
			tnode cur = row[x];
			while(cur){
				tnode l;
				tnode r;
				
				int idx = x*c + cur->key;
				int idx2 = cnt-1-idx;
				
				ans += cur->val * 1ll * powmod(b, idx2) % mod;
				ans %= mod;
				
				int key = cur->key;
				tnode tmp;
				tnode tmp2;
				split(cur, l, r, key);
				split(l, tmp, tmp2, key-1);
				
				merge(cur, tmp, r);
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
