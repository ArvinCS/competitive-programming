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
	return sqrt(x*x*1.0 + y*y*1.0);
}

bool same(double a, double b){
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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<ll, ll> bebek[n];
	for(int x=0;x<n;x++){
		cin >> bebek[x].first >> bebek[x].second;
	}
	
	sort(bebek, bebek+n);
	
	double ans = inf_ll;
	ll cnt = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			for(int z=y+1;z<n;z++){
				double area = abs(bebek[x].first*(bebek[y].second-bebek[z].second) + bebek[y].first*(bebek[z].second-bebek[x].second) + bebek[z].first*(bebek[x].second-bebek[y].second))*1.0/2;
				
				if(!same(area, 0.00) && area > 0.00){
					if(same(ans, area)){
						cnt++;
					} else if(ans > area){
						ans = area;
						cnt = 1;
					}
				}
			}
		}
	}
	
	if(cnt != 1 || ans == inf_ll){
		ans = -1;
	}
	cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}

