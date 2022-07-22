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
	
	vector<pair<double, int>> v;
	for(int x=0;x<n;x++){
		int t;
		double l, r;
		cin >> t >> l >> r;
		
		if(t == 2){
			r -= 0.1;
		} else if(t == 3){
			l += 0.1;
		} else if(t == 4){
			l += 0.1;
			r -= 0.1;
		}
		
		if(l <= r){
			v.push_back({l, 1});
			v.push_back({r+0.01, -1});
		}
	}
	
	sort(v.begin(), v.end());
	
	ll ans = 0, cnt = 0;
	for(int x=0;x<v.size();x++){		
		pair<double, int> p = v[x];
		if(p.second == 1){
			ans += cnt;
			cnt++;
		} else {
			cnt--;	
		}
//		cout << p.first << " " << p.second << " -> " << ans << "\n";
	}
	cout << ans << "\n";
    return 0;
}

