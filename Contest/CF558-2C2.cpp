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

const int maxN = 1e3 + 5;
const int limit = 1e6;

bool done[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	fill(done[0], done[n+1], false);
	
	map<double, int> mp;
	for(int x=0;x<n;x++){
		map<double, vector<int>> tmp;
		for(int y=x+1;y<n;y++){
			if(!done[x][y]){
				int div = (data[y].first-data[x].first);
				double p = limit;
				if(div != 0) p = (data[y].second-data[x].second)*1.0/div;
					
				tmp[p].push_back(y);
				done[x][y] = true;
			}
		}
		for(auto m : tmp){
			for(int y=0;y<m.second.size();y++){
				for(int z=y+1;z<m.second.size();z++){
					done[m.second[y]][m.second[z]] = true;
				}
			}
			mp[m.first]++;
		}
	}
	
	ll ans = 0;
	ll sum = 0;
	for(auto m : mp) sum += m.second;
	
	for(auto it=mp.begin();it!=mp.end();it++){
		if(next(it) == mp.end()) break;
		sum -= (*it).second;
		ans += (*it).second*1ll*sum;
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

