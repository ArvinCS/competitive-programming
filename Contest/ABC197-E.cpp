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
	
	pair<ll, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	sort(data, data+n);
	
	vector<ll> v[n+1];
	int end = 1;
	for(int x=0;x<n;x++){
		v[data[x].second].push_back(data[x].first);
		end = max(end, data[x].second);
	}
	v[0].push_back(0);
	
	ll table[n+1][2]; // 0 left 0 right
	table[0][0] = table[0][1] = 0;
	
	ll ans = -1;
	for(int x=1;x<=n+1;x++){
		if(v[x].size() == 0){
			table[x][0] = table[x-1][0];
			table[x][1] = table[x-1][1];
			
			v[x].push_back(v[x-1].front());
			v[x].push_back(v[x-1].back());
			continue;
		}
		
		ll fromLeft = (x == 1 ? 0 : v[x-1].front()), fromRight = (x == 1 ? 0 : v[x-1].back());
		ll dist = abs(v[x].front() - v[x].back());
		// end at left
		table[x][0] = min(table[x-1][0] + abs(v[x].back() - fromLeft) + dist, table[x-1][1] + abs(v[x].back() - fromRight) + dist);
		// end at right
		table[x][1] = min(table[x-1][0] + abs(v[x].front() - fromLeft) + dist, table[x-1][1] + abs(v[x].front() - fromRight) + dist);
		
		if(x == end){
			ans = min(table[x][0] + abs(v[x].front()), table[x][1] + abs(v[x].back()));
			break;
		}
	}

	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

