#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll cost[9];
	for(int x=0;x<9;x++){
		cin >> cost[x];
	}
	
	pair<ll, ll> mn = {1e18, 1e18};
	for(int x=0;x<9;x++){
		mn = min(mn, {cost[x], -x});
	}
	
	mn.second *= -1;
	
	string ans;
	while(n >= mn.first){
		ans.push_back(('1' + mn.second));
		n -= mn.first;
	}
	
//	cout << ans << " " << n << " " << cost[7] << "\n";
	
	for(int x=0;x<ans.length();x++){
		for(int y=8;y>mn.second;y--){
//			cout << y << " = " << cost[y] << " " << mn.first << "\n";
			if(cost[y]-mn.first <= n){
				n -= cost[y]-mn.first;
				ans[x] = ('1' + y);
				break;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

