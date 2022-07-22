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
		int a, b, k;
		cin >> a >> b >> k;
		
		vector<int> boy[a+1], girl[b+1];
		pair<int, int> couple[k];
		for(int x=0;x<k;x++){
			cin >> couple[x].first;
		}
		for(int x=0;x<k;x++){
			cin >> couple[x].second;
			boy[couple[x].first].push_back(couple[x].second);
			girl[couple[x].second].push_back(couple[x].first);
		}
		
		sort(couple, couple+k);
		
		ll ans = 0;
		for(int x=0;x<k;x++){
			ans += k-(boy[couple[x].first].size()+girl[couple[x].second].size())+1;
		}
		cout << ans/2 << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

