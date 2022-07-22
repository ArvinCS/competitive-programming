#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		ll m;
		cin >> n >> m;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int k;
		cin >> k;
		
		ll b[k];
		for(int x=0;x<k;x++){
			cin >> b[x];
		}
		
		bool possible = true;
		vector<pair<ll, ll>> v;
		
		ll lst = -1, cnt = 0;
		for(int x=0;x<n;x++){
			ll cur = a[x];
			ll cnt2 = 1;
			while(cur % m == 0){
				cur /= m;
				cnt2 *= m;
			}
			
			if(lst != cur){
				if(lst > 0 && cnt > 0){
					v.push_back({lst, cnt});
				}
				cnt = 0;
			}
			
			lst = cur;
			cnt += cnt2;
		}
		if(lst > 0 && cnt > 0){
			v.push_back({lst, cnt});
		}
		cnt = 0;
		
//		for(auto p : v){
//			cout << p.first << " -> " << p.second << "\n";
//		}
		int pos = 0, pos2 = 0;
		for(int x=0;x<k;x++){
			while(b[x] > 0){
				if(pos == v.size()){
					possible = false;
					break;
				}
				
				if(v[pos].second == 0){
					pos++;
					continue;
				}
				
				if(b[x] % v[pos].first != 0){
					possible = false;
					break;
				}
				
				ll need = b[x]/v[pos].first;
				if(v[pos].second < need){
					possible = false;
					break;
				}
				
				ll cur = need;
				while(cur > 1 && cur % m == 0){
					cur /= m;
				}
				
				if(cur != 1){
					possible = false;
					break;
				}
				
				b[x] -= need*1ll*v[pos].first;
				v[pos].second -= need;
			}
			if(!possible){
				break;
			}
		}
		while(pos < v.size() && v[pos].second == 0) pos++;
		if(pos < v.size()){
			possible = false;
		}
		
		cout << (possible ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

