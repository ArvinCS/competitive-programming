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
		
		string s;
		cin >> s;
		
		vector<array<int, 2>> v;
		int last = 0;
		
		for(int x=0;x<n;x++){
			if(s[last] != s[x]){
				v.push_back({x-last, (s[last] - '0')});
				last = x;
			}	
		}
		v.push_back({n-last, (s[last] - '0')});
		
		bool one = false;
		int pos = 0;
		int ans = 0;
		for(int x=0;x<v.size();x++){
			if(v[x][0] == 0) continue;
			
			while(pos < x) pos++;
			while(!one && pos < v.size() && v[pos][0] <= 1){
				pos++;
			}
			if(pos == v.size()){
				one = true;
				pos = x;
			}
			while(pos < v.size() && v[pos][0] <= 0) pos++;
			
			if(pos < v.size()){
				v[pos][0]--;
				ans++;
			}
			if(v[x][0] > 0) v[x][0] = 0;
			else if(x+1 < v.size()) v[x+1][0] = 0;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

