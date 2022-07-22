#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct Line {
	ll m, c;
	
	Line(){
		
	}
	
	Line(ll m, ll c = 0) : m(m), c(c){
		
	}
	
	double intersect(Line other){
		return (c - other.c) * 1.0 / (other.m - m);
	}
	
	ll calc(ll x){
		return m*x + c;
	}
};

struct LiChao {
	Line tree[4*maxN];
	vector<ll> w;
	
	LiChao(){
		
	}
	
	void reset(vector<ll> v){
		this->w = v;
		Line l(0, 1e18);
		fill(tree, tree+4*maxN, l);
	}
	
	void update(int v, int curL, int curR, int l, int r, Line cur){
		if(curL > curR || l > r) return;
		
		int curM = (curL+curR)>>1;
		if(l == curL && r == curR){
			if(tree[v].calc(w[l]) > cur.calc(w[l])){
				swap(tree[v], cur);
			}
			
			if(curL == curR){
				return;
			}
			
			if(tree[v].calc(w[curM]) < cur.calc(w[curM])){
				update(2*v+2, curM+1, curR, max(l, curM+1), r, cur);
			} else {
				swap(tree[v], cur);
				update(2*v+1, curL, curM, l, min(r, curM), cur);
			}
			
			return;	
		}
		
		update(2*v+1, curL, curM, l, min(r, curM), cur);
		update(2*v+2, curM+1, curR, max(l, curM+1), r, cur);
	}
	
	ll query(int v, int l, int r, int x){
		Line line = tree[v];
		ll best = line.calc(w[x]);
		if(l == r) return best;
		
		int m = (l+r) >> 1;
		if(x <= m){
			return min(best, query(2*v+1, l, m, x));
		} else {
			return min(best, query(2*v+2, m+1, r, x));
		}
	}
};

LiChao lct;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, n;
	cin >> h >> n;
	
	int d[n];
	vector<ll> v;
	for(int x=0;x<n;x++){
		cin >> d[x];
		d[x]--;
		v.push_back(d[x]);
	}
		
	ll s;
	cin >> s;
	
	array<ll, 4> q[n];
	for(int x=0;x<n;x++){
		for(int y=0;y<4;y++){
			cin >> q[x][y];
		}
		q[x][0]--; q[x][1]--;
		v.push_back(q[x][0]);
		v.push_back(q[x][1]);
	}
	
	int m;
	cin >> m;
	
	m--;
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	lct.reset(v);
	
	int posL = lower_bound(v.begin(), v.end(), d[m]) - v.begin();
	int posR = posL;
	
	lct.update(0, 0, v.size()-1, posL, posR, Line(0, 0));
	
	while(posL >= 0 || posR < v.size()){
		ll curNode = -1;
		
		ll valL = 1e18, valR = 1e18;
		if(posL >= 0){
			valL = lct.query(0, 0, v.size()-1, posL);	
		}
		if(posR < v.size()){
			valR = lct.query(0, 0, v.size()-1, posR);
		}
		
		if(valL < valR){
			curNode = v[posL];
			posL--;
		} else {
			curNode = v[posR];
			posR++;
		}
		
		int id = lower_bound(d, d+n, curNode) - d;
		int id2 = lower_bound(v.begin(), v.end(), curNode) - v.begin();
		ll dist = lct.query(0, 0, v.size()-1, id2);
		
		if(id < n && d[id] == curNode){
			int l = lower_bound(v.begin(), v.end(), q[id][0]) - v.begin();
			int r = lower_bound(v.begin(), v.end(), q[id][1]) - v.begin();
			
			lct.update(0, 0, v.size()-1, l, min(id2, r), Line(-q[id][2], q[id][3] + q[id][2] * 1ll * curNode + dist));
			lct.update(0, 0, v.size()-1, max(id2+1, l), r, Line(q[id][2], q[id][3] - q[id][2] * 1ll * curNode + dist));
		}
		
		lct.update(0, 0, v.size()-1, 0, id2, Line(-s, s * 1ll * curNode + dist));
		lct.update(0, 0, v.size()-1, id2+1, v.size()-1, Line(s, -s * 1ll * curNode + dist));
	}
	
	for(int x=0;x<n;x++){
		int id2 = lower_bound(v.begin(), v.end(), d[x]) - v.begin();
		cout << lct.query(0, 0, v.size()-1, id2) << "\n";
	}
    return 0;
}

