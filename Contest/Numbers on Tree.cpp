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

const int maxN = 2*1e3 + 5;

int ans[maxN], c[maxN];
vector<int> adj[maxN];
unordered_set<int> s;

void dfs(int curNode){
//	cout << curNode << "\n";
	int cnt = 0;
	for(int x=1;x<=maxN;x++){
		if(s.count(x)) continue;
		cnt++;
		
		if(cnt == 1+c[curNode]){
			ans[curNode] = x;
			s.insert(x);
			break;
		}
	}
	
	for(auto v : adj[curNode]) dfs(v);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int root = -1;
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp >> c[x];
		
		if(tmp == 0){
			root = x;
		} else {
			adj[tmp-1].push_back(x);
		}
	} 
	
	dfs(root);
	
	bool possible = true;
	for(int x=0;x<n;x++){
		queue<int> q;
		q.push(x);
		
		int tmp = 0;
		
		while(!q.empty()){
			int curNode = q.front();
			q.pop();

			for(auto v : adj[curNode]){
				q.push(v);
				tmp++;
			}
		}
		
		if(c[x] > tmp){
			possible = false;
			break;
		}
	}
	
	if(possible){
		cout << "YES\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

