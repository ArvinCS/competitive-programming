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
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int ans = 1e9;
		int cnt = 0;
		for(int x=0;x<k-1;x++){
			if(s[x] == 'B') cnt++;
		}
		for(int x=k-1;x<n;x++){
			if(s[x] == 'B') cnt++;
			ans = min(ans, k-cnt);
			if(s[x-k+1] == 'B') cnt--;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

