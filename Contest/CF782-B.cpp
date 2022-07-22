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
		ll k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int ans[n];
		fill(ans, ans+n, 0);
		
		int cnt = 0;
		for(int x=0;x<n&&cnt<k;x++){
			int val = (s[x] - '0');
			if(!(val^(k&1))){
				ans[x]++;
				cnt++;
			}
		}
		while(k-cnt > 0){
			ans[n-1]++;
			cnt++;
		}
		
		for(int x=0;x<n;x++){
			int val = (s[x] - '0')^((k+ans[x])&1);
			cout << val;
		}
		cout << "\n";
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

