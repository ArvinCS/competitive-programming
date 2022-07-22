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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<ll, ll> data[n];
		unordered_set<ll> setX, setY;
		
		vector<ll> vx, vy;
		for(int x=0;x<n;x++){
			cin >> data[x].first >> data[x].second;
			
			vx.push_back(data[x].first);
			vy.push_back(data[x].second);
			
			setX.insert(data[x].first);
			setY.insert(data[x].second);
		}
		
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		
		cout << (vx[vx.size()/2] - vx[(vx.size()-1)/2] + 1) * (vy[vy.size()/2] - vy[(vy.size()-1)/2] + 1) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

