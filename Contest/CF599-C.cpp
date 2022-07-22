#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxK = 20;
const int maxN = 5e3 + 5;
const int powK = (1 << maxK);

int k, n[maxK];
ll a[maxK][maxN];
bool valid[powK];
pair<int, int> ans[powK][maxK];
vector<int> adj[maxK*maxN];
int color[maxK*maxN], parrent[maxK*maxN];
ll row[maxK], sum = 0;

void dfs(int curNode){
	color[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(color[nxt] == 1){
			ll cnt = row[nxt/maxN];
			int cur = curNode, state = (1 << (nxt/maxN)), length = 1;
			while(cur != nxt){
				state |= (1 << (cur/maxN));
				cnt += row[cur/maxN];
				cur = parrent[cur];
				length++;
			}
			
			if(__builtin_popcount(state) != length || cnt % length != 0 || cnt/length != sum/k){
				continue;
			}
			
			cur = curNode;
			ans[state][cur/maxN] = {cur%maxN, nxt/maxN};
			while(cur != nxt){
				ans[state][parrent[cur]/maxN] = {parrent[cur]%maxN, cur/maxN};
				cur = parrent[cur];
			}
			valid[state] |= true;
		} else if(color[nxt] == 0){
			parrent[nxt] = curNode;
			dfs(nxt);
		}
	}
	
	color[curNode] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> k;
	
	map<ll, int> mp;
	for(int x=0;x<k;x++){
		cin >> n[x];
		
		row[x] = 0;
		for(int y=0;y<n[x];y++){
			cin >> a[x][y];
			mp[a[x][y]] = x*maxN+y;
			row[x] += a[x][y];
			sum += a[x][y];
		}
	}
	
	if(sum % k != 0){
		cout << "No\n";
		return 0;
	}
	
	fill(valid, valid+powK, 0);
	fill(color, color+maxK*maxN, 0);
	
	for(int x=0;x<k;x++){
		for(int y=0;y<n[x];y++){
			ll need = sum/k-(row[x]-a[x][y]);
			if(mp.find(need) != mp.end()){
				adj[mp[need]].push_back(x*maxN+y);
			}
		}
		
		if(row[x] == sum/k){
			valid[1 << x] = true;
			ans[1 << x][x] = {0, x};
		}
	}
	
	for(int x=0;x<k;x++){
		for(int y=0;y<n[x];y++){
			if(color[x*maxN+y] == 0){
				dfs(x*maxN+y);	
			}
		}
	}
	
	for(int x=1;x<(1 << k);x++){
		if(valid[x]) continue;
		
		for(int y=x;y>0;y=(y-1)&x){
			if(valid[y]&&valid[x^y]){
				valid[x] = true;
				for(int z=0;z<k;z++){
					if(y&(1 << z)){
						ans[x][z] = ans[y][z];
					} else if((x^y)&(1 << z)){
						ans[x][z] = ans[x^y][z];
					} else {
						ans[x][z] = {-1, -1};
					}
				}
			}
		}
	}
	
	if(valid[(1 << k)-1] == 1){
		cout << "Yes\n";
		for(int x=0;x<k;x++){
			cout << a[x][ans[(1 << k)-1][x].first] << " " << ans[(1 << k)-1][x].second+1 << "\n";
		}
	} else {
		cout << "No\n";
	}
    return 0;
}

