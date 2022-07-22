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

int ans[maxN];
int cnt[maxN];
vector<int> adj[maxN];
vector<pair<int, int>> v;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		fill(cnt, cnt+n, 0);
		v.clear();
		for(int x=0;x<m;x++){
			adj[x].clear();
			
			int z;
			cin >> z;
					
			for(int y=0;y<z;y++){
				int tmp;
				cin >> tmp;
				
				adj[x].push_back(tmp-1);
			}
			
			v.push_back({z, x});
		}

		sort(v.begin(), v.end());
		
		fill(ans, ans+m, -1);
		
		for(int i=0;i<m;i++){
			int sz = v[i].first;
			int day = v[i].second;

			for(int x=0;x<adj[day].size();x++){
				int person = adj[day][x];
				if(cnt[person] == (m+1)/2) continue;
				
				cnt[person]++;
				ans[day] = person+1;
				break;
			}
		}
		
		bool possible = true;
		for(int x=0;x<m;x++){
			if(ans[x] == -1){
				possible = false;
				break;
			}
		}
		
		if(possible){
			cout << "YES\n";
			for(int x=0;x<m;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

