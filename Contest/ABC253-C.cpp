#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	multiset<int> st;
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int val;
			cin >> val;
			
			st.insert(val);
		} else if(t == 2){
			int val, cnt;
			cin >> val >> cnt;
			
			while(cnt > 0){
				auto it = st.find(val);
				if(it == st.end()) break;
				st.erase(it);
				cnt--;
			}
		} else if(t == 3){
			cout << *(st.rbegin()) - *(st.begin()) << "\n";
		}
	}
	
    return 0;
}

