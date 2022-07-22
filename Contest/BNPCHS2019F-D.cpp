#include <bits/stdc++.h>

using namespace std;

#define ll long long

const double eps = 1e-7;

bool isSame(double a, double b){
	if(abs(a-b) < eps){
		return true;
	} else {
		return false;
	}
}

bool customSort(pair<double, ll> &a, pair<double, ll> &b){
	if(isSame(a.first, b.first)){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	
	pair<ll, ll> p[n], d[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		cin >> d[x].first >> d[x].second;
	}
	
	vector<pair<double, ll>> v;
	ll cnt = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if((d[y].first-d[x].first) == 0 && (d[y].second-d[x].second) == 0){
				ll distX = (p[x].first-p[y].first);
				ll distY = (p[x].second-p[y].second);
				ll dist = distX*distX + distY*distY;
				
				if(dist <= m*m){
					cnt++;
				}
				continue;
			}
			
			ll ax = p[x].first-p[y].first;
			ll ay = p[x].second-p[y].second;
			ll bx = d[x].first-d[y].first;
			ll by = d[x].second-d[y].second;
			
			ll a = (bx*bx + by*by);
			ll b = 2*(ax*bx + ay*by);
			ll c = ax*ax + ay*ay - m*m;
			
			ll d = b*b - 4*a*c;
			
			if(d < 0 && !isSame(d, 0.0)){
				continue;
			}
			if(a == 0){
				continue;
			}
			
			double mn2 = (-b*1.0 + sqrt(d))*1.0/(2*a);
			double mn1 = (-b*1.0 - sqrt(d))*1.0/(2*a);
			
			if(mn1 > mn2) swap(mn1, mn2);
			
			if(mn1 < 0) mn1 = 0;
			
			v.push_back({mn1, 1});
			v.push_back({mn2, -1});
		}
	}
	
	sort(v.begin(), v.end(), customSort);
	
	ll ans = 0, cur = 0;
	for(int x=0;x<v.size();x++){
		cur += v[x].second;
		ans = max(ans, cur);
	}
	
	cout << ans+cnt << "\n";
    return 0;
}

