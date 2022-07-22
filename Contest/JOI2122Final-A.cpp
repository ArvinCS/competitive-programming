#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<ll, int>> v;
	ll prv = 0;
	for(int x=0;x<n;x++){
		int cur;
		ll cnt = 1;
		cin >> cur;
		
		while(cur % 2 == 0){
			cur /= 2;
			cnt *= 2;
		}
		
		v.push_back({prv+1, cur});
		prv += cnt;
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		ll m;
		cin >> m;
		
		auto it = lower_bound(v.begin(), v.end(), make_pair(m+1, -1));
		it--;
		
		cout << (*it).second << "\n";
	}
    return 0;
}

