#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;
const int maxM = 2e7 + 5;
const int logN = 25;

ll table[logN];
bool visited[maxM];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	fill(table, table+logN, 0);
	fill(visited, visited+maxM, false);
	
	ll cnt = 0;
	for(int x=1;x<=20;x++){
		for(int y=1;y<=m;y++){
			if(!visited[x*y]){
				visited[x*y] = true;
				cnt++;
			}
		}
		table[x] = cnt;
	}
	
	fill(visited, visited+n+5, false);
	
	ll ans = 1;
	for(int x=2;x<=n;x++){
		if(!visited[x]){
			ll cur = x;
			int mx = 0;
			while(cur <= n){
				visited[cur] = true;
				cur *= x;
				mx++;
			}
			
			ans += table[mx];
		}
	}
	
	cout << ans << "\n";
    return 0;
}

