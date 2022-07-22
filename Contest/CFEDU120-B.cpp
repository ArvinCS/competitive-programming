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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		string s;
		cin >> s;
		
		vector<pair<int, int>> v[2];
		for(int x=0;x<n;x++){
			v[(s[x] - '0')].push_back({p[x], x});
		}
		
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		
		int ans[n];
		int cnt = 1;
		for(int x=0;x<v[0].size();x++){
			ans[v[0][x].second] = cnt++;
		}
		for(int x=0;x<v[1].size();x++){
			ans[v[1][x].second] = cnt++;
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}
