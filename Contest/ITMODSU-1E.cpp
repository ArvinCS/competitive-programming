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

const int maxN = 2e5 + 5, maxM = 4e5 + 5;

int parrent[maxN], sz[maxN], ans[maxN];
pair<int, int> data[maxN], q[maxM];
bool valid[maxN][2];
unordered_set<int> child[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
			swap(x, y);
		}
			
		parrent[b] = a;
		sz[a] += sz[b];
		
		if(child[b].size() > child[a].size()) swap(child[b], child[a]);
		for(auto s : child[b]){
			child[a].insert(s);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=1;x<=n;x++){
		parrent[x] = x;
		child[x].insert(x);
	}
	
	for(int x=1;x<=n;x++){
		cin >> data[x].first >> data[x].second;
		valid[x][0] = valid[x][1] = true;
	}
	
	for(int x=0;x<m;x++){
		cin >> q[x].first >> q[x].second;
		valid[q[x].first][q[x].second-1] = false;
	}
	
	fill(ans, ans+n+1, inf_int);
	for(int x=1;x<=n;x++){
		if(valid[x][0] && data[x].first > 0){
			merge(x, data[x].first);
		}
		if(valid[x][1] && data[x].second > 0){
			merge(x, data[x].second);
		}
	}
	
	for(auto s : child[getParrent(1)]) ans[s] = -1;
	
	for(int x=m-1;x>=0;x--){
		int mon = q[x].first, hand = q[x].second;
		
		if(hand == 1){
			if(ans[mon] == inf_int && getParrent(1) == getParrent(data[mon].first)){
				for(auto s : child[getParrent(mon)]){
					if(ans[s] == inf_int) ans[s] = x;
				}
			}
			if(ans[data[mon].first] == inf_int && getParrent(1) == getParrent(mon)){
				for(auto s : child[getParrent(data[mon].first)]){
					if(ans[s] == inf_int) ans[s] = x;
				}
			}
			
			merge(mon, data[mon].first);
		} else {
			if(ans[mon] == inf_int && getParrent(1) == getParrent(data[mon].second)){
				for(auto s : child[getParrent(mon)]){
					if(ans[s] == inf_int) ans[s] = x;
				}
			}
			if(ans[data[mon].second] == inf_int && getParrent(1) == getParrent(mon)){
				for(auto s : child[getParrent(data[mon].second)]){
					if(ans[s] == inf_int) ans[s] = x;
				}
			}
			
			merge(mon, data[mon].second);
		}
	}
	
	for(int x=1;x<=n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

