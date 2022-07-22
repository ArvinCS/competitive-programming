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
		
		int ans = 0;
		int pos = 0;
		for(int x=1;x<n;x++){
			if(pos >= x) continue;
			if(pos+1 == x){
				if(s[pos] == s[x]){
					ans++;
					pos = x+1;
				} else if(s[pos] == '(' && s[x] == ')'){
					ans++;
					pos = x+1;
				}
			} else {
				if(s[x] == s[pos]){
					ans++;
					pos = x+1;
				}
			}
		}
		
		cout << ans << " " << n-pos << "\n";
	}
	
    return 0;
}

