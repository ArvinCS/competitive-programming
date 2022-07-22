#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}	
	
	sort(p, p+n);
	
	ll ans = n*1ll*(n-1)*(n-2)/6;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			for(int z=y+1;z<n;z++){
				if((p[y].second - p[x].second) * (p[z].first-p[y].first) == (p[z].second-p[y].second) * (p[y].first-p[x].first)){
					ans--;
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

