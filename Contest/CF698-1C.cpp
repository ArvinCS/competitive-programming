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

#define PI 3.141592653589793238463

bool isSame(long double a, long double b){
	if(abs(a-b) < 1e-9){
		return true;
	} else {
		return false;
	}
}

ll check(pair<ll, ll> p, pair<ll, ll> q, pair<ll, ll> r){
	double angle = atan2(r.second - q.second, r.first - q.first) - atan2(p.second - q.second, p.first - q.first);
	angle = angle * 180 / PI;
	
	if(!isSame(angle, 0) && angle < 0) angle += 360.0;
	if(!isSame(angle, 180) && angle > 180) angle = 360.0 - angle;
	
//	cout << p.first << " " << p.second << " - " << q.first << " " << q.second << " - " << r.first << " " << r.second << "\n";
//	cout << fixed << setprecision(5) << angle << "  --- " << isSame(angle, 90) << "\n";
	if(!isSame(angle, 90) && angle < 90){
		return true;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	int ans[n];
	for(int x=0;x<n;x++) ans[x] = x+1;
	
	for(int x=1;x+1<n;x++){ // as center point
//		cout << ans[x-1] << " " << ans[x] << " " << ans[x+1] << " -> ";
		if(check(p[x-1], p[x], p[x+1])){
			continue;
		} else {
			swap(p[x], p[x+1]);
			swap(ans[x], ans[x+1]);
			
			bool ok = true;
			for(int y=x-1;y>0;y--){
				if(!check(p[y-1], p[y], p[y+1])){
					ok = false;
					break;
				}
			}
			
			if(ok){
				continue;
			}
			
			ok = true;
			for(int y=x-1;y>0;y--){
				if(!check(p[y-1], p[y], p[y+1])){
					swap(p[y], p[y+1]);
					swap(ans[y], ans[y+1]);
				}
			}
			for(int y=x;y>0;y--){
				if(!check(p[y-1], p[y], p[y+1])){
					ok = false;
					break;
				}
			}
			
			if(!ok){
				cout << "-1\n";
				return 0;
			}
		}
//		for(int x=0;x<n;x++){
//			if(x > 0) cout << " ";
//			cout << ans[x];
//		}
//		cout << "\n";
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

