#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5005;

struct Fenwick {
	ll tree[maxN];
	int n;
	
	void reset(int n){
		this->n = n;
		fill(tree, tree+n+3, 0);	
	}
	
	void update(int pos, ll val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
	
	ll query(int pos){
		pos++;
		
		ll ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
};

Fenwick s, e;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		s.reset(n);
		e.reset(n);
		
		ll sz = 0;
		ll ans = 0;
		for(int x=n-1;x>=0;x--){
			for(int y=x+1;y<n;y++){
				if(p[x] > p[y]){
					s.update(x, 1);
					e.update(y, 1);
					sz++;
				}
				if(p[x] < p[y]){
					ll cnt = sz;
					cnt -= e.query(y);
					cnt -= sz - s.query(y-1);
					
					ans += cnt;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

