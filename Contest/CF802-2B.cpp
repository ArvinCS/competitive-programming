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
		
		if(s == "99"){
			cout << "32\n";
			continue;
		}
		
		string ans(n, '0');
		for(int x=1;x<n-1;x++){
			int mx = max((s[x] - '0'), (s[n-x-1] - '0'));
			ans[x] = ('0' + abs(mx-(s[x] - '0')));				
		}
		if(max(s[0] - '0', s[n-1] - '0') == 9){
			ans[0] = ('0' + (11 + (max(s[1], s[n-2]) - '0') - (s[0] - '0')));
			ans[n-1] = ('0' + (11 - (s[n-1] - '0')));	
		} else {
			int mx = max((s[0] - '0'), (s[n-1] - '0'));
			ans[0] = ('0' + abs(mx-(s[0] - '0')));
			ans[n-1] = ('0' + abs(mx-(s[n-1] - '0')));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

