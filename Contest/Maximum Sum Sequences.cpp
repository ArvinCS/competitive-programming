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
	
	us t;
	cin >> t;
	
	while(t--){
		ui n;
		cin >> n;
		
		int data[n];
//		sum[0] = 0;
		for(ui x=0;x<n;x++){
			cin >> data[x];
		}
		
		ll tmp, best, ways = 0;
		tmp = best = data[0];
		for(ui x=1;x<n;x++){
			tmp = max(data[x] * 1ll, data[x] + tmp);
			if(tmp > best) best = tmp;
		}
		
		tmp = 0;
		unordered_map<ll, ll> map;
		map[0]++;
		for(ui x=0;x<n;x++){
			tmp += data[x];
			ll left = tmp - best;
			ways += map[left];
			map[tmp]++;
		}
		cout << best << " " << ways << "\n";
	}
	
    return 0;
}
