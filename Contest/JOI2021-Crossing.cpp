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

const int maxN = 2e5 + 5;
const ll base = 2309;

ll n;
ll prefix[maxN];
string t;

ll convert(char c){
	if(c == 'J') return 0;
	else if(c == 'O') return 1;
	else if(c == 'I') return 2;
	return 3;
}

struct SegTree { // index start from 0 (v)
	ll tree[4*maxN], lazy[4*maxN];
	
	void build(int v, int l, int r){
		if(l > r) return;
		if(l == r){
			tree[v] = (prefix[l] - (l > 0 ? prefix[l-1] : 0) + mod) % mod * convert(t[l]) % mod;
			lazy[v] = -1;
			return;
		}
		
		int m = (l+r) >> 1;
		build(v*2+1, l, m);
		build(v*2+2, m+1, r);
		
		tree[v] = (tree[v*2+1] + tree[v*2+2]) % mod;
		lazy[v] = -1;
	}
	
	void push(int v, int l, int m, int r){
		if(lazy[v] == -1) return;
		
		tree[v*2+1] = (prefix[m] - (l > 0 ? prefix[l-1] : 0) + 2*mod) % mod * lazy[v] % mod;
		lazy[v*2+1] = lazy[v];
		
		tree[v*2+2] = (prefix[r] - prefix[m] + 2*mod) % mod * lazy[v] % mod;
		lazy[v*2+2] = lazy[v];
		
		lazy[v] = -1;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r || curL > curR) return;
		if(curL == l && r == curR){
			tree[v] = (prefix[curR] - (curL > 0 ? prefix[curL-1] : 0) + 2*mod) % mod * val % mod;
			lazy[v] = val;
		} else {
			int curM = (curL+curR) >> 1;
			
			push(v, curL, curM, curR);
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = (tree[v*2+1] + tree[v*2+2]) % mod;
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;

		push(v, curL, curM, curR);
		
		return (query(v*2+1, curL, curM, l, min(r, curM)) + query(v*2+2, curM+1, curR, max(l, curM+1), r)) % mod;
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("JOI2021-Crossing.in","r",stdin);
	
	cin >> n;
	
	ll cur = 1;
	prefix[0] = 1;
	for(int x=1;x<maxN;x++){
		cur *= base;
		cur %= mod;
		prefix[x] = (prefix[x-1] + cur) % mod;
	}
	
	set<string> st;
	vector<string> v;
	
	for(int x=0;x<3;x++){
		string s;
		cin >> s;
		
		if(!st.count(s)){
			st.insert(s);
			v.push_back(s);
		}
	}
	
	for(int x=0;x<v.size();x++){
		for(int y=0;y<x;y++){
			string tmp;
			for(int z=0;z<v[x].length();z++){
				if(v[x][z] == v[y][z]){
					tmp.push_back(v[x][z]);
				} else {
					int bit = (1 << convert(v[x][z]));
					bit |= (1 << convert(v[y][z]));
					
					for(int i=0;i<3;i++){
						if(!(bit&(1<<i))){
							if(i == 0) tmp.push_back('J');
							else if(i == 1) tmp.push_back('O');
							else tmp.push_back('I');
							break;
						}
					}
				}
			}
			
			if(!st.count(tmp)){
				st.insert(tmp);
				v.push_back(tmp);
			}
		}
	}
	
	set<ll> st2;
	for(auto s : st){
		ll val = 0, cur = 1;
		for(int x=0;x<n;x++){
			val += convert(s[x]) * cur % mod;
			val %= mod;
			cur *= base;
			cur %= mod;
		}
		
//		cout << s << "\n";
		st2.insert(val);
	}
	
	int q;
	cin >> q;
	
	cin >> t;
	
	tree.build(0, 0, n-1);
	
	if(st2.count(tree.query(0, 0, n-1, 0, n-1))){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	for(int i=1;i<=q;i++){
		int l, r;
		char c;
		cin >> l >> r >> c;
		
		l--; r--;
		tree.update(0, 0, n-1, l, r, convert(c));
		
		if(st2.count(tree.query(0, 0, n-1, 0, n-1))){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}

