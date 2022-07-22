#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxK = 105;
const int logK = log2(maxK);

ll n, ans = 0;
vector<int> v;
vector<ll> w;

void solve(int idx, int bound, bool id, ll val){
	if(idx == bound){
		if(id){
			auto it = lower_bound(w.begin(), w.end(), n/val+1);
			ans += (it - w.begin());
		} else {
			w.push_back(val);
		}
		
		return;
	}
	
	ll pw = 1;
	for(int y=0;pw<=n/val;y++){
		solve(idx+1, bound, id, pw*val);
		pw *= v[idx];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int k;
	cin >> n >> k;
	
	int ans = 0;
	for(int x=1;x<=n;x++){
		int cur = x;
		
		for(int y=2;y<=k;y++){
			while(cur % y == 0){
				cur /= y;
			}
		}
		
		if(cur == 1){
			ans++;
		}
	}
	cout << ans << "\n";
    return 0;
}

