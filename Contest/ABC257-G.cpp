#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int key2 = 51;
const int key = 37;
const int maxN = 6e5 + 5;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 1e9);
	}
	
	void update(int v, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		if(curL == curR && curL == pos){
			tree[v] = val;
		} else {			
			int curM = (curL+curR) >> 1;
			
			if(pos <= curM) update(v*2+1, curL, curM, pos, val);
			else update(v*2+2, curM+1, curR, pos, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 1e9;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
} tree;

ll pw[maxN], pw2[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1; pw2[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (key * pw[x-1]) % mod;
		pw2[x] = (key2 * pw2[x-1]) % mod2;
	}
	
	string s;
	cin >> s;
	
	string t;
	cin >> t;
	
	ll hash[s.length()], hash2[t.length()], hash3[s.length()], hash4[t.length()];
	for(int x=0;x<s.length();x++){
		hash[x] = ((x > 0 ? hash[x-1] : 0) * key + (s[x] - 'a' + 1)) % mod;
		hash3[x] = ((x > 0 ? hash3[x-1] : 0) * key2 + (s[x] - 'a' + 1)) % mod2;
	}
	for(int x=0;x<t.length();x++){
		hash2[x] = ((x > 0 ? hash2[x-1] : 0) * key + (t[x] - 'a' + 1)) % mod;
		hash4[x] = ((x > 0 ? hash4[x-1] : 0) * key2 + (t[x] - 'a' + 1)) % mod2;
	}
	
	auto get = [&](ll hash[], int l, int r) -> ll {
		return (hash[r] - ((l > 0 ? hash[l-1] : 0) * pw[r-l+1] % mod) + 2*mod) % mod;
	};
	auto get2 = [&](ll hash[], int l, int r) -> ll {
		return (hash[r] - ((l > 0 ? hash[l-1] : 0) * pw2[r-l+1] % mod2) + 2*mod2) % mod2;
	};
	
	tree.reset();
	
	for(int x=t.length()-1;x>=0;x--){
		int bound = 0;
		int left = 1, right = min(s.length(), t.length()-x);
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(get(hash, 0, mid-1) == get(hash2, x, x+mid-1) && get2(hash3, 0, mid-1) == get2(hash4, x, x+mid-1)){
				bound = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		if(bound == t.length()-x){
			tree.update(0, 0, t.length()-1, x, 1);
			continue;
		}
		if(bound == 0){
			continue;
		}
		
		tree.update(0, 0, t.length()-1, x, tree.query(0, 0, t.length()-1, x+1, x+bound)+1);
	}
	
	int ans = tree.query(0, 0, t.length()-1, 0, 0);
	cout << (ans != 1e9 ? ans : -1) << "\n";
    return 0;
}

