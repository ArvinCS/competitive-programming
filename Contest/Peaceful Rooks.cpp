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

int dsu[maxN];

int findParrent(int x){
	if(dsu[x] == x) return x;
	return dsu[x] = findParrent(dsu[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;

		pair<int, int> pos[m];
		for(int x=0;x<m;x++){
			cin >> pos[x].first >> pos[x].second;
			
			dsu[pos[x].first] = pos[x].first;
			dsu[pos[x].second] = pos[x].second;
		}
		
		int ans = 0, cnt = 0;
		for(int x=0;x<m;x++){
			if(pos[x].first == pos[x].second) continue;
			
			ans++;
			
			int a = findParrent(pos[x].first), b = findParrent(pos[x].second);
			if(a == b){
				ans++;
			}
			dsu[a] = b;
		}
		
		cout << ans + (cnt/2) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

