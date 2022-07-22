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

double calc(ll x, ll y){
	return sqrt(x*x*1.0 + y*y);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll start, end, n, d;
	cin >> start >> end >> n >> d;
	
	pair<ll, ll> tiang[n];
	for(int x=0;x<n;x++){
		cin >> tiang[x].first >> tiang[x].second;
	}
	
	sort(tiang, tiang+n);
	
	bool valid[n];
	ll mxX = 0, mxY = 0;
	for(int x=n-1;x>=0;x--){
		valid[x] = false;
		if(mxY*(end-tiang[x].first-d/2) <= tiang[x].second*mxX){
			mxX = (end-tiang[x].first-d/2);
			mxY = tiang[x].second;
			valid[x] = true;
		}
	}
	
	int idx = -1;
	double ans = 0;
	bool right = false;
	ll curX = start, curY = 0;
	while(idx < n){
		ll bestX = 0, bestY = 0, bestIdx = -1;
		for(int x=idx+1;x<n;x++){
			if(bestY*(tiang[x].first-d/2-curX) <= (tiang[x].second-curY)*bestX){
				bestX = (tiang[x].first-d/2-curX);
				bestY = (tiang[x].second-curY);
				bestIdx = x;
			}
		}
		
		if(curY >= tiang[bestIdx].second){
			if(!right){
				curX += d;
				ans += d;
			}
			
			ans += calc(tiang[bestIdx].first+d/2-curX, tiang[bestIdx].second-curY);
			curX = tiang[bestIdx].first+d/2; curY = tiang[bestIdx].second;
			right = true;
		} else {
			ans += calc(tiang[bestIdx].first-d/2-curX, tiang[bestIdx].second-curY);
			curX = tiang[bestIdx].first-d/2; curY = tiang[bestIdx].second;
			right = false;
		}
		
		idx = bestIdx;
		if(valid[idx]){
			break;
		}
	}
	if(!right){
		ans += d;
		curX += d;
	}
	
	ans += calc(end-curX, curY);
	
	cout << fixed << setprecision(3) << ans << "\n";
    return 0;
}

