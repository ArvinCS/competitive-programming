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

struct Pilar {
	ll x, y, r, cost;
};

const int maxN = 1e5 + 50;

vector<Pilar> p;
vector<int> sub[maxN];
vector<tuple<ll, ll, int>> v, w;
int parrent[2][maxN]; // 0 hor // 1 ver
ll dist[maxN];
bool visited[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	ll a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	Pilar tmp;
	for(int x=0;x<n;x++){
		cin >> tmp.x >> tmp.y >> tmp.r >> tmp.cost;
		
		p.push_back(tmp);
	}
	
	Pilar start, end;
	start.x = a; start.y = b; start.r = 0; start.cost = 0;
	end.x = c; end.y = d; end.r = 0; end.cost = 0; 
	
	p.push_back(end);
	p.push_back(start);
	
	for(int x=0;x<p.size();x++){
		v.push_back(make_tuple(p[x].x-p[x].r, p[x].x+p[x].r, x));
		w.push_back(make_tuple(p[x].y-p[x].r, p[x].y+p[x].r, x));
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	fill(parrent[0], parrent[2], -1);
	
	int dsu = -1, prvIdx = -1;
	ll prv = -inf_ll;
	for(int x=0;x<v.size();x++){
		ll low = get<0>(v[x]), high = get<1>(v[x]), idx = get<2>(v[x]);
		if(low <= prv){
			parrent[1][idx] = parrent[1][prvIdx];
		} else {
			dsu++;
			parrent[1][idx] = dsu;
		}
		
		sub[parrent[1][idx]].push_back(idx);
		if(high > prv){
			prv = high;
			prvIdx = idx;
		}
	}
	
	prv = -inf_ll, prvIdx = -1;
	for(int x=0;x<w.size();x++){
		ll low = get<0>(w[x]), high = get<1>(w[x]), idx = get<2>(w[x]);
		if(low <= prv){
			parrent[0][idx] = parrent[0][prvIdx];
		} else {
			dsu++;
			parrent[0][idx] = dsu;
		}
		
		sub[parrent[0][idx]].push_back(idx);
		if(high > prv){
			prv = high;
			prvIdx = idx;
		}
	}
	
	fill(dist, dist+n+5, inf_ll);
	fill(visited, visited+dsu+5, false);
	
	priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq;
	
	dist[p.size()-1] = 0;
	pq.push(make_tuple(dist[p.size()-1], p.size()-1, false));
	
	while(!pq.empty()){
		tuple<ll, int, bool> t = pq.top();
		pq.pop();
		
		ll cost = get<0>(t);
		int idx = get<1>(t);
		bool ver = get<2>(t);
		
//		cout << idx << ": " << cost << " " << ver << "\n";
		if(dist[idx] < cost) continue; // dist is also cost
		if(p[idx].x == c && p[idx].y == d){
			cout << cost << "\n";
			return 0;
		}
		
		if(visited[parrent[ver][idx]]){
			continue;
		}
		visited[parrent[ver][idx]] = true;
		
		for(auto nxt : sub[parrent[ver][idx]]){
			if(nxt == idx) continue;
			
			if(dist[nxt] > cost+p[nxt].cost){
				dist[nxt] = cost+p[nxt].cost;
				pq.push(make_tuple(dist[nxt], nxt, !ver));	
			}
		}
	}
	
	cout << "-1\n";
    return 0;
}

