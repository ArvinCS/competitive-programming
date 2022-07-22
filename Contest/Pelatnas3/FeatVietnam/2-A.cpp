#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxQ = 2e5 + 5;

vector<int> vX, vY;

struct Line {
	ll xl, xr, yl, yr;
	
	Line(ll xl, ll xr, ll yl, ll yr) : xl(xl), xr(xr), yl(yl), yr(yr) {
		
	}
	
	ll calc(ll x, ll y){
		return min(abs(x-xl), abs(x-xr))+min(abs(y-yl), abs(y-yr));
	}
};

struct LiChao {
	vector<Line> tree;
	vector<int> idx;
	int valX;
	
	void build(vector<int> &w, int val){
		idx = w;
		valX = val;
		tree = vector<Line>(idx.size(), Line(-1e17, -1e17, -1e17, -1e17));
	}
	
	void update(int v, int curL, int curR, int l, int r, Line f){
		if(curL > curR || l > r) return;
		
		int curM = (curL+curR) >> 1;
		
		if(curL == l && curR == r){
			if(tree[v].calc(valX, vY[idx[l]]) < f.calc(valX, vY[idx[l]])){
				swap(tree[v], f);
			}
			
			if(curL == curR){
				return;
			}
			
			if(tree[v].calc(valX, vY[idx[l]]) > f.calc(valX, vY[idx[l]])){
				update(2*v+2, curM+1, curR, max(l, curM+1), r, f);
			} else {
				swap(tree[v], f);
				update(2*v+1, curL, curM, l, min(r, curM), f);
			}
			
			return;	
		}
		
		update(2*v+1, curL, curM, l, min(curM, r), f);
		update(2*v+2, curM+1, curR, max(curM+1, l), r, f);
	}
};

struct RangeTree {
	LiChao tree[4*maxQ];
	
	void build(int v, int l, int r, vector<int> y[]){
		if(l > r) return;
		if(l == r){
			tree[v].build(y[l], vX[l]);
			return;
		}
		
		int m = (l+r) >> 1;
		
		build(2*v+1, l, m, y);
		build(2*v+2, m+1, r, y);
		
		vector<int> w;
		for(int x=l;x<=r;x++){
			for(auto val : y[x]){
				w.push_back(val);
			}
		}
		
		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());
		
		tree[v].build(w);
		w.clear();
	}
	
	void update(int v, int curL, int curR, int l, int r, Line f){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			tree[v].update;
			return;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	assert(t == 3);
	
	int q;
	cin >> q;
	
	vector<pair<int, int>> v;
	
	ll ans = 0;
	while(q--){
		int type;
		cin >> type;
		
		if(type == 1){
			int x, y;
			cin >> x >> y;
			
			x *= 2; y *= 2;
			v.push_back({x, y});
		} else if(type == 2){
			int posX, posY;
			cin >> posX >> posY;
			
			posX *= 2; posY *= 2;
			
			string s0, s1;
			cin >> s0 >> s1;
			
			vector<int> vX, vY;
			for(int x=0;x<v.size();x++){
				vX.push_back(v[x].first);
				vY.push_back(v[x].second);
			}
			
			sort(vX.begin(), vX.end());
			vX.erase(unique(vX.begin(), vX.end()), vX.end());
			
			sort(vY.begin(), vY.end());
			vY.erase(unique(vY.begin(), vY.end()), vY.end());
			
			ll mx = -1e18;
			for(int x=0;x<v.size();x++){
				int idX = lower_bound(vX.begin(), vX.end(), v[x].first) - vX.begin();
				int idY = lower_bound(vY.begin(), vY.end(), v[x].second) - vY.begin();
				
				int xL = (idX > 0 ? (v[x].first + vX[idX-1])/2 : -1e9);
				int xR = (idX+1 < vX.size() ? (vX[idX+1] + v[x].first)/2 : 1e9);
				
				int yL = (idY > 0 ? (v[x].second + vY[idY-1])/2 : -1e9);
				int yR = (idY+1 < vY.size() ? (vY[idY+1] + v[x].second)/2 : 1e9);
				
				if(s0 == ">="){
					xL = max(xL, posX);
				} else {
					xR = min(xR, posX);
				}
				
				if(s1 == ">="){
					yL = max(yL, posY);
				} else {
					yR = min(yR, posY);
				}
				
				if(s0 == ">="){
					if(xR < posX) continue;
				} else {
					if(xL > posX) continue;
				}
				
				if(s1 == ">="){
					if(yR < posY) continue;
				} else {
					if(yL > posY) continue;
				}
				
//				cout << x << " -> " << xR << " " << xL << " " << yR << " " << yL << "\n";
//				cout << posX << " " << posY << "\n";
				mx = max(mx, min(abs(xR-posX), abs(xL-posX))*1ll+min(abs(yR-posY), abs(yL-posY)));
			}
			
//			cout << q << " -> " << mx << "\n";
			
			if(mx < 0){
				ans--;
				continue;
			}
			
			ans += mx;
		}
	}
	
	cout << ans << "\n";
	return 0;	
}
