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

const int maxN = 3e5 + 5;

bool visited[maxN];
int pos[maxN], n, cycle = 0;

void dfs(int curNode, int a){
	visited[curNode] = true;
    if(visited[pos[(curNode-a+n)%n + 1]]){
    	cycle++;
	} else {
		dfs(pos[(curNode-a+n)%n + 1], a);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int m;
		cin >> n >> m;
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
			pos[p[x]] = x;
		}
		
		vector<int> v[n];
		
		for(int x=0;x<n;x++){
			v[(x+1-p[x]+n) % n].push_back(x);
		}
		
		vector<int> w;
		for(int x=0;x<n;x++){
			if(v[x].size()*3 >= n){
				w.push_back(x);
			}
		}
		
		vector<int> ans;
		for(int x=0;x<w.size();x++){
			fill(visited, visited+n, false);
			
			cycle = 0;
			for(int y=0;y<n;y++){
				if(!visited[y]){
					dfs(y, w[x]);
				}
			}
			
			if(n-cycle <= m){
				ans.push_back(w[x]);
			}
		}
		
		cout << ans.size();
		for(int x=0;x<ans.size();x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

