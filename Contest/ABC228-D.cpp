#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n = pow(2, 20);
	set<int> st;
	map<int, ll> mp;
	for(int x=0;x<n;x++){
		st.insert(x);	
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int t;
		ll val;
		cin >> t >> val;
		
		if(t == 1){
			auto it = st.lower_bound(val%n);
			if(it == st.end()){
				it = st.lower_bound(0);
			}
			
			mp[*it] = val;
			st.erase(it);
		} else {
			if(mp.find(val%n) != mp.end()){
				cout << mp[val%n] << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
	
    return 0;
}

