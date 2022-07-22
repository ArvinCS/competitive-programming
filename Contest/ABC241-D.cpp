#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	multiset<ll> st;
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			ll val;
			cin >> val;
			
			st.insert(val);
		} else if(t == 2){
			ll val;
			int pos;
			cin >> val >> pos;
			
			auto it = st.lower_bound(val+1);
			bool exist = true;
			for(int x=0;x<pos;x++){
				if(it == st.begin()){
					exist = false;
					break;
				}
				it--;
			}
			if(!exist || it == st.end()){
				cout << "-1\n";
				continue;
			}
			
			cout << *it << "\n";
		} else if(t == 3){
			ll val;
			int pos;
			cin >> val >> pos;
			
			auto it = st.lower_bound(val);
			bool exist = true;
			for(int x=0;x<pos-1;x++){
				if(it == st.end()){
					exist = false;
					break;
				}
				it++;
			}
			if(!exist || it == st.end()){
				cout << "-1\n";
				continue;
			}
			
			cout << *it << "\n";
		}
	}
	
    return 0;
}

