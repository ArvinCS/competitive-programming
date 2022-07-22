#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	unordered_map<ll, ll> mp;
	
	ll sum = 0, ans = 0;
	for(int x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		
		sum += tmp;
		
		if(sum == 0 || mp[sum] > 0){
//			cout << x << " " << sum << " | " << ans << "\n";
			mp.clear();
			ans++;
			sum = tmp;
		}
		mp[sum]++;
	}
	
	cout << ans << "\n";
    return 0;
}

