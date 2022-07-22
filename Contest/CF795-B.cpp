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
		cin >> n;
		
		map<int, vector<int>> mp;
		int s[n];
		for(int x=0;x<n;x++){
			cin >> s[x];
			mp[s[x]].push_back(x);
		}
		
		vector<int> ans(n, -1);
		bool possible = true;
		
		for(auto p : mp){
			if(p.second.size() == 1){
				possible = false;
				break;
			}
			
			for(int x=0;x<p.second.size();x++){
				ans[p.second[x]] = p.second[(x+1)%p.second.size()];
			}
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

