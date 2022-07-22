#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		string s;
		cin >> s;
		
		int n = s.length();
		bool dif[n];
		set<char> st;
		fill(dif, dif+n, false);
		
		for(int x=n-1;x>=0;x--){
			st.insert(s[x]);
			
			if(st.size() > 1){
				dif[x] = true;
			} else {
				dif[x] = false;
			}
		}
		
		string ans;
		for(int x=0;x<n;x++){
			int pos = x+1;
			while(pos < n && s[pos] == s[x]) pos++;
			if(dif[x] && s[x] <= s[pos]){
				ans.push_back(s[x]);
			}
			ans.push_back(s[x]);
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

