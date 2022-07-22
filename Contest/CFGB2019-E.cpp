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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	vector<int> ans;
	for(int x=0;x<n;x++){
		map<ll, vector<int>> mp;
		for(int y=0;y<n;y++){
			if(x == y) continue;
			
			ll dist = pow(p[x].first-p[y].first, 2) + pow(p[x].second-p[y].second, 2);
			
			mp[dist].push_back(y);
		}
	}
	
	cout << ans.size() << "\n";
	for(auto idx : ans){
		cout << p[idx].first << " " << p[idx].second << "\n";
	}
    return 0;
}

