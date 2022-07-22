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

bool isSame(double a, double b){
	if(abs(a-b) < 1e-9){
		return true;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll r;
	cin >> n >> r;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	bool xZero = true, yZero = true;
	for(int x=0;x<n;x++){
		if(p[x].first > 0) xZero = false;
		if(p[x].second > 0) yZero = false;
	}
	
	if(xZero){ // subtask 5
		ll x = 0;
		double y1 = r;
		double y2 = -y1;
		
		int ans = 0;
		int cnt = 0;
		for(int z=0;z<n;z++){
			ll a = (x-p[z].first);
			ll dist = r*r - a*a;
			double b = (y1-p[z].second);
			
			if(b*b < dist || isSame(b*b, dist)){
				cnt++;
			}
		}

		ans = max(ans, cnt);
		
		cnt = 0;
		for(int z=0;z<n;z++){
			ll a = (x-p[z].first);
			ll dist = r*r - a*a;
			double b = (y2-p[z].second);
			
			if(b*b < dist || isSame(b*b, dist)){
				cnt++;
			}
		}
		
		ans = max(ans, cnt);
		
		cout << ans << "\n";
		return 0;
	}
	
	ll mx = 100000/2;
	int ans = 0;
	for(ll x=-min(mx, r);x<=min(mx, r);x++){
		double y1 = sqrt(r*r - x*x);
		double y2 = -y1;
		
		int cnt = 0;
		for(int z=0;z<n;z++){
			ll a = (x-p[z].first);
			ll dist = r*r - a*a;
			double b = (y1-p[z].second);
			
			if(b*b < dist || isSame(b*b, dist)){
				cnt++;
			}
		}
		
//		if(ans < cnt){
//			cout << x << " " << y1 << "\n";
//		}
		ans = max(ans, cnt);
		
		cnt = 0;
		for(int z=0;z<n;z++){
			ll a = (x-p[z].first);
			ll dist = r*r - a*a;
			double b = (y2-p[z].second);
			
			if(b*b < dist || isSame(b*b, dist)){
				cnt++;
			}
		}
		
//		if(ans < cnt){
//			cout << x << " " << y1 << "\n";
//		}
		ans = max(ans, cnt);
	}
	
	cout << ans << "\n";
    return 0;
}

