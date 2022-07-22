#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxK = 105;
const int logK = log2(maxK);

ll n, cnt1 = 0, cnt2 = 0, ans = 0;
vector<int> v;
vector<ll> w;

void solve(int idx, int bound, bool id, ll val){
	if(idx == bound){
		if(id){
			auto it = lower_bound(w.begin(), w.end(), n/val+1);
			ans += (it - w.begin());
			cnt1++;
		} else {
			cnt2++;
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
	
	for(int x=2;x<=k;x++){
		bool valid = true;
		for(int y=2;y*y<=x;y++){
			if(x%y == 0){
				valid = false;
			}
		}
		
		if(valid){
			v.push_back(x);	
		}
	}
	
	int sz = v.size();
	solve(0, (v.size()+3)/4, 0, 1);
//	solve((v.size()+3)/4, sz, 0, 1);
	
	sort(w.begin(), w.end());
	
//	solve(0, (v.size()+3)/4, 1, 1);
	solve((v.size()+3)/4, sz, 1, 1);
//	cout << cnt1 << " " << cnt2 << "\n";
	cout << ans << "\n";
    return 0;
}

