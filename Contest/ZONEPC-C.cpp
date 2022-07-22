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

vector<pair<ll, ll>> v[5];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	vector<pair<ll, ll>> v[5];
	ll data[n][5];
	for(int x=0;x<n;x++){
		for(int y=0;y<5;y++){
			cin >> data[x][y];
			v[y].push_back({data[x][y], x});
		}
	}
	
	for(int x=0;x<5;x++){
		sort(v[x].begin(), v[x].end());
	}
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			vector<pair<ll, ll>> tmp;
			for(int z=0;z<5;z++){
				tmp.push_back({max(data[x][z], data[y][z]), z});
			}
			
			sort(tmp.begin(), tmp.end());
						
			for(int i=1;i<=3;i++){
				int idx = v[tmp[0].second][n-i].second;
				if(idx == x || idx == y) continue;
				
				tmp[0].first = max(tmp[0].first, v[tmp[0].second][n-i].first);
				break;
			}
			
			ll mn = inf_ll;
			for(int z=0;z<5;z++) mn = min(mn, tmp[z].first);
			ans = max(ans, mn);
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

