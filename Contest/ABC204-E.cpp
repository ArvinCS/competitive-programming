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

ll dist[maxN];
vector<tuple<int, ll, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		ll c, d;
		cin >> a >> b >> c >> d;
		
		a--; b--;
		adj[a].push_back(make_tuple(b, c, d));
		adj[b].push_back(make_tuple(a, c, d));
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	queue<pair<ll, ll>> q;
	
	fill(dist, dist+n, inf_ll);
	dist[0] = 0;
	pq.push({0, 0});
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		ll time = p.first;
		int curNode = p.second;
		
		if(curNode == n-1){
			break;
		}
		
		for(auto t : adj[curNode]){
			int nxt = get<0>(t);
			ll c = get<1>(t), d = get<2>(t);
			if(dist[nxt] <= time+c) continue;
			
			ll best = time+c+d/(time+1);
			
//			cout << curNode << " to " << nxt << " init " << best << "(" << time << ")" << "\n";
			q.push({time+1, sqrt(d)});
			while(!q.empty()){
				pair<ll, ll> p = q.front();
				q.pop();
				
				if(p.first <= time || p.first > p.second) continue;
				
				ll mid = (p.first+p.second) >> 1;
				ll tmp = mid+c+d/(mid+1);
//				cout << mid << " " << p.first << " " << p.second << " -> " << tmp << " " << best << "\n";
				
				if(tmp < best){
					best = tmp;
				}
				
				ll tmp1 = (mid-1)+c+d/mid, tmp2 = (mid+1)+c+d/(mid+2);
				if(mid-1 >= time && tmp1 == tmp2 && mid+1 <= d){
					q.push({p.first, mid-1});
					q.push({mid+1, p.second});
				} else if(mid-1 >= time && tmp1 < tmp2){
					q.push({p.first, mid-1});
				} else if(mid+1 <= d){
					q.push({mid+1, p.second});
				}
			}
			
			if(dist[nxt] > best){
				dist[nxt] = best;
				pq.push({dist[nxt], nxt});
			}
		}
	}
	
	cout << (dist[n-1] == inf_ll ? -1 : dist[n-1]) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

