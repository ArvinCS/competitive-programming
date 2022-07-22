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
	
	int n, k;
	cin >> n >> k;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	int ans = 0, cnt = 0;
	map<int, int> mp;
	for(int x=0;x<n;x++){
		if(x >= k){
			mp[c[x-k]]--;
			if(mp[c[x-k]] == 0) cnt--;
		}
		if(mp[c[x]] == 0) cnt++;
		mp[c[x]]++;
		
		ans = max(ans, cnt);
	}
	
	cout << ans << "\n";
    return 0;
}

