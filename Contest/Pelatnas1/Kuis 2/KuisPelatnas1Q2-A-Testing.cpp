#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> st;
	st.push_back({});
	
	for(int i=1;i<=n;i++){
		char t;
		cin >> t;
		
		if(t == 'a'){
			int v;
			cin >> v;
			
			st.push_back(st[v]);
			st.back().push_back(i);
		} else if(t == 'b'){
			int v;
			cin >> v;
			
			st.push_back(st[v]);
			cout << st.back().back() << "\n";
			st.pop_back();
		} else if(t == 'c'){
			int v, w;
			cin >> v >> w;
			
			st.push_back(st[v]);
			map<int, int> mp;
			for(int x=0;x<st[w].size();x++){
				mp[st[w][x]]++;
			}
			
			int ans = 0;
			for(int x=0;x<st.back().size();x++){
				mp[st.back()[x]]++;
			}
			
			for(auto p : mp){
				if(p.second == 1) ans++;
			}
			cout << ans << "\n";
		} else {
			assert(false);
		}
		
		cout << i << ":\n";
		for(int x=0;x<st.back().size();x++){
			cout << st.back()[x] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
