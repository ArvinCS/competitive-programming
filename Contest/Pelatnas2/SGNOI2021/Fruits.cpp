#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 5;

struct Fenwick {
	ll tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	ll query(int pos){
		pos++;
		
		ll ans = 0;
		while(pos > 0){
			ans = max(ans, tree[pos]);
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, ll val){
		pos++;
		
		while(pos < maxN){
			tree[pos] = max(tree[pos], val);
			pos += pos&(-pos);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	bool ok[n];
	fill(ok, ok+n, true);
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		if(a[x] > 0) a[x]--;
		if(a[x] >= 0) ok[a[x]] = false;
	}
	
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	for(int x=0;x<n;x++){
		int p[n];
		for(int y=0;y<n;y++){
			p[y] = y;
		}
		
		ll ans = 0;
		do {
			ll cur = 0;
			int mx = -1;
			for(int y=0;y<=x;y++){
				if(a[y] != -1 && a[y] != p[y]){
					cur = 0;
					break;
				}
				
				if(mx < a[y]){
					cur += c[a[y]];
					mx = a[y];
				}
			}
			
			ans = max(ans, cur);
		} while(next_permutation(p, p+n));
		
		if(x > 0) cout << " ";
		cout << ans;
	}
	cout << "\n";
	return 0;
}
