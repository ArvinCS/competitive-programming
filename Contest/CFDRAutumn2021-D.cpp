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

const int maxN = 1e3 + 5;

struct DSU {
	int parrent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parrent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];	
			return true;
		}
		return false;
	}	
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
	}
	
	for(int x=0;x<m;x++){
		dsu.reset();
		
		int cnt = x+1;
		for(int y=0;y<=x;y++){
			if(dsu.merge(p[y].first, p[y].second)){
				cnt--;
			}
		}
		
		priority_queue<int> pq;
		for(int x=0;x<n;x++){
			if(dsu.getParrent(x) == x){
				pq.push(dsu.sz[x]);
			}
		}
		
		int ans = pq.top()-1;
		pq.pop();
		
		while(cnt > 0){
			ans += pq.top();
			pq.pop();
			cnt--;
		}
		
		cout << ans << "\n";
	}
    return 0;
}

