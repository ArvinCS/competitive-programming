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
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			ll a = abs(p[x].first-p[y].first);
			ll b = abs(p[x].second-p[y].second);
			
			if(a*a+b*b > ans){
				ans = a*a+b*b;;
			}
		}
	}
	
	cout << fixed << setprecision(7) << sqrt(ans) << "\n";
    return 0;
}

