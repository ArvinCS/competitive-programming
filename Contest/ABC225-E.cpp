#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	vector<pair<ld, ld>> v;
	ld bot[n], top[n];
	for(int x=0;x<n;x++){
		bot[x] = atan2(p[x].second-1, p[x].first);
		top[x] = atan2(p[x].second, p[x].first-1);
		
		v.push_back({top[x], bot[x]});
	}
	
	sort(v.begin(), v.end());
	
	int cnt = 0;
	ld prv = -1;
	for(int x=0;x<v.size();x++){
		if(v[x].second >= prv){
			prv = v[x].first;
			cnt++;
		}
	}
	
	cout << cnt << "\n";
    return 0;
}

