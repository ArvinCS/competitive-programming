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
		
		pair<int, int> c[n];
		for(int x=0;x<n;x++){
			cin >> c[x].first >> c[x].second;
		}
		
		ll ans = 0, prev = -1, time = 0, pos = 0;
		for(int x=0;x<n;x++){
			if(c[x].first >= time){
				time = c[x].first + abs(pos-c[x].second);
				prev = pos;
				pos = c[x].second;
			}
			bool maju = (pos-prev >= 0);
			if(maju){
				if(c[x].second >= pos-(time-c[x].first)){
					if((x+1 == n && c[x].second <= pos) || (x+1 < n && c[x+1].first > time && c[x].second <= pos) || (x+1 < n && c[x+1].first <= time && c[x].second <= pos-(time-c[x+1].first))){
						ans++;
					}	
				}
			} else {
				if(c[x].second <= pos+(time-c[x].first)){
					if((x+1 == n && c[x].second >= pos) || (x+1 < n && c[x+1].first > time && c[x].second >= pos) || (x+1 < n && c[x+1].first <= time && c[x].second >= pos+(time-c[x+1].first))){
						ans++;
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

