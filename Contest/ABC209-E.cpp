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

const int maxN = 2e5 + 5;

map<string, vector<int>> adj;
string s[maxN];
int n, table[maxN]; // who lose: 2 second mover 1 first mover 0 draw/cycle
bool visited[maxN];

int solve(int idx){
	if(table[idx] != inf_int) return table[idx];
	
//	cout << idx << " " << visited.size() << "\n";
	
	int best = 2;
	bool cycle = false;
	string tmp;
	for(int x=3;x>=1;x--) tmp += s[idx][s[idx].length()-x];
	for(auto nxt : adj[tmp]){
		if(visited[nxt]){
			cycle = true;
			continue;
		}
		
		visited[nxt] = true;
		int state = solve(nxt);
		visited[nxt] = false;
		
		if(state == 2){
			best = 1;
		} else if(state == 0){
			cycle = true;
		}
	}
	
	if(best == 2){
		if(cycle){
			best = 0;
		}
	}
	
	return table[idx] = min(table[idx], best);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> s[x];
		
		string tmp;
		for(int y=0;y<3;y++){
			tmp += s[x][y];
		}
		adj[tmp].push_back(x);
	}
	
	fill(table, table+n, inf_int);
	for(int x=0;x<n;x++){
		if(table[x] == inf_int){
			visited[x] = true;
			solve(x);
			visited[x] = false;
		}
	}
	
//	for(int x=0;x<n;x++){
//		cout << table[x] << " ";
//	}
//	cout << "\n";
	
	for(int x=0;x<n;x++){
		if(table[x] == 2){
			cout << "Takahashi\n";
		} else if(table[x] == 1){
			cout << "Aoki\n";
		} else if(table[x] == 0){
			cout << "Draw\n";
		}
	}
    return 0;
}

