#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+n);
	
	if(k == 1){
		cout << "Infinity\n";
		return 0;
	}
	
	// m = (y2-y1)/(x2-x1)
	int ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			ll mY = p[y].second-p[x].second;
			ll mX = p[y].first-p[x].first;
			
			bool valid = true;
			int cnt = 2;
			for(int z=x+1;z<y;z++){
				ll cY = p[z].second-p[x].second;
				ll cX = p[z].first-p[x].first;
				
				if(mY*cX == cY*mX){
					cnt++;
				}
			}
			for(int z=0;z<n;z++){
				if(x <= z && z <= y) continue;
				
				ll cY = p[z].second-p[x].second;
				ll cX = p[z].first-p[x].first;
				
				if(mY*cX == cY*mX){
					valid = false;
					break;
				}
			}
			
			ans += (cnt >= k && valid);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

