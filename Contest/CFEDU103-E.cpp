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

vector<int> w[27][27][27][27];
int pos[27][27][27][27];
int pos2[maxN];
int cnt[maxN], mt[maxN], wild[maxN];
string p[maxN], s[maxN];
bool visited[maxN];
vector<int> adj[maxN];
vector<int> topo, ans;

void dfs(int curNode){
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt);
		}
	}
	topo.push_back(curNode);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<n;x++){
		cin >> p[x];
		cnt[x] = wild[x] = 0;
		visited[x] = false;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<k;y++){
			if(p[x][y] == '_') wild[x]++;
		}
	}
	
	vector<int> v;
	set<string> st;
	for(int x=0;x<m;x++){
		cin >> s[x] >> mt[x];
		mt[x]--;
		
		cnt[mt[x]]++;
	}
	
	fill(**pos[0], **pos[27], inf_int);
	
	for(int x=0;x<n;x++){
		if(cnt[x] > 0){
			if(st.count(p[x])){
				cout << "NO\n";
				return 0;
			}
			
			if(wild[x] == 0){
				pos2[x] = ans.size();
				ans.push_back(x);
				visited[x] = true;
			} else {
				v.push_back(x);
			}
			st.insert(p[x]);
		}
	}
	
	for(int x=0;x<v.size();x++){
		int idx[4];
		fill(idx, idx+4, 26);
		
		for(int y=0;y<k;y++){
			if(p[v[x]][y] != '_') idx[y] = (p[v[x]][y] - 'a');
		}
		
		w[idx[0]][idx[1]][idx[2]][idx[3]].push_back(v[x]);	
	}
	
	for(int x=0;x<m;x++){
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				if(b && k < 2) break;
				for(int c=0;c<2;c++){
					if(c && k < 3) break;
					for(int d=0;d<2;d++){
						if(d && k < 4) break;
						
						int idx[4];
						fill(idx, idx+4, 26);
						
						if(a) idx[0] = (s[x][0] - 'a');
						if(b) idx[1] = (s[x][1] - 'a');
						if(c) idx[2] = (s[x][2] - 'a');
						if(d) idx[3] = (s[x][3] - 'a');
						
						for(auto y : w[idx[0]][idx[1]][idx[2]][idx[3]]){
							if(y != mt[x]){
								adj[mt[x]].push_back(y);
							}
						}
					}
				}
			}
		}
	}
	
	for(int x=0;x<v.size();x++){ // priority selected pattern
		if(!visited[v[x]]){
			dfs(v[x]);
		}
	}
	
	reverse(topo.begin(), topo.end());
	
	for(int x=0;x<n;x++){ // now insert the non-selected pattern
		if(!visited[x]){
			dfs(x);
		}
	}
	
	for(int x=0;x<topo.size();x++){ // now add it to vector ans
		pos2[topo[x]] = ans.size();
		ans.push_back(topo[x]);
	}
	
	for(int x=0;x<ans.size();x++){ // validating make sure it possible
		int idx[4];
		fill(idx, idx+4, 26);
		
		for(int y=0;y<k;y++){
			if(p[ans[x]][y] != '_') idx[y] = (p[ans[x]][y] - 'a');
		}
		
		pos[idx[0]][idx[1]][idx[2]][idx[3]] = min(x, pos[idx[0]][idx[1]][idx[2]][idx[3]]);
	}
	
	for(int x=0;x<m;x++){  // validating make sure it possible
		int should = pos2[mt[x]], best = inf_int;
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				if(b && k < 2) break;
				for(int c=0;c<2;c++){
					if(c && k < 3) break;
					for(int d=0;d<2;d++){
						if(d && k < 4) break;
						
						int idx[4];
						fill(idx, idx+4, 26);
						
						if(a) idx[0] = (s[x][0] - 'a');
						if(b) idx[1] = (s[x][1] - 'a');
						if(c) idx[2] = (s[x][2] - 'a');
						if(d) idx[3] = (s[x][3] - 'a');
						
						best = min(best, pos[idx[0]][idx[1]][idx[2]][idx[3]]);
					}
				}
			}
		}
		
		bool match = true;
		for(int y=0;y<k;y++){
			if(p[mt[x]][y] == '_') continue;
			if(p[mt[x]][y] != s[x][y]){
				match = false;
				break;
			}
		}
		
		if(should != best || !match){
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

