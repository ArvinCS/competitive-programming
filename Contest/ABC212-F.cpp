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

const int maxN = 1e5 + 5;

bool visited[maxN];
vector<pair<int, int>> v[maxN];
vector<tuple<int, int, int, int>> adj[maxN];

void dfs(int curNode, int time){
	auto it = lower_bound(adj[curNode].begin(), adj[curNode].end(), make_tuple(time, 0, 0, 0));
	if(it == adj[curNode].end()){
		return;
	}
	
	tuple<int, int, int, int> t = *it;
	v[get<3>(t)].push_back({get<0>(t), -curNode});
	v[get<3>(t)].push_back({get<1>(t), get<2>(t)});
	
	if(!visited[get<3>(t)]){
		visited[get<3>(t)] = true;
		dfs(get<2>(t), get<1>(t));
	}
	
	for(auto p : v[get<2>(t)]){
		v[get<3>(t)].push_back(p);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int x=0;x<m;x++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		adj[a].push_back(make_tuple(c, d, b, x));
	}
	
	for(int x=0;x<=n;x++){
		sort(adj[x].begin(), adj[x].end());
	}
	
	for(int x=0;x<=n;x++){
		for(auto t : adj[x]){
			if(!visited[get<3>(t)]){
				visited[get<3>(t)] = true;
				
				v[get<3>(t)].push_back({0, x});
				v[get<3>(t)].push_back({get<0>(t), -x});
				v[get<3>(t)].push_back({get<1>(t), get<2>(t)});
				
				dfs(get<2>(t), get<1>(t));
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x, y, z;
		cin >> y >> x >> z;
		
		auto it = lower_bound(adj[x].begin(), adj[x].end(), make_tuple(y, y, 0, 0));
		if(it == adj[x].end()){
			cout << x << "\n";
			continue;
		}
		
		tuple<int, int, int, int> t = *it;
		int idx = get<3>(t);
		
		auto itnxt = lower_bound(v[idx].begin(), v[idx].end(), make_pair(z, -(n+1)));
		auto itprv = itnxt;
		
		pair<int, int> nxt = {-1, -1};
		pair<int, int> prv = {-1, -1};
		
		if(itprv != v[idx].begin()){
			itprv--;
			prv = *itprv;
		}
		if(itnxt != v[idx].end()){
			nxt = *itnxt;
		} else {
			nxt = {inf_int, -prv.second};
		}
		
		cout << nxt.first << " " << nxt.second << "\n";
		cout << prv.first << " " << prv.second << "\n";
		
		if(nxt.second > 0){
			cout << "? ?\n";
		} else {
			cout << abs(nxt.second) << "\n";
		}
	}
    return 0;
}

