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

ll a[maxN], b[maxN], c[maxN], cnt[maxN][2];
vector<pair<ll, ll>> v[2][2];
pair<ll, ll> prefix[maxN][2][2];
	
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		c[x] = b[x]-a[x];
	}
	
	for(int x=2;x<=n;x++){
		for(int y=2*x;y<=n;y+=x){
			c[y-1] -= c[x-1];
		}
	}
	
	fill(cnt[0], cnt[n], 0);
	
	cnt[0][0] = 1;
	for(int x=1;x<=n;x++){
		for(int y=2*x;y<=n;y+=x){
			cnt[y-1][1] += cnt[x-1][0];
			cnt[y-1][0] += cnt[x-1][1];
		}
	}
	
	ll base_ans = 0;
	for(int x=1;x<n;x++){
		ll tmp = (cnt[x][1]-cnt[x][0]);
		if(tmp == 0){ // Case where the element dont get effected by element i = 0 (need[i] == 0)
			base_ans += abs(c[x]);
			continue;
		}
		
		ll need = c[x]/tmp;
		if(c[x]%tmp != 0){
			if(tmp >= 0) need++;
			else need--;
		}
		
		v[c[x] >= 0][tmp >= 0].push_back({need, x});
	}
	
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++) sort(v[x][y].begin(), v[x][y].end());
	}
	
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++){
			prefix[0][x][y] = {0, 0};
			for(int z=0;z<v[x][y].size();z++){
				if(z > 0) prefix[z][x][y] = prefix[z-1][x][y];
				
				prefix[z][x][y].first += c[v[x][y][z].second];
				prefix[z][x][y].second += (cnt[v[x][y][z].second][1] - cnt[v[x][y][z].second][0]);
			}
		}
	}
	
	int q;
	cin >> q;
	
	while(q--){
		cin >> b[0];
		c[0] = b[0] - a[0];
		
		// Case where it element dont get effected by element i = 0 (need[i] == 0)
		ll ans = base_ans;
		
		for(int x=0;x<2;x++){ // Case where all c[i] < 0 or c[i] >= 0
			for(int y=0;y<2;y++){ // Case where all need[i] < 0 or need[i] > 0
				if(!v[x][y].empty()){
					auto it = lower_bound(v[x][y].begin(), v[x][y].end(), make_pair(c[0], -6969ll));
					int idx = it - v[x][y].begin();
					
					ans += abs((idx > 0 ? prefix[idx-1][x][y].first : 0)-(idx > 0 ? prefix[idx-1][x][y].second : 0)*c[0]);
					ans += abs(prefix[v[x][y].size()-1][x][y].first-(idx > 0 ? prefix[idx-1][x][y].first : 0)-(prefix[v[x][y].size()-1][x][y].second-(idx > 0 ? prefix[idx-1][x][y].second : 0))*c[0]);
				}
			}
		}
		
		// Case for i = 0
		ans += abs(c[0]);
		
		cout << ans << "\n";
	}
	
    return 0;
}

