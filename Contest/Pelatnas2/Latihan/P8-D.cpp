#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1005;
const int maxM = 25;
const ll mod = 10007;

ll table[maxN][maxM], cnt[(1 << maxM)], new_cnt[(1 << maxM)];
vector<int> adjA[maxN], adjB[maxM];
int n, m, rootA = -1, rootB = -1;
vector<int> v[maxM];

ll dfs(int curNode, int prvNode){
	ll ans = 0;
	for(auto nxt : adjA[curNode]){
		if(nxt != prvNode){
			ans += dfs(nxt, curNode);
			ans %= mod;
		}
	}
	
	for(int x=0;x<m;x++){
		if(v[x].size() == 0){
			table[curNode][x] = 1;
		} else {
			int fullstate = (1 << v[x].size());
			fill(cnt, cnt+fullstate, 0);
			
			cnt[0] = 1;
			for(auto nxt : adjA[curNode]){
				if(nxt != prvNode){
					fill(new_cnt, new_cnt+fullstate, 0);
					
					for(int y=0;y<v[x].size();y++){
						int bit = (1 << y);
						for(int state=0;state<fullstate;state++){
							if(!(state&bit)){
								new_cnt[state|bit] += cnt[state]*table[nxt][v[x][y]] % mod;
								new_cnt[state|bit] %= mod;
							}
						}
					}
					
					for(int state=0;state<fullstate;state++){
						cnt[state] += new_cnt[state];
						cnt[state] %= mod;
					}
				}
			}
			
			table[curNode][x] = cnt[fullstate-1];
		}
	}
	
	ans += table[curNode][rootB] % mod;
	ans %= mod;
	return ans;
}

void dfs2(int curNode, int prvNode){
	for(auto nxt : adjB[curNode]){
		if(nxt != prvNode){
			dfs2(nxt, curNode);
			v[curNode].push_back(nxt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	int parentA[n];
	fill(parentA, parentA+n, -1);
	
	for(int x=0;x<n-1;x++){
		int p, q;
		cin >> p >> q;
		
		p--; q--;
		adjA[p].push_back(q);
		parentA[q] = p;
	}
	
	cin >> m;
	
	int parentB[m];
	fill(parentB, parentB+m, -1);
	
	for(int x=0;x<m-1;x++){
		int r, s;
		cin >> r >> s;
		
		r--; s--;
		adjB[r].push_back(s);
		parentB[s] = r;
	}
	
	for(int x=0;x<m;x++){
		if(parentB[x] == -1){
			rootB = x;
			break;
		}
	}
	
	dfs2(rootB, rootB);
	
	for(int x=0;x<n;x++){
		if(parentA[x] == -1){
			rootA = x;
			break;
		}
	}
	
	cout << dfs(rootA, rootA) % mod << "\n";
    return 0;
}

