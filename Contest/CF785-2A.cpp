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
		string s;
		cin >> s;
		
		if(s.length() <= 1){
			cout << "Bob " << (s[0] - 'a' + 1) << "\n";
			continue;
		}
		
		if(s.length()&1){
			int l = -(s.back() - 'a' + 1), r = -(s[0] - 'a' + 1);
			for(int x=0;x<s.length();x++){
				if(x+1 < s.length()) l += (s[x] - 'a' + 1);
				if(x > 0) r += (s[x] - 'a' + 1);
			}
			
			cout << "Alice " << max(l, r) << "\n";
		} else {
			int ans = 0;
			for(int x=0;x<s.length();x++){
				ans += (s[x] - 'a' + 1);
			}
			
			cout << "Alice " << ans << "\n";
		}
	}
	
    return 0;
}

