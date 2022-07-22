#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ask(int w){
	cout << "? " << w << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int mn = 2000;
	int left = 1, right = 2000;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		if(ask(mid) != 0){
			mn = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	vector<pair<int, int>> v;
	int pos = mn;
	while(pos <= mn*n){
		int mx = pos;
		int cur = ask(pos);
		int left = pos, right = pos+(n/2)*mn;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(ask(mid) == cur){
				mx = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		v.push_back({mx, cur});
		if(cur == 1) break;
		pos = mx+1;
	}
	
	ll ans = 1e18;
	pos = mn;
	for(int x=0;x<v.size();x++){
		while(pos <= v[x].first){
			ans = min(ans, pos*1ll*v[x].second);
			pos++;
		}
	}
	
	cout << "! " << ans << endl;
    return 0;
}

