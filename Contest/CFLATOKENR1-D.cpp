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

const int maxN = 2050;

int n, d[maxN], table[maxN], prv[maxN];
vector<int> adj[maxN];

void ask(int node){
	cout << "? " << node << endl;
	
	for(int x=1;x<=n;x++){
		cin >> d[x];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	vector<pair<int, int>> ans;
	set<pair<int, int>> st;
	
	ask(1);
	for(int x=1;x<=n;x++){
		if(d[x] == 1){
			ans.push_back({1, x});
			st.insert({1, x});
			st.insert({x, 1});
		}
		adj[d[x]].push_back(x);
	}
	
	prv[0] = prv[1] = 0;
	table[0] = 0;
	table[1] = adj[1].size();
	
	for(int x=2;x<=n+1;x++){
		if(table[x-2] > table[x-1]){
			table[x] = table[x-1] + adj[x].size();
			prv[x] = x-1;
		} else {
			table[x] = table[x-2] + adj[x].size();
			prv[x] = x-2;
		}
	}
	
	int cur = n+1;
	while(cur > 0){
		for(auto node : adj[cur]){
			ask(node);
			
			for(int x=1;x<=n;x++){
				if(d[x] == 1 && !st.count({node, x})){
					ans.push_back({node, x});
					st.insert({node, x});
					st.insert({x, node});
				}
			}
		}
		
		cur = prv[cur];
	}
	
	cout << "!" << endl;
	for(auto p : ans){
		cout << p.first << " " << p.second << endl;
	}
    return 0;
}

