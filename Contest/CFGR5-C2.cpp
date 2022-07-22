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

vector<vector<ll>> data;
int solve(vector<int> v, int dimension){
	if(dimension == 3){
		return v[0];		
	}
	
	map<int, vector<int>> mp;
	for(int idx : v){
		mp[data[idx][dimension]].push_back(idx);
	}
	
	vector<int> ans;
	for(auto m : mp){
		int cur = solve(m.second, dimension+1);
		if(cur != -1){
			ans.push_back(cur);
		}
	}
	for(int x=0;x+1<ans.size();x+=2){
		cout << ans[x]+1 << " " << ans[x+1]+1 << "\n";
	}
	return (ans.size() % 2 == 1 ? ans.back() : -1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		ll x, y, z;
		cin >> x >> y >> z;
		
		data.push_back({x, y, z});
	}
	
	vector<int> idxs;
	for(int x=0;x<n;x++) idxs.push_back(x);
	solve(idxs, 0);
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

